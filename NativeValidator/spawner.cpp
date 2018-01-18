#ifndef _MSC_VER
#include <unistd.h>
#include <signal.h>
#else
#include <windows.h>
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>
#endif

#include <future>
#include <thread>
#include <chrono>

#include "json.hpp"

using json = nlohmann::json;

json spawn(std::string program, std::string arg, json ins, int timeout_millis)
{
  json res = {{"isSuccess", false}, {"isTimeout", false}, {"streams", {}}};
#ifndef _MSC_VER
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
#else
  SECURITY_ATTRIBUTES saAttr;
  saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
  saAttr.bInheritHandle = TRUE;
  saAttr.lpSecurityDescriptor = NULL;

  HANDLE pipe_to_child[2] = { NULL };
  HANDLE pipe_out_from_child[2] = { NULL };
  HANDLE pipe_err_from_child[2] = { NULL };

  if(!CreatePipe(&pipe_to_child[0], &pipe_to_child[1], &saAttr, 0))
	  return res;
  if(!CreatePipe(&pipe_out_from_child[0], &pipe_out_from_child[1], &saAttr, 0))
	  return res;
  if(!CreatePipe(&pipe_err_from_child[0], &pipe_err_from_child[1], &saAttr, 0))
	  return res;
  if(!SetHandleInformation(pipe_to_child[1], HANDLE_FLAG_INHERIT, 0))
	  return res;

  std::string cmd = program + " " + arg;
  std::unique_ptr<TCHAR> szCmdline(new TCHAR[cmd.size() + 1]);
  TCHAR* it = szCmdline.get();
  for (auto ch : cmd) {
	  *it = ch;
	  it++;
  }
  szCmdline.get()[cmd.size()] = 0;
  PROCESS_INFORMATION piProcInfo;
  STARTUPINFO siStartInfo;
  BOOL bSuccess = FALSE;
  ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));
  ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
  siStartInfo.cb = sizeof(STARTUPINFO);
  siStartInfo.hStdError = pipe_err_from_child[1];
  siStartInfo.hStdOutput = pipe_out_from_child[1];
  siStartInfo.hStdInput = pipe_to_child[0];
  siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

  bSuccess = CreateProcess(NULL, szCmdline.get(), NULL, NULL, TRUE, 0, NULL, NULL, &siStartInfo, &piProcInfo);
  if(!bSuccess)
	  return res;

  CloseHandle(pipe_to_child[0]);
  CloseHandle(pipe_out_from_child[1]);
  CloseHandle(pipe_err_from_child[1]);

  std::promise<int> f;
  std::future<int> f_completes = f.get_future();
  std::thread([&](std::promise<int> f) {
	  DWORD dwRead, dwWritten;
	  char buff[512];
	  std::stringstream out;
	  std::stringstream err;

	  for (auto in = ins.begin(); in != ins.end(); ++in) {
		  auto line = in->get<std::string>();
		  WriteFile(pipe_to_child[1], line.c_str(), line.size(), &dwWritten, NULL);
		  WriteFile(pipe_to_child[1], "\r\n", 2, &dwWritten, NULL);
	  }

	  json lines;
	  do
	  {
		  bool success = ReadFile(pipe_out_from_child[0], buff, 512, &dwRead, NULL);
		  if (!bSuccess || dwRead == 0) break;
		  
		  out << std::string(buff, dwRead);
	  } while (dwRead == 512);
	  for (std::string line; std::getline(out, line); )
	  {
		  line.pop_back(); // remove \r
		  lines.push_back(line);
	  }

	  do
	  {
		  bool success = ReadFile(pipe_err_from_child[0], buff, 512, &dwRead, NULL);
		  if (!bSuccess || dwRead == 0) break;
		  
		  err << std::string(buff, dwRead);
	  } while (dwRead == 512);

	  // set_value_at_thread_exit crashes with msvc
	  res["streams"] = { { "stdout", lines },{ "stderr", err.str() } };
  },
  std::move(f)
  ).detach();

  auto end = std::chrono::system_clock::now() + std::chrono::milliseconds(timeout_millis);
  if (f_completes.wait_until(end) == std::future_status::ready)
  {
	  res["isSuccess"] = true;
  }
  else
  {
	  TerminateProcess(piProcInfo.hProcess, -1);
	  res["streams"] = {};
	  res["isTimeout"] = true;
  }
#endif
  return res;
}
