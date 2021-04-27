// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    private:
        string name;
        double fp; // fullness point
        bool mainPlayer;
    public:
        Player();
        Player(string, int , bool);
        string getName();
        void setName(string);
        double getFp();
        void setFp(double);
        bool getMainPlayer();
        void setMainPlayer(bool);
};

#endif