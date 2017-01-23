//
//  House.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "House.hpp"
#include <iostream>

House::House(string name)
: GenericPlayer(name)
{
    // TODO
}

House::~House()
{
    // TODO
}

bool House::isHitting() const
{
    return (getTotal() <= 16);
}

void House::flipFirstCard()
{
    if (!_cards.empty())
    {
        _cards[0]->flip();
    }
    else
    {
        std::cout << "No cards to flip!\n";
    }
}
