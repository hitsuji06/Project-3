// CSCI1300 Spring 2021
// Author: Sergio Borrego
// Partner: Jake Kim
// Recitation: 119 – Christen Malloy
// Project 3

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "Function.h"
#include "Inventory.h"
#include "Player.h"
#include "Room.h"

using namespace std;

Function::Function()
{
    func_execution = true;
    num_current_room = 0;
    anger_level = 0;
}
void Function::quitGame(Inventory &inven, vector<Player> &players)
{
    string rooms[5] = {"Red Room", "Blue Room", "Green Room", "Yellow Room", "Final Room"};

    cout<< "It is very unfortunate that you were not able to complete the adventure.....We hope to see you again...."<<endl;
    cout << "-------------------------------FINAL STATS----------------------------------" << endl;
    cout << "Leader: " << players[0].getName() << endl;
    cout << "Rooms cleared: ";
    for(int i = 0; i < getNumCurrentRoom(); i++)
    {
        cout << rooms[i] << "  ";
    }
    cout << endl;
    cout << "Gold Pieces Remaining: " << inven.getGold() << endl;
    cout << "Treasure Acquired: ";
    for (int i = 0; i < inven.getGemSize(); i++)
    {
        cout << inven.getGemstones(i) << "  ";
    }
    for (int i = 0; i < inven.getTreasureSize(); i++)
    {
        cout << inven.getTreasure(i) << "  ";
    }
    cout << endl;
    ofstream result_file;
    result_file.open("results.txt");

    result_file << "-------------------------------FINAL STATS----------------------------------" << endl;
    result_file << "Leader: " << players[0].getName() << endl;
    result_file << "Rooms cleared: ";
    for(int i = 0; i < getNumCurrentRoom(); i++)
    {
        result_file << rooms[i] << "  ";
    }
    result_file << endl;
    result_file << "Gold Pieces Remaining: " << inven.getGold() << endl;
    result_file << "Treasure Acquired: ";
    for (int i = 0; i < inven.getGemSize(); i++)
    {
        result_file << inven.getGemstones(i) << "  ";
    }
    for (int i = 0; i < inven.getTreasureSize(); i++)
    {
        result_file << inven.getTreasure(i) << "  ";
    }

    result_file.close();

    exit(1);
}
void Function::openDoorTry(Inventory &theInventory,vector<Player> &crew)
{
    
    int rand_num = rand() % 3 + 1;
    if(theInventory.getKey()==true)
    {
        if(rand_num==1)
        {
            if (getNumCurrentRoom() == 4)
            { 
                updateNumCurrentRoom();
                string rooms[5] = {"Red Room", "Blue Room", "Green Room", "Yellow Room", "Final Room"};
                cout << "Congratulations! You were able to open the door! You have escaped the Dungeon successfully!" << endl;
                cout << "-------------------------------FINAL STATS----------------------------------" << endl;
                cout << "Leader: " << crew[0].getName() << endl;
                cout << "Rooms cleared: ";
                for(int i = 0; i < getNumCurrentRoom(); i++)
                {
                    cout << rooms[i] << "  ";
                }
                cout << endl;
                cout << "Gold Pieces Remaining: " << theInventory.getGold() << endl;
                cout << "Treasure Acquired: ";
                for (int i = 0; i < theInventory.getGemSize(); i++)
                {
                    cout << theInventory.getGemstones(i) << "  ";
                }
                for (int i = 0; i < theInventory.getTreasureSize(); i++)
                {
                    cout << theInventory.getTreasure(i) << "  ";
                }
                cout << endl;
                ofstream result_file;
                result_file.open("results.txt");

                result_file << "-------------------------------FINAL STATS----------------------------------" << endl;
                result_file << "Leader: " << crew[0].getName() << endl;
                result_file << "Rooms cleared: ";
                for(int i = 0; i < getNumCurrentRoom(); i++)
                {
                    result_file << rooms[i] << "  ";
                }
                result_file << endl;
                result_file << "Gold Pieces Remaining: " << theInventory.getGold() << endl;
                result_file << "Treasure Acquired: ";
                for (int i = 0; i < theInventory.getGemSize(); i++)
                {
                    result_file << theInventory.getGemstones(i) << "  ";
                }
                for (int i = 0; i < theInventory.getTreasureSize(); i++)
                {
                    result_file << theInventory.getTreasure(i) << "  ";
                }

                result_file.close();
               
            }
            else
            {
                cout<<"> Success! You were able to open the door."<<endl;
                updateNumCurrentRoom();
                theInventory.setKey(false);
            }
        }
        else if(rand_num==2)
        {
            cout<<"> Oh no the door didnt open, try again"<<endl;
        }
        else if(rand_num==3)
        {
            memberLocked(crew);
            updateNumCurrentRoom();
            theInventory.setKey(false);
            if (getNumCurrentRoom() == 5)
            { 
                string rooms[5] = {"Red Room", "Blue Room", "Green Room", "Yellow Room", "Final Room"};
                cout << "Congratulations! You were able to open the door! You have escaped the Dungeon successfully!" << endl;
                cout << "-------------------------------FINAL STATS----------------------------------" << endl;
                cout << "Leader: " << crew[0].getName() << endl;
                cout << "Rooms cleared: ";
                for(int i = 0; i < getNumCurrentRoom(); i++)
                {
                    cout << rooms[i] << "  ";
                }
                cout << endl;
                cout << "Gold Pieces Remaining: " << theInventory.getGold() << endl;
                cout << "Treasure Acquired: ";
                for (int i = 0; i < theInventory.getGemSize(); i++)
                {
                    cout << theInventory.getGemstones(i) << "  ";
                }
                for (int i = 0; i < theInventory.getTreasureSize(); i++)
                {
                    cout << theInventory.getTreasure(i) << "  ";
                }
                cout << endl;
                ofstream result_file;
                result_file.open("results.txt");

                result_file << "-------------------------------FINAL STATS----------------------------------" << endl;
                result_file << "Leader: " << crew[0].getName() << endl;
                result_file << "Rooms cleared: ";
                for(int i = 0; i < getNumCurrentRoom(); i++)
                {
                    result_file << rooms[i] << "  ";
                }
                result_file << endl;
                result_file << "Gold Pieces Remaining: " << theInventory.getGold() << endl;
                result_file << "Treasure Acquired: ";
                for (int i = 0; i < theInventory.getGemSize(); i++)
                {
                    result_file << theInventory.getGemstones(i) << "  ";
                }
                for (int i = 0; i < theInventory.getTreasureSize(); i++)
                {
                    result_file << theInventory.getTreasure(i) << "  ";
                }

                result_file.close();
               
            }
        }
    }
    else
    {
        cout<<"> Oh no! you don't have the key and you fell into a trap! Quickly solve the puzzle to escape"<<endl;
        rpsDoor(theInventory, crew);
    }
}
void Function::brokenAccessary(Inventory &inven)
{
    srand(time(NULL));
    int num = rand() % 2 + 1;
    
    if (num == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            if (inven.getNumWeapon(i) > 0)
            {
                inven.setNumWeaponAt(inven.getNumWeapon(i) - 1, i);
                break;
            }
        }
        
    }
    else
    {
        inven.setArmor(inven.getArmor() - 1);
    }
    cout << "> OH NO! One of your weapons/armor broke!" << endl;
}
void Function::exploreRoom(Inventory &theinventory, vector<Player> &crew, Room theroom, Monster themonsters)
{
    int percentage = rand() % 100;
    int misfortune = rand() % 100;
    bool menuout=true;
    int userchoice;
    int playersAlive = 0;
    for (int i = 0; i < crew.size(); i++)
    {
        if(crew[i].getFp()>0)
        {
            playersAlive++;
        }
    }  
    
    if(percentage<=19)
    {
        cout<<"> You have found the key!"<<endl;
        theinventory.setKey(true); 
    }
    else if(percentage>19&&percentage<=39)
    {
        cout<<"> " << themonsters.getMonsterName() << " AHEAD! THEY LOOK HOSTILE!" <<endl;
        cout<<"Lvl: "<<themonsters.getLevel()<<endl;  
        if(theinventory.getWeaponsCombined()>0&&theinventory.getArmor()>0){
            while(menuout==true)
            {
                cout<<"1: Fight!"<<endl;
                cout<<"2: Surrender!"<<endl;
                cin>>userchoice;
                
                if(userchoice==1)
                {
                    combat(theinventory,themonsters,crew);
                    menuout=false;
                }
                else if(userchoice==2)
                {
                    surrender(crew);
                    menuout=false;
                }
                else
                {
                    cout<<"Invalid input. Please enter 1 or 2"<<endl;
                }
            }
        }
        else
        {
            while(menuout==true)
            {
                cout<<"You dont have enough weapons or armors to fight!"<<endl;
                cout<<"1: Surrender!"<<endl;
                cin>>userchoice;
                if(userchoice==1)
                {
                    surrender(crew);
                    menuout=false;
                }
                else
                {
                    cout<<"Invalid input. Please enter 1"<<endl;
                }
            }

        }  
    }
    
    else if(percentage>39&&percentage<=49)
    {
        cout<<"You have found a treasure! "<<theroom.getTreasureRoom()<<endl;
        theinventory.setTreasure(theroom.getTreasureRoom());
    }

    else if(percentage>49&&percentage<=59)
    {
        cout<<"You have found a gemstone! "<<theroom.getGemRoom()<<endl;
        theinventory.setGemstones(theroom.getGemRoom());
    }
    if(misfortune < 40)
    {
        robbery(theinventory);
    }
    if(percentage>49&&percentage<=99)
    {
        cout<<"Sadly you explored the place but dont find anything"<<endl;
    }
    
    for (int i = 0; i < playersAlive; i++)
    {
        crew[i].setFp(crew[i].getFp() - 1);
    }

}
void Function::combat(Inventory &theInventory, Monster theMonster, vector<Player> &thecrew)
{
    srand(time(NULL)); //seeds with the current time of compilation
    float w = theInventory.getWeaponsCombined();
    float a = theInventory.getArmor();
    float c = theMonster.getLevel();
    float d = 0;
    bool matching_weapon_found = false;
    int playersAlive = 0;
    for (int i = 0; i < thecrew.size(); i++)
    {
        if(thecrew[i].getFp()>0)
        {
            playersAlive++;
        }
    }  
    if (theInventory.getWeaponSize() == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i != j and theInventory.getWeapon(i) == theInventory.getWeapon(j))
                {
                    matching_weapon_found = true;
                }
            }
        }
        if (matching_weapon_found == false)
        {
            d = 1;
        }
    }

    float r1 = rand() % 6 + 1;     // generates a random # (1-6)
    float r2 = rand() % 6 + 1;     // generates a random # (1-6)
    int percentage = rand() % 100; // percentages
    int misfortune = rand() % 100;
    float result = ((r1 * w + d) - (r2 * c * (1.0 / a)));
    if (w > 0 && a > 0)
    {
        if (result > 0)
        {
            cout << "> You won and you found 20 ingredients and 50 of gold" << endl;
            theInventory.setIngredients(theInventory.getIngredients() + 20);
            theInventory.setGold(theInventory.getGold() + 50);
            if (percentage < 33) // 33% percent chance
            {
                theInventory.setKey(true);
                cout << "> You are lucky! The monster dropped a key!" << endl;
            }
        }
        else
        {
            cout << "> Unfortunately, you have lost the battle and here is the result" << endl;
            if (a >= 5) // if everyone has an armor
            {
                for (int i = 0; i < playersAlive; i++)
                {
                    percentage = rand() % 100;
                    if (percentage < 5)
                    {
                        if (i == 0)
                        {
                            thecrew[i].setFp(0);
                            cout << "> Sadly, " << thecrew[0].getName() << " He was our hero, We cant continue without him" << endl;
                        }
                        thecrew[i].setFp(0); // O fp = death
                        cout << "> Sadly, " << thecrew[i].getName() << " has died in combat" << endl;
                    }
                }
            }
            else
            {
                for (int i = (playersAlive - 1); i > (a - 1); i--) // looking for the members w/o an armor
                {
                    percentage = rand() % 100;
                    if (percentage < 10)
                    {
                        thecrew[i].setFp(0);
                        cout << "> Sadly, " << thecrew[i].getName() << " has died in combat" << endl;
                    }
                }
            }
            theInventory.setGold(theInventory.getGold() - (theInventory.getGold() / 4));
            theInventory.setIngredients(theInventory.getIngredients() - 30);
            for (int i = 0; i < playersAlive; i++)
            {
            thecrew[i].setFp(thecrew[i].getFp() - 1);
            }
        }
    }
    for (int i = 0; i < playersAlive; i++)
    {
        thecrew[i].setFp(thecrew[i].getFp() - 1);
    }
    if(misfortune < 40)
    {
        brokenAccessary(theInventory);
    }
}



void Function::surrender(vector<Player> &crew)
{
    int playersAlive = 0;
    for (int i = 0; i < crew.size(); i++)
    {
        if(crew[i].getFp()>0)
        {
            playersAlive++;
        }
    }  
    
    crew[playersAlive-1].setFp(0); // 1 person captured

    cout<<"> Unfortunately, "<<crew[crew.size() - 1].getName()<<" has been captured and you need to continue without him/her."<<  endl;
    
    for (int i = 0; i < playersAlive; i++)
    {
        crew[i].setFp(crew[i].getFp() - 1);
    }
}

// This function displays the options of what the player can buy
void Function::merchantMenu(Inventory &inven)
{
    cout << "> The merchant asks if you wish to purcahse things in the following 4 categoies" << endl;

    double price_factor = 1;
    string choice = "1";
    double total_cost = 0.0;
    int i = 0;
    
    for (int i = 1; i < 5; i++)
    {
        if (getNumCurrentRoom() == i)
        {
            price_factor += .25; // price increases by 25% as you go into the next room          
        }
    }

    while (choice == "1" or choice == "2" or choice == "3" or choice == "4")
    {
        cout << "1. Ingredients" << endl;
        cout << "2. Weapons" << endl;
        cout << "3. Armor" << endl;
        cout << "4. Cookware" << endl;
        cout << "> Enter 1-4 or any other characters to quit" << endl;
        cin >> choice;

        if (choice == "1")
        {
            string kg = "0";

            cout << "> The merchant recommends you to purchase at least 10 kg of ingredients per person." << endl;

            while (isdigit(kg[0]))
            {
                cout << "> " << 1.0 * price_factor << " gold piece per kilogram of food" << endl;
                cout << "> How many kilograms of ingredients would you like to purchase?" << endl;
                cout << "> Enter any non-numeric charater to exit." << endl;
                cin >> kg;

                if (isdigit(kg[0]) and total_cost + stoi(kg) * price_factor <= inven.getGold())
                {
                    total_cost += stoi(kg) * price_factor;
                    inven.setIngredients(inven.getIngredients() + stoi(kg) * price_factor);
                    cout << "Current Total Cost: " << total_cost << " gold pieces" << endl;
                }
                else if (isdigit(kg[0]) and total_cost + stoi(kg) * price_factor > inven.getGold())
                {
                    cout << "> You do not have enough gold. Please choose a different amount. " << endl;
                    cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
                }
            }
        }
        else if (choice == "2")
        {
            string weapon_choice = "1";

            cout << "> You need weapons to be able to fend off monsters. "
                 << "Otherwise, you can only run! Equipping your team with the maximum number of weapons(1 weapon per person) "
                 << "and buying upgraded weapons that are worth 5 gold pieces will maximize your chances of survival during an attack. "
                 << "You can have a maximum of 5 weapons. These are the different types of weapons:" << endl;

            while ((weapon_choice == "1" or weapon_choice == "2" or weapon_choice == "3" or weapon_choice == "4" or weapon_choice == "5") and i < 5)
            {
                cout << "1. A club costs " << 2 * price_factor << " gold pieces." << endl
                     << "2. A spear costs "<< 2 * price_factor << " gold pieces." << endl
                     << "3. A crossbow costs " << 5 * price_factor << " gold pieces." << endl
                     << "4. A battle-axe costs " << 5 * price_factor << " gold pieces." << endl
                     << "5. A longsword costs " << 5 * price_factor << " gold pieces." << endl;
                cout << "> Which weapons would you like to purchase?" << endl;
                cout << "> Enter 1-5 or any other characters to quit" << endl;
                cin >> weapon_choice;

                if (weapon_choice == "1" or weapon_choice == "2")
                {
                    if (total_cost + 2 * price_factor <= inven.getGold())
                    {
                        total_cost += 2 * price_factor;
                        inven.setWeaponsCombined(inven.getWeaponsCombined() + 1);
                        cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;

                        if (weapon_choice == "1")
                        {
                            inven.addWeapon("club");
                        }
                        else
                        {
                            inven.addWeapon("spear");
                        }
                    }
                    else
                    {
                        cout << "> You do not have enough gold. You cannot purchase a weapon." << endl;
                        cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
                    }
                }
                else if (weapon_choice == "3" or weapon_choice == "4" or weapon_choice == "5")
                {
                    if (total_cost + 5 * price_factor <= inven.getGold())
                    {
                        total_cost += 5 * price_factor;
                        inven.setWeaponsCombined(inven.getWeaponsCombined() + 2);
                        cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;

                        if (weapon_choice == "3")
                        {
                            inven.addWeapon("crossbow");
                        }
                        else if (weapon_choice == "4")
                        {
                            inven.addWeapon("battleaxe");
                        }
                        else
                        {
                            inven.addWeapon("longsword");
                        }
                    }
                    else
                    {
                        cout << "> You do not have enough gold. Please choose a different weapon." << endl;
                        cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
                    }
                }

                i++;
            }
        }
        else if (choice == "3")
        {
            int num_armor;

            cout << "> A set of armor costs " << 5 * price_factor <<" gold coins. Armor protects you from monsters. "
                 << "Equipping your team with the maximum amount of armor(1 armor per person) will maximize your chances of survival during an attack. "
                 << "Adding more armor on top of the maximum amount will not increase your chances further." << endl;
            cout << "How many sets of armor would you like to purchase?" << endl;
            cin >> num_armor;

            if (total_cost + num_armor * 5 * price_factor <= inven.getGold() and inven.getArmor() + num_armor <= 5)
            {
                total_cost += num_armor * 5 * price_factor;
                inven.setArmor(inven.getArmor() + num_armor);
            }
            else if (total_cost + num_armor * 5 * price_factor > inven.getGold() and inven.getArmor() + num_armor <= 5)
            {
                cout << "> You do not have enough gold. Please choose a different amount." << endl;
            }
            else if (inven.getArmor() + num_armor > 5)
            {
                cout << "> You can only purchase maximum of 5 armors. Please choose a different amount." << endl;
            }
        }
        else if (choice == "4")
        {
            string cookware_choice = "1";
            while (cookware_choice == "1" or cookware_choice == "2" or cookware_choice == "3")
            {
                cout << "1. A cauldron costs " << 20 * price_factor << " gold pieces. You can use a cauldron to stew and boil ingredients. "
                     << "It is made of thick sturdy metal, so it only has a 2% chance of breaking each time you use it." << endl
                     << "2. A cast iron pan costs " << 10 * price_factor << " gold pieces. You can use a frying pan to sizzle ingredients. "
                     << "It is not as sturdy as a cauldron, with a 10% chance of breaking each time you use it." << endl
                     << "3. A ceramic pot costs " << 5 * price_factor << " gold pieces. You can use a ceramic pot to stew and boil ingredients. "
                     << "It is made from weaker material, so it has a 25% chance of breaking each time you use it." << endl;
                cout << "> Which cookwares would you like to purchase?" << endl;
                cout << "> Enter 1-3 or any other characters to quit" << endl;
                cin >> cookware_choice;

                if (cookware_choice == "1" and total_cost + 20 * price_factor <= inven.getGold())
                {
                    total_cost += 20 * price_factor;
                    cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
                    inven.addCookware("cauldron");
                }
                else if (cookware_choice == "2" and total_cost + 10 * price_factor <= inven.getGold())
                {
                    total_cost += 10 * price_factor;
                    cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
                    inven.addCookware("cast iron pan");
                }
                else if (cookware_choice == "3" and total_cost + 5 * price_factor <= inven.getGold())
                {
                    total_cost += 5 * price_factor;
                    cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
                    inven.addCookware("ceramic pot");
                }
                else
                {
                    cout << "> You do not have enough gold. Please choose a different amount." << endl;
                }
            }
        }
        cout << "Current Total Cost: " << total_cost << " gold pieces" << endl << endl;
    }
    inven.setGold(inven.getGold() - total_cost);
    inven.numWeapon();
    inven.numCookware();
}
// This function displays current status
void Function::statusUpdate(Inventory &inven, vector<Player> &players)
{
    readMonsterFile();
    readRoomFile();
    Monster mons;
    Room rooms;
    rooms = getRoom(getNumCurrentRoom());
    int num_alive = 0;
    for (int i = 0; i < 5; i++)
    {
        if (players[i].getFp() > 0)
        {
            num_alive++;
        }
    }

    if (getAngerLevel() >= 100)
    {
        cout << "The sorcerer is furious and have caught you trying to escape." << endl;
        cout << "---------------------------GAME OVER------------------------------" << endl;
        quitGame(inven, players);
    }
    if (players[0].getFp() <= 0)
    {
        cout << "The journey cannot be continued without the leader." << endl;
        cout << "---------------------------GAME OVER------------------------------" << endl;
        quitGame(inven, players);
    }
    if (num_alive < 2)
    {
        cout << "Unfortunately there are not enough members to complete the journey" << endl;
        cout << "---------------------------GAME OVER------------------------------" << endl;
        quitGame(inven, players);
    }

    cout << "----STATUS UPDATE----" << endl;
    cout << "CURRENT ROOM: "<< rooms.getRoomName() << endl;
    cout << "ROOM KEY FOUND: ";
    if(inven.getKey() == true)
    {
        cout << "FOUND" << endl;
    }
    else if(inven.getKey() == false)
    {
        cout << "NOT FOUND" << endl;
    }
    cout << "SORCERER ANGER LEVEL: " << getAngerLevel() << " OUT OF 100" << endl;
    cout << endl;
    cout << "----PARTY MEMBERS----" << endl;
    cout << "(LEADER) ME: " << players[0].getFp() << " FULLNESS POINTS" << endl;
    for (int i = 1; i < 5; i++)
    {
        if (players[i].getFp() <= 0)
        {
            players[i].setFp(0);
        }
        cout << "MEMBER " << i + 1 << ": " << players[i].getFp() << " FULLNESS POINTS" << endl;
    }
    cout << endl;
    cout << "----MATERIALS----" << endl;
    cout << "INGREDIENTS: " << inven.getIngredients() << " kg" << endl;
    cout << "COOKWARE: " << inven.getNumCookware(0) << " CAULDRON(S), "
    << inven.getNumCookware(1) << " CAST IRON PAN(S), "
    << inven.getNumCookware(2) << " CERAMIC POT(S)" << endl;
    cout << "WEAPONS: " << inven.getNumWeapon(0) << " CLUB(S), "
    << inven.getNumWeapon(1) << " SPEAR(S), "
    << inven.getNumWeapon(2) << " CROSSBOW(S), "
    << inven.getNumWeapon(3) << " BATTLEAXE(S), "
    << inven.getNumWeapon(4) << " LONGSWORD(S)" << endl;
    cout << "ARMOR: " << inven.getArmor() << " SET(S)" << endl;
    cout << "GOLD: " << inven.getGold() << " PIECE(S)" << endl;
    cout << "TREASURE ITEM: ";
   
    if (inven.getGemSize() > 0 and inven.getTreasureSize() > 0)
    {
        for (int i = 0; i < inven.getGemSize(); i++)
        {
            cout << inven.getGemstones(i) << " ";
        }
        for (int i = 0; i < inven.getTreasureSize(); i++)
        {
            cout << inven.getTreasure(i) << " ";
        }    
    }
    else if (inven.getGemSize() > 0 and inven.getTreasureSize() == 0)
    {
        for (int i = 0; i < inven.getGemSize(); i++)
        {
            cout << inven.getGemstones(i) << " ";
        }
    }
    else if (inven.getGemSize() == 0 and inven.getTreasureSize() > 0)
    {
        for (int i = 0; i < inven.getTreasureSize(); i++)
        {
            cout << inven.getTreasure(i) << " ";
        }
        
    }

    cout << endl;
    int choice = 0;
    srand(time(NULL));
    
    while (choice > 6 or choice < 1)
    {
        int percent = rand() % 100;
        cout << "> WOULD YOU LIKE TO (1) FIGHT A MONSTER, (2) SPEAK TO NPC, (3) COOK & EAT, "
        << "(4) EXPLORE THE ROOM, (5) OPEN THE DOOR, OR (6) QUIT?" << endl;
        cin >> choice;
        
        if (percent < 25)
        {
            mons = getMonster(getNumCurrentRoom() * 4);
        }
        else if (percent >= 25 and percent < 50)
        {
            mons = getMonster(getNumCurrentRoom() * 4 + 1);
        }
        else if (percent >= 50 and percent < 75)
        {
            mons = getMonster(getNumCurrentRoom() * 4 + 2);
        }
        else
        {
            mons = getMonster(getNumCurrentRoom() * 4 + 3);
        }
        
        if (choice == 1)
        {
            int fight_choice = 0;
            
            cout<< "> " << mons.getMonsterName() << " AHEAD! THEY LOOK HOSTILE!" <<endl;

            if(inven.getWeaponsCombined() > 0 and inven.getArmor() > 0)
            {
                while(fight_choice != 1 or fight_choice != 2)
                {
                    cout << "1: Fight!" << endl;
                    cout << "2: Surrender!" << endl;
                    cin >> fight_choice;
                    
                    if(fight_choice == 1)
                    {
                        combat(inven, mons, players);
                        break;
                    }
                    else if(fight_choice == 2)
                    {
                        surrender(players);
                        break;
                    }
                    else
                    {
                        cout<<"> Invalid input. Please enter 1 or 2"<<endl;
                    }
                }
            }
            else
            {
                cout << "> You need at least one weapon and an armor. Please select a different option." << endl;
                choice = 0;
            }
            updateAngerLevel();
        }
        else if (choice == 2)
        {
            npcTalk(inven, players, mons);
            updateAngerLevel();
        }
        else if (choice == 3)
        {
            cookFood(inven, players);
            updateAngerLevel();
        }
        else if (choice == 4)
        {
            exploreRoom(inven, players, rooms, mons);
            updateAngerLevel();
        }
        else if (choice == 5)
        {
            openDoorTry(inven, players);
            updateAngerLevel();
        }
        else if (choice == 6)
        {
            quitGame(inven, players);
        }
        else
        {
            cout << "> Invalid input. Please enter a number 1-6." << endl;
        }
    }
}
// This function splits a string and creates an array of strings with the split pieces
// parameters: string, seperator(char), array(string), size of the array(int)
// return: number of split pieces(int)
int Function::split(string str, char seperator, string array[], unsigned int size_array)
{
    unsigned int num_pieces = 1, starting_point = 0;
    int j = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i] == seperator && str[i + 1] != ' ')
        {
            array[j] = str.substr(starting_point, i - starting_point);

            starting_point = i + 1;

            num_pieces++;
            j++;
        }
        else if (str[i] == seperator && str[i + 1] == ' ')
        {
            array[j] = str.substr(starting_point, i - starting_point);

            starting_point = i + 2;

            num_pieces++;
            j++;
        }

        if (i == str.length() - 1)
        {
            array[j] = str.substr(starting_point);
        }
    }

    if (num_pieces > size_array)
    {
        return -1;
    }
    else if (str == "")
    {
        return 0;
    }
    else
    {
        return num_pieces;
    }
}
// This function reads monsters.txt to get the information on monsters
void Function::readMonsterFile()
{
    
    // create file stream objects/variables
    ifstream file;

    // open file
    file.open("monsters.txt");

    string line;
    int arr_size = 2;
    string arr[arr_size];
    int i = 0;
    // read lines from the file
    while (getline(file, line))
    {
        // process each line
        if (line.length() > 0)
        {
            split(line, ',', arr, arr_size);
            // arr[0] = name of monster
            // arr[1] = level of monster
            monsters[i].setMonsterName(arr[0]);
            monsters[i].setLevel(stoi(arr[1]));
        }
        i++;
    }
}
// This function reads rooms.txt to get the information on rooms
void Function::readRoomFile()
{
    
    // create file stream objects/variables
    ifstream file;

    // open file
    file.open("rooms.txt");

    string line;
    int arr_size = 3;
    string arr[arr_size];
    int arr_size2 = 2;
    string arr2[arr_size2];
    int i = 0;
    int j = 0;
    // read lines from the file
    while (getline(file, line))
    {
        // process each line
        if (line.length() > 0)
        {
            if (i % 2 == 0)
            {
                rooms[j].setRoomName(line);
            }
            else
            {
                split(line, ',', arr, arr_size);
                // arr[0] = gem
                // arr[1] = treasure
                // arr[2] = gold

                rooms[j].setGemRoom(arr[0]);
                rooms[j].setTreasureRoom(arr[1]);
                split(arr[2], ' ', arr2, arr_size2);
                rooms[j].setGoldRoom(stoi(arr2[0]));

                j++;
            }
            if (j == 5)
            {
                break;
            }
        }
        i++;
    }
}
Monster Function::getMonster(int i)
{
    return monsters[i];
}
Room Function::getRoom(int i)
{
    return rooms[i];
}
int Function::getNumCurrentRoom()
{
    return num_current_room;
}
void Function::updateNumCurrentRoom()
{
    num_current_room += 1;
}
int Function::getAngerLevel()
{
    return anger_level;
}
void Function::updateAngerLevel()
{
    anger_level += 2;
}





void Function::cookFood(Inventory &theInventory,vector<Player> &crew)
{
    int kg;
    int cookwareChoice = 1;
    double foodRatio= 0.0;
    int playersAlive= 0;
    int probability=  rand() % 100;
    if(crew[0].getFp()!=10)
    {

        cout<<"> How many kilograms of food would you like to cook?"<<endl;
        cin>>kg;
        if (kg > theInventory.getIngredients())
        {
            cout << "You do not have enough ingredients" << endl;
        }
        else
        {
            for (int i = 0; i < crew.size(); i++)
            {
                if(crew[i].getFp()>0)
                {
                    playersAlive++;
                }
            }
            foodRatio=(kg*1.0)/(playersAlive*1.0);

            if(foodRatio+crew[0].getFp()<10)
            {
                cout<<"> Please select which cookware you would like to use to cook"<<endl;
                while (cookwareChoice == 1 or cookwareChoice == 2 or cookwareChoice == 3)
                {
                    cout<<"> You have ";
                    cout<<theInventory.getNumCookware(0)<<" cauldron(s)" << ", ";
                    cout<<theInventory.getNumCookware(1)<<" cast iron pan(s)" << ", ";
                    cout<<theInventory.getNumCookware(2)<<" ceramic pot(s)." << endl;
                    cout << "1. CAULDRON" << endl;
                    cout << "2. CAST IRON PAN" << endl;
                    cout << "3. CERAMIC POT" << endl;
                    cout << "> Please enter 1-3 or any other characters to exit" << endl;

                    cin>>cookwareChoice;
                    probability=  rand() % 100;
                    if(cookwareChoice==1&&theInventory.getNumCookware(0)>0)
                    {
                        if(probability<2)
                        {
                            cout<<"> The cauldron has been broken. You lost the ingredients and the cooking failed"<<endl;
                            for (int i = 0; i < playersAlive; i++)
                            {
                                crew[i].setFp(crew[i].getFp() - 1);
                            }
                        }
                        else
                        {
                            cout<<"> Food Is ready. Everyone gets +"<< foodRatio<<" Fullness Points"<<endl;
                            for (int i = 0; i < playersAlive; i++)
                            {
                                crew[i].setFp(crew[i].getFp() + foodRatio);
                            } 
                        }
                    }
                    else if(cookwareChoice==2&&theInventory.getNumCookware(1)>0)
                    {
                        if(probability>=2 and probability<12)
                        {
                            cout<<"> The cast iron pan has been broken. You lost the ingredients and the cooking failed"<<endl;
                            for (int i = 0; i < playersAlive; i++)
                            {
                                crew[i].setFp(crew[i].getFp() - 1);
                            }
                        }
                        else
                        {
                            cout<<"> Food Is ready. Everyone gets +"<< foodRatio<<" Fullness Points"<<endl;
                            for (int i = 0; i < playersAlive; i++)
                            {
                                crew[i].setFp(crew[i].getFp() + foodRatio);
                            } 
                        }
                    }
                    else if(cookwareChoice==3&&theInventory.getNumCookware(2)>0)
                    {
                        if(probability>=25 and probability<50)
                        {
                            cout<<"> The ceramic pot has been broken. You lost the ingredients and the cooking failed"<<endl;
                            for (int i = 0; i < playersAlive; i++)
                            {
                                crew[i].setFp(crew[i].getFp() - 1);
                            }
                        }
                        else
                        {
                            cout<<"> Food Is ready. Everyone gets +"<< foodRatio<<" Fullness Points"<<endl;
                            for (int i = 0; i < playersAlive; i++)
                            {
                                crew[i].setFp(crew[i].getFp() + foodRatio);
                            } 
                        }
                    }
                    else if(cookwareChoice > 3 and cookwareChoice < 1)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << "> Please try a different number" << endl << endl;
                    } 
                }

                theInventory.setIngredients(theInventory.getIngredients()-kg);
            }
            else
            {
                cout<<"You can't cook that much food you will be more than full"<<endl;
            }
        }
    }
    else
    {
        cout<<"You are already full you cant make more food!"<<endl;
    }
    
    
}

void Function::robbery(Inventory &inven)
{
    inven.setIngredients(0);
    for (int i = 0; i < inven.getNumCookwareSize(); i++)
    {
        inven.setNumCookwareAt(0, i);
    }
    inven.setArmor(0);
    cout << "> OH NO! Your team was robbed by dungeon bandits! You have no food/cookware/armor left!" << endl;
}

void Function::deathHunger(vector<Player> players)
{
    int playersAlive = 0;
    for (int i = 0; i < players.size(); i++)
    {
        if(players[i].getFp()>0)
        {
            playersAlive++;
        }
    }

    for (int i = 0; i < playersAlive-1; i++)
    {
        if (players[i].getFp() == 0)
        {
            cout << "> ON NO! Your teammate has died of hunger!" << endl;
        }
    }
    
}
void Function::memberLocked(vector<Player> &players)
{
    int playersAlive = 0;
    for (int i = 0; i < players.size(); i++)
    {
        if(players[i].getFp()>0)
        {
            playersAlive++;
        }
    }  

    players[playersAlive-1].setFp(0); // 1 person captured
    
    for (int i = 0; i < playersAlive; i++)

    {
        players[i].setFp(players[i].getFp() - 1);
    }

    cout << "> OH NO! one of your teammates is trapped in the previous room, and is unable to get through."
    << "You must continue without him." << endl;
    
}

void Function::npcTalk(Inventory &theInventory,vector<Player> &crew, Monster theMonster)
{
    bool menuout=true;
    int probability=  rand() % 100;
    int userchoice;
    
    cout<<"> You have encountered a mysterious person in the room. They are giving you a puzzle to solve!"<<endl;
    if(probability>=0&&probability<=33)
    {
        cout<<"> Watch Out! The mysterious person is an enemy! Prepare for a battle!"<<endl;
        cout<<"> " << theMonster.getMonsterName() << " AHEAD! THEY LOOK HOSTILE!" <<endl;
        cout<<"Lvl: "<<theMonster.getLevel()<<endl;  
        if(theInventory.getWeaponsCombined()>0&&theInventory.getArmor()>0){
            while(menuout==true)
            {
                cout<<"1: Fight!"<<endl;
                cout<<"2: Surrender!"<<endl;
                cin>>userchoice;
                
                if(userchoice==1)
                {
                    combat(theInventory,theMonster,crew);
                    menuout=false;
                }
                else if(userchoice==2)
                {
                    brokenAccessary(theInventory);
                    menuout=false;
                }
                else
                {
                    cout<<"> Invalid input. Please enter 1 or 2"<<endl;
                }
            }
        }
        else
        {
            while(menuout==true)
            {
                cout<<"> You dont have enough weapons or armors to fight!"<<endl;
                cout<<"1: Surrender!"<<endl;
                cin>>userchoice;
                if(userchoice==1)
                {
                    surrender(crew);
                    menuout=false;
                }
                else
                {
                    cout<<"> Invalid input. Please enter 1"<<endl;
                }
            }

        }  
    }
        
    else if(probability>33&&probability<=66)
    {
        bool puzzle = npcPuzzle();
        if(puzzle == true)
        {
        cout<<"> WOW! The person was a merchant! He is happy that you solved the puzzle! He opens his store for you!"<<endl;
        merchantMenu(theInventory);
        }
        else
        {
            cout<<"The person was a merchant. Since you didn't solved the puzzle, he will not open the store"<<endl;
        }



    }
    else if(probability>66&&probability<=99)
    {
        npcPuzzle();
        cout<<"It seems like this person just wanted to have some fun. Sadly thats everything they can offer"<<endl;
    }
}
void Function::rpsDoor(Inventory& inven, vector<Player>& players)
{
    srand(time(NULL));
    int userchoice;
    
    bool tie=true;
    int machinechoice=rand() % 3 + 1;
    cout<<"To escape from the door you need to win a game of Rock Paper Sissor" << endl;
    while(tie==true)
    {
        cout<<"Please select an option"<<endl;
        cout<<"1: Rock  2: Paper  3: Sissor"<<endl;   
        cin>>userchoice;
        machinechoice=rand() % 3 + 1;
        if(userchoice==1&&machinechoice==3||userchoice==2&&machinechoice==1||userchoice==3&&machinechoice==2)
        {
            cout<<"You win! You can continue your adventure!"<<endl;
            tie=false;
        }
        else if(userchoice==1&&machinechoice==2||userchoice==2&&machinechoice==3||userchoice==3&&machinechoice==1)
        {
            cout<<"Oh no! you have lost, The adventure ends here..."<<endl;
            quitGame(inven, players);
            tie=false;
        }
        else if(userchoice==1&&machinechoice==1||userchoice==2&&machinechoice==2||userchoice==3&&machinechoice==3)
        {
            cout<<"There is a Tie! Try again!"<<endl;
            tie=true;
        }
    }
}

bool Function::npcPuzzle()
{
    cout<<"You need to guess the number I'm thinking between 1-10 to get away"<<endl;
    int machinechoice=rand() % 10 + 1;
    int chances=2;
    int userchoice;
    bool solved = false;
    while(chances!=0)
    {
        cout<<"> Please enter a number"<<endl;
        cin>>userchoice;
        if(userchoice==machinechoice)
        {
            solved = true;
        }
        else if(userchoice<machinechoice)
        {
            chances--;
            cout<<"Your number is lower than mine You have "<<chances<<" chances left"<<endl;
            if(chances==0)
            {
                cout<<"sorry You didn't solve the puzzle"<<endl;
            }
        }
        else if(userchoice>machinechoice)
        {
            chances--;
            cout<<"Your number is greater than mine You have "<<chances<<" chances left"<<endl;
            if(chances==0)
            {
                cout<<"sorry You didn't solve the puzzle"<<endl;
            }
        }
    }
    return solved;
}

// test run
// int main()
// {
//     
//     Inventory inven;

//     inven.setGold(100);

//     // merchantMenu(inven);

//     readMonsterFile();
//     readRoomFile();
//     // for (int i = 0; i < 20; i++)
//     // {
//     //     cout << getMonster(i).getMonsterName() << endl;
//     //     cout << getMonster(i).getLevel() << endl;
//     // }
//     // for (int i = 0; i < 5; i++)
//     // {
//     //     cout << getRoom(i).getRoomName() << endl;
//     //     cout << getRoom(i).getGemRoom() << endl;
//     //     cout << getRoom(i).getTreasureRoom() << endl;
//     //     cout << getRoom(i).getGoldRoom() << endl;
//     // }

//     Player p1, p2, p3, p4, p5; 
//     p1.setName("p1");
//     p2.setName("p2");
//     p3.setName("p3");
//     p4.setName("p4");
//     p5.setName("p5");
//     p1.setMainPlayer(true);
//     vector<Player> crew{p1, p2, p3, p4, p5};

//     Monster beast = getMonster(1);
//     combat(inven, beast, crew);
// }