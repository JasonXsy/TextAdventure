#include <iostream>

#include "reset/NPCReset.h"
#include "reset/DoorReset.h"
#include "reset/ItemReset.h"

#include <memory>

int main() {

    shared_ptr<Room> room = make_shared<Room>();

    NPC npc("monster", "42");
    // Item item;


    NPCReset npcReset(room, npc, 10);
    DoorReset doorReset(room, 5, "Lock");
    ItemReset itemReset(room); //item


    npcReset.performReset();
    doorReset.performReset();
    itemReset.performReset();

    return 0;
}