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

void patrolMission(std::vector<Tank>& tanks, int& bravery);
void attackMission(std::vector<Tank>& tanks, int& bravery);
void restMission(std::vector<Tank>& tanks, int& bravery);
void printStatusTeam(std::vector<Tank>& tanks, int& bravery);
int getAliveTanks(std::vector<Tank>& tanks);

int main(int argc, const char * argv[]) {
    // insert code here...
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
        cout << "3 - Repair and refuel\n\n";
        
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
            bravery += 1;
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
            bravery += 2;
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
        }
    }
    bravery -= 5;
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
