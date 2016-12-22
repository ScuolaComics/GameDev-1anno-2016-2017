//
//  main.cpp
//  TigerTank
//
//  Created by Leonardo Passeri on 08/01/16.
//  Copyright © 2016 Ever Dream. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Tank.hpp"

using namespace std;

#define TANK_NUM 5
#define BRAVERY_GOAL 100

#define PATROL_MISSION_GAIN 1
#define ATTACK_MISSION_GAIN 2
#define REST_MISSION_COST 1
#define ENGINE_UPGRADE_COST 10
#define ARMOR_UPGRADE_COST 20
#define SHELL_UPGRADE_COST 30

void patrolMission(std::vector<Tank>& tanks, int& bravery);
void attackMission(std::vector<Tank>& tanks, int& bravery);
void restMission(std::vector<Tank>& tanks, int& bravery);
void purchaseEngineUpgrade(std::vector<Tank>& tanks, int& bravery);
void purchaseArmorUpgrade(std::vector<Tank>& tanks, int& bravery);
void purchaseShellUpgrade(std::vector<Tank>& tanks, int& bravery);
void printStatusTeam(std::vector<Tank>& tanks, int& bravery);
int getAliveTanks(std::vector<Tank>& tanks);

int main(int argc, const char * argv[])
{    
    std::cout << "Tiger Tank!\n\n";
    
    srand(static_cast<unsigned int>(time(0)));
    
    std::vector<Tank> tanks;
    
    for (int i = 0; i < TANK_NUM; i++)
    {
        tanks.push_back(Tank());
    }
    
    int aliveTanks = (int)tanks.size();
    
    int bravery = 0;
    int choice = -1;
    
    do
    {
        printStatusTeam(tanks, bravery);
        
        cout << "\nSelect your daily mission\n\n";
        cout << "1 - Patrol\n";
        cout << "2 - Attack enemy outpost\n";
        cout << "3 - Repair and refuel\n";
        cout << "4 - Purchase Engine Upgrade (cost " << ENGINE_UPGRADE_COST << " Bravery, halved fuel loss)\n";
        cout << "5 - Purchase Armor Upgrade (cost " << ARMOR_UPGRADE_COST << " Bravery, halved health loss)\n";
        cout << "6 - Purchase Shell Upgrade (cost " << SHELL_UPGRADE_COST << " Bravery, doubled Bravery gain)\n\n";
        
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                patrolMission(tanks, bravery);
                break;
            case 2:
                attackMission(tanks, bravery);
                break;
            case 3:
                restMission(tanks, bravery);
                break;
            case 4:
                purchaseEngineUpgrade(tanks, bravery);
                break;
            case 5:
                purchaseArmorUpgrade(tanks, bravery);
                break;
            case 6:
                purchaseShellUpgrade(tanks, bravery);
                break;
            default:
                cout << "\nNo available mission for " << choice;
                break;
        }
        aliveTanks = getAliveTanks(tanks);
    }
    while (aliveTanks != 0 && bravery < BRAVERY_GOAL);
    
    printStatusTeam(tanks, bravery);
    
    if (aliveTanks == 0)
    {
        cout << "All your tanks have been destroyed. Better luck next war... ;)" << endl;
    }
    else
    {
        cout << "You are a true hero! Congratulations, General..." << endl;
    }
    
    return 0;
}

void patrolMission(std::vector<Tank>& tanks, int& bravery)
{
    for (int i = 0; i < tanks.size(); i++)
    {
        Tank& tank = tanks[i];
        if (!tank.isDestroyed())
        {
            int distance = 2 + (rand() % 3);
            tank.patrol(distance);
            bravery += (PATROL_MISSION_GAIN * ((tank.hasUpgrade(SHELL)) ? 2 : 1));
        }
    }
}

void attackMission(std::vector<Tank>& tanks, int& bravery)
{
    for (int i = 0; i < tanks.size(); i++)
    {
        Tank& tank = tanks[i];
        if (!tank.isDestroyed())
        {
            int enemyStrength = 2 + (rand() % 3);
            tank.attack(enemyStrength);
            bravery += (ATTACK_MISSION_GAIN * ((tank.hasUpgrade(SHELL)) ? 2 : 1));
        }
    }
}

void restMission(std::vector<Tank>& tanks, int& bravery)
{
    for (int i = 0; i < tanks.size(); i++)
    {
        Tank& tank = tanks[i];
        if (!tank.isDestroyed())
        {
            int supplies = 2 + (rand() % 3);
            tank.rest(supplies);
            bravery -= REST_MISSION_COST;
        }
    }
}

void printStatusTeam(std::vector<Tank>& tanks, int& bravery)
{
    for (int i = 0; i < tanks.size(); i++)
    {
        cout << "Tank " << (i+1) << ": ";
        tanks[i].printStatus();
        cout << endl;
    }
    cout << "Current Bravery: " << bravery << endl;
}

void purchaseEngineUpgrade(std::vector<Tank>& tanks, int& bravery)
{
    if (bravery >= ENGINE_UPGRADE_COST)
    {
        int i = 0;
        bool purchaseDone = false;
        while (!purchaseDone && i < tanks.size())
        {
            Tank& tank = tanks[i];
            if (!tank.isDestroyed() && !tank.hasUpgrade(ENGINE))
            {
                bravery -= ENGINE_UPGRADE_COST;
                tank.purchaseUpgrade(ENGINE);
                purchaseDone = true;
            }
            i++;
        }
        if (!purchaseDone)
        {
            cout << "No more tanks to upgrade" << endl;
        }
    }
    else
    {
        cout << "Not enough Bravery!" << endl;
    }
}

void purchaseArmorUpgrade(std::vector<Tank>& tanks, int& bravery)
{
    if (bravery >= ARMOR_UPGRADE_COST)
    {
        int i = 0;
        bool purchaseDone = false;
        while (!purchaseDone && i < tanks.size())
        {
            Tank& tank = tanks[i];
            if (!tank.isDestroyed() && !tank.hasUpgrade(ARMOR))
            {
                bravery -= ARMOR_UPGRADE_COST;
                tank.purchaseUpgrade(ARMOR);
                purchaseDone = true;
            }
            i++;
        }
        if (!purchaseDone)
        {
            cout << "No more tanks to upgrade" << endl;
        }
    }
    else
    {
        cout << "Not enough Bravery!" << endl;
    }
}

void purchaseShellUpgrade(std::vector<Tank>& tanks, int& bravery)
{
    if (bravery >= SHELL_UPGRADE_COST)
    {
        int i = 0;
        bool purchaseDone = false;
        while (!purchaseDone && i < tanks.size())
        {
            Tank& tank = tanks[i];
            if (!tank.isDestroyed() && !tank.hasUpgrade(SHELL))
            {
                bravery -= SHELL_UPGRADE_COST;
                tank.purchaseUpgrade(SHELL);
                purchaseDone = true;
            }
            i++;
        }
        if (!purchaseDone)
        {
            cout << "No more tanks to upgrade" << endl;
        }
    }
    else
    {
        cout << "Not enough Bravery!" << endl;
    }
}

int getAliveTanks(std::vector<Tank>& tanks)
{
    int aliveTanks = 0;
    for (int i = 0; i < tanks.size(); i++)
    {
        if (!tanks[i].isDestroyed())
        {
            aliveTanks++;
        }
    }
    return aliveTanks;
}
