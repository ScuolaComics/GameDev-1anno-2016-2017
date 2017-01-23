//
//  Card.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "Card.hpp"
#include <string>
#include <iostream>

using namespace std;

Card::Card(Rank rank, Suit suit, bool isFaceUp)
: _rank(rank)
, _suit(suit)
, _isFaceUp(isFaceUp)
{}

int Card::getValue() const
{
    int value = 0;
    
    if (_isFaceUp)
    {
        value = _rank;
        
        if (value > 10)
        {
            value = 10;
        }
    }
    
    return value;
}

void Card::flip()
{
    _isFaceUp = !_isFaceUp;
}

void Card::printCard()
{
    const string RANKS[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    const string SUITS[] = {"C", "D", "H", "S"};
    
    if (_isFaceUp)
    {
        cout << RANKS[_rank] << SUITS[_suit];
    }
    else
    {
        cout << "XX";
    }
}
