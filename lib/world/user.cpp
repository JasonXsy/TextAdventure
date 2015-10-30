/* 	User CLASS
	Contains statistics and methods for player inventory and creation
	
	Created by: Jordan Nielsen
*/

#include "user.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Default constructor setting up basic values */
User::User(){
  setUserType(true);
  setUserName("testUser");
  setPassword("password");
  playerHealth = playerMaxHealth;
  usedDefaultConstructor = true;

  /*inventory = new Inventory(); */
}

/* User constructor for setting up basic information */
User::User(bool isAdmin, string userName, string password, Room currentRoom) {
  setUserType(isAdmin);
  setUserName(userName);
  setPassword(password);
  setRoom(currentRoom);
  playerHealth = playerMaxHealth;
  usedDefaultConstructor = false;

  /* inventory = new Inventory(); */
}

/* Ensures deletion of the player's inventory and currentRoom if default constructor used*/
User::~User() {
   /* delete inventory; */
}

void User::setUserName(string userName){
  this->userName = userName;
}

string User::getUserName(){
  return userName;
}

void User::setPassword(string password){
  this->password = password;
}

string User::getPassword(){
  return password;
}

void User::setUserType(bool isAdmin){
  this->isAdmin = isAdmin;
}

bool User::getUserType(){
  return isAdmin;
}

 /*
void User::setInventory(Inventory inventory){
  this->inventory = inventory;
}

vector<Item> User::getInventory() {
  return inventory;
}
*/

void User::setRoom(Room currentRoom){
  this->currentRoom = currentRoom;
}

Room User::getRoom(){
  return currentRoom;
}

void User::setPlayerHealth(int playerHealth){
  this->playerHealth = playerHealth;
}

int User::getPlayerHealth(){
  return playerHealth;
}

void User::setPlayerAttack(int playerAttack){
  this->playerAttack = playerAttack;
}

int User::getPlayerAttack(){
  return playerAttack;
}

void User::setPlayerDefense(int playerDefense){
  this->playerDefense = playerDefense;
}

int User::getPlayerDefense(){
  return playerDefense;
}

void User::setLivingStatus(bool isAlive){
  this->isAlive = isAlive;
}

bool User::getLivingStatus(){
  return isAlive;
}