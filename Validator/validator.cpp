#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "json.hpp"


using json = nlohmann::json;

json spawn(std::string program, std::string arg, json in, int timeout);

json test(std::string script, json chall)
{
  std::string bin = "node";
  if(script.find(".js") == std::string::npos)
    bin = "python";
  json result = {{"results", {}}};
  int successCount = 0;
  for_each(chall["tests"].begin(), chall["tests"].end(), [&chall, &result, &successCount, bin, script](json test) {
    json res = spawn(bin, script, test["inputs"], chall["timeAllowed"].get<int>()*1000);
    res["isSuccess"] = res["isSuccess"].get<bool>() && test["outputs"] == res["streams"]["stdout"];
    res["name"] = test["name"];
    result["results"].push_back(res);
    if(res["isSuccess"])
      successCount++;
  });

  result["percent"] = float(successCount)/chall["tests"].size();
  return result;
}

int main(int argc, char**  argv)
{
  if(argc != 3)
  {
    std::cerr << argv[0] << " <script file> <validation file>" << std::endl;
    return 1;
  }
  if(std::string(argv[2]).find(".json") < 0)
  {
    std::cerr << "validation file should be json" << std::endl;
    return 1;
  }
  std::string script(argv[1]);
  std::ifstream challfile(argv[2]);
  json chall;
  challfile >> chall;
  challfile.close();

  auto res = test(script, chall);
  for_each(res["results"].begin(), res["results"].end(), [](json result) {
    auto timeout = result["isTimeout"] ? " timeout" : "";
    auto success = result["isSuccess"] ? "Success" : "Failed";
    std::cout << "Test " << result["name"] << " --- " << success << timeout << std::endl;
  });
  std::cout << "Pourcentage de réussite: " << res["percent"].get<float>()*100 << "%" << std::endl;
}