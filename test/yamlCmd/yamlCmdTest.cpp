#include <iostream>
#include <string>
#include <fstream>
#include <yaml-cpp/yaml.h>

using namespace std;

int main(int argc, char const *argv[])
{

   YAML::Emitter out;
    out << YAML::BeginMap;
    out << YAML::Key << "MOVE";
    out << YAML::Value << YAML::BeginSeq << "move" << "mv" << "go" << YAML::EndSeq;
    out << YAML::EndMap;
   std::cout << "Here's the output YAML:\n" << out.c_str();
   std::ofstream fout("cmd_global.yaml");
    return 0;
}