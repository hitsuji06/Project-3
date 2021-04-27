// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iostream>
#include <fstream>
#include <string>
#include "Monster.h"
#include "Room.h"
#include "Inventory.h"
#include "Player.h"

using namespace std;

#ifndef FUNCTION_H
#define FUNCTION_H

class Function
{
    private:
        bool func_execution;
        bool gameOver= false;
        static const int num_monsters = 20;
        static const int num_rooms = 5;
        int num_current_room = 0;
        int anger_level = 0;
        Monster monsters[num_monsters];
        Room rooms[num_rooms];
        
    public:
        Function();
        void merchantMenu(Inventory &inven); // This function displays the options of what the player can buy
        void statusUpdate(Inventory &inven, vector<Player>&); // displays status update
        int split(string str, char seperator, string array[], unsigned int size_array);
        void readMonsterFile(); // reads monsters.txt and creates Monster objects
        void readRoomFile(); // reads rooms.txt and creates Room objects
        Monster getMonster(int);
        Room getRoom(int);
        int getNumCurrentRoom();
        void updateNumCurrentRoom();
        int getAngerLevel();
        void updateAngerLevel();
        void combat(Inventory &theInventory , Monster theMonster,vector<Player>&);
        void surrender(vector<Player>&);
        void exploreRoom(Inventory& ,vector<Player>&, Room, Monster);
        void quitGame(Inventory&, vector<Player>&);
        void openDoorTry(Inventory &thInventor,vector <Player>&);
        void cookFood(Inventory &theInventory,vector<Player>&);
        void robbery(Inventory&);
        void brokenAccessary(Inventory&);
        void deathHunger(vector<Player>);
        void memberLocked(vector<Player>&);
        void npcTalk(Inventory& , vector<Player>&, Monster);
        void rpsDoor(Inventory&, vector<Player>&);
        bool npcPuzzle();

    };

#endif