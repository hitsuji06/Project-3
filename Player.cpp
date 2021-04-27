// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include "Player.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
    
Player::Player()
{
    name = "";
    fp = 10.0;
    mainPlayer=false;
}
Player::Player(string n, int f, bool playermain)
{
    name = n;
    fp = f;
    mainPlayer=playermain;
}
string Player::getName()
{
    return name;    
}
void Player::setName(string new_name)
{
   name = new_name;
}
double Player::getFp()
{
    return fp;   
}
void Player::setFp(double new_fp)
{
   fp = new_fp;
}
bool Player::getMainPlayer()
{
    return mainPlayer;
}
void Player::setMainPlayer(bool isMainPlayer)
{
    mainPlayer = isMainPlayer;
}