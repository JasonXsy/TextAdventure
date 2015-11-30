//
//  item.h
//  TeamProject_cmpt373
//
//  Created by JasonYang on 2015-10-04.
//  Copyright © 2015 JasonYang. All rights reserved.
//

#ifndef item_h
#define item_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>
using namespace std;

class Item{

private:
    
    // attributes (yaml)
    string itemID;          // the Id of the item
    string longDesc;
    string shortDesc;
    string extraDesc;
    vector<string> keywords;


    //save for late (status)
    string itemType;        // the type of the item
    string itemName;
    //int itemDamage;         // the damage of the item (deal damage to player or monster)
    int itemBoost;          // increase the max HP of user
    // functions (status)
    void setAll(string type);       // create potion or weapon or armour
    
    
public:
    // constructor
    Item(string type, string id); // status
    Item(string id); // yaml
    Item(Item *item); // copy
    //destructor
    // ~Item();

    // ID set,get
    void setID(string id);
    string getID() const;
    // descriptions 
    void addLongDesc(string s);
    //void addLongDescs(vector<string> s);
    void addShortDesc(string s);
    void addExtraDesc(string s);
    //void addExtraDescs(vector<string> s);
    string getLongDesc()const;
    string getShortDesc()const;
    string getExtraDesc() const;
    
    // keyword
    void addKeyword(string s);
    void addKeywords(vector<string> s);
    bool searchKeyword(string s) const;
    void removeKeyword(string s);
    void removeAllKeyword();
    vector<string> getKeyword()const;
    void printVector() const;


    // functions (status)
    void setBoost();
    int getBoost() const;
    // helper function
    void checkItem() const;         // Check Item attributes
    
};

#endif /* item_h */
