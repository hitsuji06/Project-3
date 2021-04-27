// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3
#include <string>

using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room
{
    private:
        string room_name;
        string gem_room;
        string treasure_room;
        int gold_room;
        
    public:
        Room();
        Room(string, string, string, int);
        string getRoomName();
        void setRoomName(string);
        string getGemRoom();
        void setGemRoom(string);
        string getTreasureRoom();
        void setTreasureRoom(string); 
        int getGoldRoom();
        void setGoldRoom(int);
};

#endif