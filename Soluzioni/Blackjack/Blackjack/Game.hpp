//
//  Game.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <vector>
#include <string>
#include "Deck.hpp"
#include "House.hpp"
#include "Player.hpp"

using namespace std;

class Game
{
public:
    
    Game(vector<string> playerNames);
    
    ~Game();
    
    void playRound();
    
private:
    
    Deck _deck;
    House _house;
    vector<Player> _players;
    
};

#endif /* Game_hpp */
