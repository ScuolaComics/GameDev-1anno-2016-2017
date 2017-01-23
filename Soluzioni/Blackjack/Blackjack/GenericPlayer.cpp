//
//  GenericPlayer.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "GenericPlayer.hpp"
#include <iostream>

using namespace std;

GenericPlayer::GenericPlayer(string name)
: _name(name)
{
    
}

GenericPlayer::~GenericPlayer()
{
    
}

bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}

void GenericPlayer::bust() const
{
    cout << _name << " busts..." << endl;
}

void GenericPlayer::printStatus() const
{
    cout << _name << ":";
    for (int i = 0; i < _cards.size(); i++)
    {
        cout << "\t";
        _cards[i]->printCard();
    }
    cout << "\t" << getTotal();
    cout << endl;
}

