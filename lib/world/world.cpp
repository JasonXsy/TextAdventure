/*World CLASS

This is a game class that contains attributes and methods for each room contained in the game world.

Created By: Sarah Kim Dao
*/

#include "world.h"


World::World(){

	cout << endl << "--Now Instantiating World--" << endl;

	//Parsing Rooms
	shared_ptr<roomLibrary> rL( new roomLibrary());
	roomLib = rL;

	for (auto & room :roomLib->getRoomList()){
		roomList.push_back(room);
	}

	//Parsing NPCs
	shared_ptr<npcLibrary> nL( new npcLibrary());
	NPCLib = nL;

	//Parsing Items
	shared_ptr<itemLibrary> iL( new itemLibrary());
	itemLib = iL;

	//Parsing Spells
	shared_ptr<spellsLibrary> sL( new spellsLibrary() );
	spellsLib = sL;


	//Parsing Resets
	shared_ptr<resetLibrary> reL( new resetLibrary(NPCLib->getNPCList(), roomList, itemLib->getItemList() ) );
	resetLib = reL;

	performResets();

	//Set Current Room
	cout << endl <<"--World Instantiation Complete! Now setting up Current Room--" << endl;
	//currentRoom = roomList.front(); 

	//currentRoom->addNPC(NPCLib->spawn("103"));
	//roomList.front()->addNPC(NPCLib->spawn("104"));

	roomList.front()->addItem(itemLib->spawn("3000"));
	roomList.front()->addItem(itemLib->spawn("3001"));
}

World::~World(){
	
}

World::World(World &obj){
	currentRoom = obj.getCurrentRoom();

	for (auto & room : obj.getRoomList()){
		roomList.push_back(room);
	}
}

shared_ptr<Room> World::getCurrentRoom(){
	return currentRoom;
}


vector<shared_ptr<Room>> World::getRoomList(){
	return roomList;
}

shared_ptr<Room> World::getRoom(int i){
	return roomList.at(i);
}

shared_ptr<Room> World::getRoom(string roomID) {
	for(auto &room : roomList) {
		if(roomID.compare(room->getId()) == 0) {
			return room;
		}
	}

	return nullptr;
}

shared_ptr<NPC> World::getNPC(string npcID) {
	return NPCLib->get("npcID");
}

void World::setCurrentRoom(shared_ptr<Room> newRoom){
	currentRoom = newRoom;
}

void World::addReset(shared_ptr<Reset> reset) {
	resets.push_back(reset);
}

void World::performResets() {

	cout << "---Now Performing Resets ..." ;

	for(auto &reset : resetLib->getResetList()) {
		reset->performReset();
	}

	cout << "Resets Complete!" << endl;

}


string World::moveTo(string dir){
	for (auto & door : currentRoom->getDoorList() ) {
		if(door->findKeyword(dir) || door->getLeadsTo()->findKeyword(dir)){
			currentRoom = (door->getLeadsTo());
			return (currentRoom)->getDesc();
		}
	}
	return "Cannot go there";	
}

shared_ptr<npcLibrary> World::getNPCLib(){
	return NPCLib;
}

shared_ptr<spellsLibrary> World::getSpellsLib(){
	return spellsLib;
}
