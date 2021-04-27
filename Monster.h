// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iostream>
#include <string>
#include <fstream>

#ifndef MONSTER_H
#define MONSTER_H

using namespace std;

class Monster
{
private:
    string name_monster;
    int level;

public:
    Monster();
    Monster(string, int);
    string getMonsterName();
    void setMonsterName(string);
    int getLevel();
    void setLevel(int);
};

#endif