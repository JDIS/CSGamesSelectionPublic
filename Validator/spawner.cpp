#include <unistd.h>
#include <signal.h>
#include <future>
#include <thread>
#include <chrono>

#include "json.hpp"

using json = nlohmann::json;

json spawn(std::string program, std::string arg, json ins, int timeout_millis)
{
  json res = {{"isSuccess", false}, {"isTimeout", false}, {"streams", {}}};
  int pipe_to_child[2];
  int pipe_out_from_child[2];
  int pipe_err_from_child[2];
  
  if(pipe(pipe_to_child) < 0)
    return res;
  if(pipe(pipe_out_from_child) < 0)
    return res;
  if(pipe(pipe_err_from_child) < 0)
    return res;

  pid_t pid = fork();
  
  if(pid == 0)
  {
    if(dup2(pipe_to_child[0], STDIN_FILENO) < 0)
      return res;
    if(dup2(pipe_out_from_child[1], STDOUT_FILENO) < 0)
      return res;
    if(dup2(pipe_err_from_child[1], STDERR_FILENO) < 0)
      return res;

    close(pipe_to_child[0]);
    close(pipe_to_child[1]);
    close(pipe_out_from_child[0]);
    close(pipe_out_from_child[1]);
    close(pipe_err_from_child[0]);
    close(pipe_err_from_child[1]);

    execlp(program.c_str(), program.c_str(), arg.c_str(), NULL);
    return res;
  }
  else if(pid > 0)
  {
    close(pipe_to_child[0]);
    close(pipe_out_from_child[1]);
    close(pipe_err_from_child[1]);

    std::promise<json> f;
    std::future<json> f_completes = f.get_future();
    std::thread([&](std::promise<json> f) { 
      char buff[512];
      std::stringstream out;
      std::stringstream err;
      
      for(auto in = ins.begin(); in != ins.end(); ++in) {
        auto line = in->get<std::string>();
        write(pipe_to_child[1], line.c_str(), line.size());
        write(pipe_to_child[1], "\n", 1);
      }

      size_t count;
      json lines;
      do
      {
        count = read(pipe_out_from_child[0], buff, 512);
        out << std::string(buff, count);
      } while(count == 512);
      for(std::string line; std::getline(out, line); )
      {
        lines.push_back(line);
      }

      do
      {
        count = read(pipe_err_from_child[0], buff, 512);
        err << std::string(buff, count);
      } while(count == 512);
      f.set_value_at_thread_exit({{"stdout", lines}, {"stderr", err.str()}}); 
    },
    std::move(f)
    ).detach();

    auto end = std::chrono::system_clock::now() + std::chrono::milliseconds(timeout_millis);
    if(f_completes.wait_until(end) == std::future_status::ready)
    {
      res["streams"] = f_completes.get();
      res["isSuccess"] = true;
    }
    else
    {
      kill(pid, SIGKILL);
      res["isTimeout"] = true;
    }

    close(pipe_to_child[1]);
    close(pipe_out_from_child[0]);
    close(pipe_err_from_child[0]);
  }
  return res;
}
