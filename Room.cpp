// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iostream>
#include <string>
#include <fstream>
#include "Room.h"
#include "Function.h"

using namespace std;

Room::Room()
{
    room_name = "" ;
    gem_room = "";
    treasure_room = "";
    gold_room = 0;
}
Room::Room(string rn, string gem, string treasure, int gold)
{
    room_name = rn;
    gem_room = gem;
    treasure_room = treasure;
    gold_room = gold;
}
string Room::getRoomName()
{
    return room_name;    
}
void Room::setRoomName(string rn)
{
    room_name = rn;
}
string Room::getGemRoom()
{
    return gem_room;
}
void Room::setGemRoom(string gem)
{
    gem_room = gem;
}
string Room::getTreasureRoom()
{
    return treasure_room;
}
void Room::setTreasureRoom(string treasure)
{
    treasure_room = treasure;
}
int Room::getGoldRoom()
{
    return gold_room;    
}
void Room::setGoldRoom(int gold)
{
    gold_room = gold;
}