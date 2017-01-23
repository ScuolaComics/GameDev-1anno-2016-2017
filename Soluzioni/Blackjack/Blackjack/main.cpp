//
//  main.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "\t\t Welcome to Blackjack!\n\n";
    
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1-7): ";
        cin >> numPlayers;
    }
    
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;
    
    // Game Loop
    Game game(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        game.playRound();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }
    
    return 0;
}
