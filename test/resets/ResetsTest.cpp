#include <iostream>

#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"

#include <memory>

void testNPCResetWithMultipleResets() {
    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<NPC> npc1 = make_shared<NPC>("50");
    shared_ptr<NPC> npc2 = make_shared<NPC>("35");


    NPCReset reset1(room, npc1, 3);
    NPCReset reset2(room, npc2, 2);

    reset1.performReset();
    reset1.performReset();
    reset1.performReset();
    reset1.performReset();
    reset1.performReset();

    reset2.performReset();
    reset2.performReset();
    reset2.performReset();
    reset2.performReset();
    reset2.performReset();

    if(room->getNumberOfNPCsWithID("50") == 3) {
        cout << "test passed: 3 npc's with id: 50 added" << endl;
    } else {
        cout << "test failed: " << endl;
    }

    if(room->getNumberOfNPCsWithID("35") == 2) {
        cout << "test passed: 2 npc's with id: 35 addded" << endl;
    } else {
        cout << "test failed: " << endl;
    }

    if(room->getNPCs().size() == 5) {
        cout << "test passed: 5 npc's in total were added" << endl;
    } else {
        cout << "test failed: " << endl;
    }

    auto npcs = room->getNPCs();

    if(npcs[0] == npc1) {
        cout << "test failed: not coppied properly" << endl;
    } else {
        cout << "test passed: npc not reference to object - " << npc1 << " : " << npcs[0] << endl;
    }

    if(npcs[0] == npcs[1]) {
        cout << "test failed: two npc's have same reference in room" << endl;
    } else { 
        cout << "test passed: npc's dont have the same reference - " << npcs[0] << " : " <<  npcs[1] << endl;
    }



}

void testNPCReset() {
    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<NPC> npc = make_shared<NPC>("50");

    NPCReset reset(room, npc, 3);

    reset.performReset();

    if(room->getNumberOfNPCsWithID("50") == 1) {
        cout << "test passed: after 1 reset npc count = 1" << endl;
    } else {
        cout << "test failed: npc count != 1" << endl;
    }

    reset.performReset();

    if(room->getNumberOfNPCsWithID("50") == 2) {
        cout << "test passed: after 3 reset npc count = 2" << endl;
    } else {
        cout << "test failed: npc count != 2" << endl;
    }

    reset.performReset();

    if(room->getNumberOfNPCsWithID("50") == 3) {
        cout << "test passed: after 3 resets npc count = 3" << endl;
    } else {
        cout << "test failed: npc count != 3" << endl;
    }

    reset.performReset();

    if(room->getNumberOfNPCsWithID("50") == 3) {
        cout << "test passed: after 4 resets npc count = 3" << endl;
    } else {
        cout << "test failed: npc count != 3" << endl;
    }


}

void testNPCResetWithNPCLimitZero() {
    shared_ptr<Room> room = make_shared<Room>();
    shared_ptr<NPC> npc = make_shared<NPC>("50");

    NPCReset reset(room, npc, 0);

    auto npcsInRoom = room->getNPCs();

    if(npcsInRoom.size() == 0) {
        cout << "test passed: room initialized with no npc" << endl;
    } else {
        cout << "test failed: room has npc in it upon itialization" << endl;
    }

    reset.performReset();

    npcsInRoom = room->getNPCs();

    if(npcsInRoom.size() == 0) {
        cout << "test passed: since npc limit is 0 no npc was added" << endl;
    } else {
        cout << "test failed: npc was added despite npc limit being 0" << endl;
    }
}

void performNPCResetTests() {
    testNPCResetWithNPCLimitZero();
    testNPCReset();
    testNPCResetWithMultipleResets();
}

void testDoorResetLocking() {
    shared_ptr<Room> room1 = make_shared<Room>();
    shared_ptr<Room> room2 = make_shared<Room>();

    room1->addDoor("12345", "north", "the door that leads north", room2);

    DoorReset reset(room, 0, "Lock");

    reset->performReset();

    // no real way to chedck that the change occured
    // should test what the locking / unlocking of doors does

    // we likely want to check that the player cannot move through a locked door.

}

void performDoorResetTests() {
    testDoorResetLocking();
}

int main() {

    // shared_ptr<Room> room = make_shared<Room>();

    // shared_ptr<Room> secondroom = make_shared<Room>();
    // room->addDoor("3215", "north", "the second door", secondroom);

    // shared_ptr<NPC> npc = make_shared<NPC>("50");
    // // Item item;


    // NPCReset npcReset(room, npc, 10);
    // DoorReset doorReset(room, 0, "Lock");
    // ItemReset itemReset(room); //item


    // npcReset.performReset();
    // doorReset.performReset();
    // itemReset.performReset();


    performNPCResetTests();

    performDoorResetTests();




    return 0;
}