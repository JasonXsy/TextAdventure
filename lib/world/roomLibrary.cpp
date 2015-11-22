
//Test run with g++ -I. -g npc_yamlparser.cpp -lyaml-cpp -std=c++11 -L. -o yamltest
// ./yamltest

#include "roomLibrary.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
roomLibrary::roomLibrary(){
	parseYaml();
}

shared_ptr<Room> roomLibrary::create(string name,string id, string description){
	shared_ptr<Room> room (new Room());
	cout << endl << "creating room" << endl;
	room->setName(name);
	room->setId(id);
	room->setDesc(description);
	//room->addKeywords
	room->setExtDesc("no extended desc");

	return room;
}

void roomLibrary::addRoom(shared_ptr<Room> room){
	roomList.push_back(room);
}

shared_ptr<Room> roomLibrary::getRoom(string id){
	for (auto & room :roomList){
		if (room->getId() == id){
			return room;
		}
	}
	return NULL;
}

vector<shared_ptr<Room>> roomLibrary::getRoomList(){
	return roomList;
}

void roomLibrary::parseYaml(){
	using namespace std;
	YAML::Node allNode = YAML::LoadFile("gameYaml/midgaard.yaml");
	YAML::Node roomsNodes = allNode["ROOMS"];

	string roomsDescription;
	string doorsDesc; 
	string doorsDir;
	string doorsKeywords;
	string doorsTo;
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

		addRoom(create(roomName,roomId,roomsDescription));

		// cout <<"-----New Room Created!------"<< endl;
		// cout << "Room name is " << roomName << endl << endl;
		// cout << roomName << "'s' id is: " << roomId << endl << endl;
		// cout << roomName << "'s description is: " << roomsDescription << endl<< endl;

		YAML::Node doorsNode = roomsNodes[i]["doors"];
		for(int k = 0; k < doorsNode.size(); k++){
			doorsDesc = " ";
			doorsDir = " ";
			doorsKeywords = "";
			doorsTo = "";

			//parsing Doors. and it's description, direction, keywords and to
			YAML::Node doorsdescNode = doorsNode[k]["desc"];
			for(int l = 0; l < doorsdescNode.size(); l++){
				doorsDesc = doorsdescNode[l].as<string>();
				}

			YAML::Node doorsdirNode = doorsNode[k]["dir"];
			doorsDir = doorsdirNode.as<string>();

			YAML::Node doorskeywordNode = doorsNode[k]["keywords"];
			for (int m = 0; m < doorskeywordNode.size(); m++){
				doorsKeywords = doorskeywordNode[m].as<string>();
				//cout << doorsKeywords << endl << endl;
			}
			YAML::Node doorstoNode = doorsNode[k]["to"];
			doorsTo = doorstoNode.as<string>();

			

			// cout << "----Doors in the room " << roomName << " -----" << endl;
			// cout << "description: " << doorsDesc << endl << endl;
			// cout << "direction: " << doorsDir << endl << endl;
			// cout << "to: " << doorsTo << endl << endl;
		}		

	}
}
