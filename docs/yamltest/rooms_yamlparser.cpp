
//Test run with g++ -I. -g npc_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest

#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// void ClassName::functionName(string name){

int main()
{
	using namespace std;

	YAML::Node allNode = YAML::LoadFile("test.yml");
	YAML::Node roomsNodes = allNode["ROOMS"];

	string roomsDescription;
	vector<string> doorsDesc; //need to rework
	vector<string> doorsDir;
	string keywords;
	string to;
	string extended_desc; //leave out for now
	string roomId;
	string roomName;

	for(int i = 0; (unsigned)i < roomsNodes.size(); i++) {
		roomsDescription = " ";
		roomId = " ";
		roomName = " ";

		//parsing room's main description
		YAML::Node descriptionNode = roomsNodes[i]["desc"];
		for(int j = 0; j < descriptionNode.size(); j++){
			roomsDescription += descriptionNode[j].as<string>();
		}

		//parsing room name and room id
		roomName = roomsNodes[i]["name"].as<string>();
		roomId = roomsNodes[i]["id"].as<string>();	

		YAML::Node doorsNode = roomsNodes[i]["doors"];
		for(int k = 0; k < doorsNode.size(); k++){
			doorsDesc.clear();
			doorsDir.clear();

			//parsing doors description node
			YAML::Node doorsdescNode = doorsNode[k]["desc"];
			for(int l = 0; l < doorsdescNode.size(); l++){
				doorsDesc.push_back(doorsdescNode[l].as<string>());
				cout << doorsDesc[l] << endl << endl;
				
				// YAML::Node doorsdirNode = doorsdescNode[l]["dir"];
				// for(int m = 0; m < doorsdirNode.size(); m++){
					// doorsDesc =doorsdirNode[m].as<string>();
					// cout << doorsDir[l] << endl << endl;	
				}
			}
		}					

	cout <<"--New Room Created!--"<< endl;
	cout << "Room name is " << roomName << endl << endl;
	cout << "Room name id " << roomId << endl << endl;
	cout << roomName << "'s description is " << roomsDescription << endl<< endl;


	// cout << "Doors description is " << doorsDesc << endl << endl;
	// cout << "Doors descriptions are " << endl;
	// for (auto & description : doorsDesc) {
	// 		cout << description << ", ";
	// 	}
	return 0;
}