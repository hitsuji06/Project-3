// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iostream>
#include <string>
#include <fstream>
#include "Monster.h"
#include "Room.h"
#include "Function.h"
#include "Player.h"
#include "Inventory.h"

using namespace std;

int main()
{
    Function functions;
    Inventory theInventory;
    string leader_name, m1_name, m2_name, m3_name, m4_name;
    cout << "An evil sorcerer has captured a group of players and trapped them in a monster-filled, labyrinthine dungeon for his own amusement. " 
    << "The goal of this game is to make it out of the dungeon with as many party members alive as possible. " 
    << "Each day in the dungeon makes you more hungry (reduces fullness) and has risks such as monsters and traps. "
    << "You can fight monsters, speak to NPCs, and explore, but you have to make it through the dungeon "
    << "before the sorcerer runs out of patience and destroys the dungeon, along with the player and all the party members!" << endl << endl;

    cout << "> What is the first name of the leader of the party?" << endl;
    cin >> leader_name;

    cout << "> What are the first names of the four traveling companions?" << endl;
    cout << "1) ";
    cin >> m1_name;
    cout << "2) ";
    cin >> m2_name;
    cout << "3) ";
    cin >> m3_name;
    cout << "4) ";
    cin >> m4_name;
    Player Mainplayer;
    Player member1;
    Player member2;
    Player member3;
    Player member4;
    Mainplayer.setName(leader_name);
    Mainplayer.setMainPlayer(true);
    member1.setName(m1_name);
    member2.setName(m2_name);
    member3.setName(m3_name);
    member4.setName(m4_name);
    vector<Player> crew;
    crew.push_back(Mainplayer);
    crew.push_back(member1);
    crew.push_back(member2);
    crew.push_back(member3);
    crew.push_back(member4);
    cout << endl;
    cout << "> You are at the entrance of the dungeon and there is a merchant." << endl;
    cout << "> Merchant:" << endl;
    cout << "\"Between the 5 of you, you have 100 gold coins and 5 weapons. You will need to spend the rest of your money on the following items:" << endl;
    cout << "- INGREDIENTS. To make food, you have to cook raw ingredients." << endl;
    cout << "- COOKWARE. If you want to cook, you have to have cookware first." << endl;
    cout << "- WEAPONS. You’ll want at least one weapon per party member to fend off monsters." << endl;
    cout << "- ARMOR. Armor increases the chances of surviving a monster attack." << endl;
    cout << "You can spend all of your money here before you start your journey, or you can save some to spend on merchants along the way. " 
    << "But beware, some of the merchants in this dungeon are shady characters, and they won’t always give you a fair price...\"" << endl << endl;
    
    functions.merchantMenu(theInventory);
    while (functions.getNumCurrentRoom() < 5)
    {
        functions.statusUpdate(theInventory, crew); 
    }
}