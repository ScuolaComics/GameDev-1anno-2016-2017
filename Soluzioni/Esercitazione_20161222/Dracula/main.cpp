//
//  main.cpp
//  Dracula
//
//  Created by Leonardo Passeri on 21/12/2016.
//  Copyright © 2016 Balzo. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Actor.hpp"

bool proceed(Actor& player, int& currentBossChance);

void rest(Actor& player);

bool bossFound(int currentBossChance);

void generateEnemies(std::vector<Actor>& enemies);

void playNormalEncounter(Actor& player);

void playBossEncounter(Actor& player);

void playEncounter(Actor& player, std::vector<Actor>& enemies);

bool checkEnemiesAlive(std::vector<Actor>& enemies);

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    
    int currentBossChance = 0;
    Actor player(100, 100, 10, 10);
    bool gameWon = false;;
    int choice = -1;
    
    std::cout << "Caccia a Dracula!";
    
    while (!player.isKilled() && !gameWon)
    {
        std::cout << "\n\nVan Helsing: ";
        player.printStatus();
        
        std::cout << "\nVan Helsing, qual è la tua prossima mossa?\n\n";
        std::cout << "1 - Proseguo\n";
        std::cout << "2 - Riposo\n";
        
        std::cout << "Choice: ";
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
                gameWon = proceed(player, currentBossChance);
                break;
            case 2:
                rest(player);
                break;
            default:
                std::cout << "\nMossa non disponibile " << choice;
                break;
        }
    }
    
    if (player.isKilled())
    {
        std::cout << "\n\nVan Helsing è morto... Dracula festeggia una nuova era di terrore";
    }
    else if (gameWon)
    {
        std::cout << "\n\nHai ucciso Dracula! Ma non vantartene a giro... ti prenderebbero per pazzo...";
    }
    
    return 0;
}

bool proceed(Actor& player, int& currentBossChance)
{
    bool bossDefeated = false;
    if (bossFound(currentBossChance))
    {
        playBossEncounter(player);
        if (!player.isKilled())
        {
            bossDefeated = true;
        }
    }
    else
    {
        playNormalEncounter(player);
        currentBossChance += 10;
    }
    return bossDefeated;
}

void rest(Actor& player)
{
    if (rand() % 100 < 30)
    {
        playNormalEncounter(player);
    }
    else
    {
        player.rest();
    }
}

bool bossFound(int currentBossChance)
{
    return rand() % 100 < currentBossChance;
}

void generateEnemies(std::vector<Actor>& enemies)
{
    int randomValue = rand() % 100;
    if (randomValue < 50)
    {
        // Gruppo di servitori
        int health = 12;
        int will = 30;
        int attack = 12;
        int intimidation = 10;
        
        for (int i = 0; i < 3; i++)
        {
            enemies.push_back(Actor(health, will, attack, intimidation));
        }
    }
    else
    {
        // Gruppo di spettri
        int health = 100;
        int will = 12;
        int attack = 2;
        int intimidation = 20;
        
        for (int i = 0; i < 3; i++)
        {
            enemies.push_back(Actor(health, will, attack, intimidation));
        }
    }
}

void playNormalEncounter(Actor& player)
{
    std::cout << "Nemici incontrati\n";
    
    std::vector<Actor> enemies;
    
    generateEnemies(enemies);
    
    playEncounter(player, enemies);
    
    if (!player.isKilled())
    {
        std::cout << "Nemici sconfitti\n";
    }
}

void playBossEncounter(Actor& player)
{
    std::cout << "Hai trovato Dracula! L'epico scontro ha inizio...\n";
    
    std::vector<Actor> enemies;
    Actor boss(50, 50, 20, 20);
    
    enemies.push_back(boss);
    
    playEncounter(player, enemies);
}

void playEncounter(Actor& player, std::vector<Actor>& enemies)
{
    while (checkEnemiesAlive(enemies) && !player.isKilled())
    {
        std::cout << "\n\nVan Helsing: ";
        player.printStatus();
        
        for (int i = 0; i < enemies.size(); i++)
        {
            std::cout << "\nNemico " << i << ": ";
            enemies[i].printStatus();
        }
        
        bool validChoice = false;
        
        while (!validChoice)
        {
            // Turno giocatore
            int choice = -1;
            
            std::cout << "\n1 - Attacca";
            std::cout << "\n2 - Intimidisci";
            
            std::cout << "\nChoice: ";
            std::cin >> choice;
            
            switch (choice)
            {
                case 1:
                    for (int i = 0; i < enemies.size(); i++)
                    {
                        player.attack(enemies[i]);
                    }
                    validChoice = true;
                    break;
                case 2:
                    for (int i = 0; i < enemies.size(); i++)
                    {
                        player.scare(enemies[i]);
                    }
                    validChoice = true;
                    break;
                default:
                    std::cout << "\nMossa non disponibile " << choice;
                    break;
            }
        }
        
        // Turno nemici
        for (int i = 0; i < enemies.size(); i++)
        {
            if (rand() % 100 < 50)
            {
                enemies[i].attack(player);
            }
            else
            {
                enemies[i].scare(player);
            }
        }
    }
}

bool checkEnemiesAlive(std::vector<Actor>& enemies)
{
    int enemiesAlive = 0;
    for (int i = 0; i < enemies.size(); i++)
    {
        if (!enemies[i].isKilled())
        {
            enemiesAlive++;
        }
    }
    return (enemiesAlive > 0);
}




