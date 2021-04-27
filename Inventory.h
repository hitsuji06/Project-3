// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <string>
#include <vector>

using namespace std;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
    bool key;
    double gold;
    int ingredients;
    int armor;
    vector<string> gemstones;
    vector<string> treasure;
    vector<string> weapon;
    int weapons_combined;
    vector<int> num_weapon;
    vector<string> cookware;
    vector<int> num_cookware;
public:
    Inventory();
    Inventory(int, int, int, bool, vector<string>, vector<string>, vector<string>, int);
    double getGold();
    void setGold(double);
    int getIngredients();
    void setIngredients(int);
    string getGemstones(int);
    void setGemstones(string);
    int getGemSize();
    string getTreasure(int);
    void setTreasure(string);
    int getTreasureSize();
    string getWeapon(int);
    void addWeapon(string);
    int getWeaponsCombined();
    void setWeaponsCombined(int);
    int getWeaponSize();
    void weaponPopback();
    void numWeapon();
    int getNumWeapon(int);
    void setNumWeaponAt(int,int);
    string getCookware(int);
    void addCookware(string);
    void numCookware();
    int getNumCookware(int);
    int getNumCookwareSize();
    void setNumCookwareAt(int,int);
    int getArmor();
    void setArmor(int);
    void setKey(bool);
    bool getKey();
};

#endif