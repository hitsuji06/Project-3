// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <string>
#include <vector>
#include "Inventory.h"

using namespace std;

Inventory::Inventory()
{
    gold = 100;
    ingredients = 0;
    armor = 0;
    key = false;
    gemstones;
    treasure;
    weapon;
    weapons_combined = 0;
    num_weapon.push_back(0);
    num_weapon.push_back(0);
    num_weapon.push_back(0);
    num_weapon.push_back(0);
    num_weapon.push_back(0);
    cookware;
    num_cookware.push_back(0);
    num_cookware.push_back(0);
    num_cookware.push_back(0);
}
Inventory::Inventory(int theGold, int theIngredients, int theArmor, bool theKey, vector<string> theGems, vector<string> theTreasure, vector<string> theWeapon, int num_weapon)
{
    gold = theGold;
    ingredients = theIngredients;
    armor = theArmor;
    gemstones = theGems;
    treasure = theTreasure;
    weapons_combined = num_weapon;
}
double Inventory::getGold()
{
    return gold;
}
void Inventory::setGold(double theGold)
{
    gold = theGold;
}
int Inventory::getIngredients()
{
    return ingredients;
}
void Inventory::setIngredients(int theIngredients)
{
    ingredients = theIngredients;
}
string Inventory::getGemstones(int i)
{
    return gemstones[i];
}
void Inventory::setGemstones(string theGem)
{
    gemstones.push_back(theGem);
}
int Inventory::getGemSize()
{
    return gemstones.size();
}
string Inventory::getTreasure(int i)
{
    return treasure[i];
}
void Inventory::setTreasure(string theTreasure)
{
    treasure.push_back(theTreasure);   
}
int Inventory::getTreasureSize()
{
    return treasure.size();
}
string Inventory::getWeapon(int i)
{
    return weapon[i];
}
void Inventory::addWeapon(string theWeaponAdd)
{
    weapon.push_back(theWeaponAdd);
}
int Inventory::getWeaponsCombined()
{
    return weapons_combined;
}
void Inventory::setWeaponsCombined(int weapon_value)
{
    weapons_combined = weapon_value;
}
int Inventory::getWeaponSize()
{
    return weapon.size();
}
void Inventory::weaponPopback()
{
    weapon.pop_back();
}
void Inventory::numWeapon()
{
    int num_club = 0;
    int num_spear = 0;
    int num_crossbow = 0;
    int num_battleaxe = 0;
    int num_longsword = 0;
    for (int i = 0; i < weapon.size(); i++)
    {
        if (weapon[i] == "club")
        {
            num_club++;
        }
        else if (weapon[i] == "spear")
        {
            num_spear++;
        }
        else if (weapon[i] == "crossbow")
        {
            num_crossbow++;
        }
        else if (weapon[i] == "battleaxe")
        {
            num_battleaxe++;
        }
        else
        {
            num_longsword++;
        }
    }
    num_weapon[0] = (num_club);
    num_weapon[1] = (num_spear);
    num_weapon[2] = (num_crossbow);
    num_weapon[3] = (num_battleaxe);
    num_weapon[4] = (num_longsword);
}
int Inventory::getNumWeapon(int i)
{
    return num_weapon[i];
}
void Inventory::setNumWeaponAt(int newnumber,int position)
{
    num_weapon[position]=newnumber;
}
string Inventory::getCookware(int i)
{
    return cookware[i];
}
void Inventory::addCookware(string cooker)
{
    cookware.push_back(cooker);
}
void Inventory::numCookware()
{
    int num_cauldron = 0;
    int num_cast_iron_pan = 0;
    int num_ceramic_pot = 0;
    for (int i = 0; i < cookware.size(); i++)
    {
        if (cookware[i] == "cauldron")
        {
            num_cauldron++;
        }
        else if (cookware[i] == "cast iron pan")
        {
            num_cast_iron_pan++;
        }
        else
        {
            num_ceramic_pot++;
        }
    }
    num_cookware[0] = (num_cauldron);
    num_cookware[1] = (num_cast_iron_pan);
    num_cookware[2] = (num_ceramic_pot);
}
int Inventory::getNumCookware(int i)
{
    return num_cookware[i];
}
int Inventory::getArmor()
{
    return armor;
}
void Inventory::setArmor(int num_armor)
{
    armor = num_armor;
}

void Inventory::setKey(bool newKeyStatus)
{
    key = newKeyStatus;
}

bool Inventory::getKey()
{
    return key;
}
int Inventory::getNumCookwareSize()
{
    return cookware.size();
}
void Inventory::setNumCookwareAt(int newnumber,int position)
{
    num_cookware[position]=newnumber;
}