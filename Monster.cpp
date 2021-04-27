// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iostream>
#include <string>
#include <fstream>
#include "Monster.h"
#include "Function.h"

using namespace std;

Monster::Monster()
{
    name_monster = "";
    level = 0;
}
Monster::Monster(string m, int l)
{
    name_monster = m;
    level = l;
}
string Monster::getMonsterName()
{
    return name_monster;
}
void Monster::setMonsterName(string m)
{
    name_monster = m;
}
int Monster::getLevel()
{
    return level;
}
void Monster::setLevel(int l)
{
    level = l;
}