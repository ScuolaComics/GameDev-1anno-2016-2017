//
//  Hand.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "Hand.hpp"

Hand::~Hand()
{
    this->clear();
}

void Hand::addCard(Card *card)
{
    _cards.push_back(card);
}

void Hand::clear()
{
    vector<Card *>::iterator cardIterator;
    for (cardIterator = _cards.begin(); cardIterator != _cards.end(); cardIterator++)
    {
        delete *cardIterator;
        *cardIterator = nullptr;
    }
    _cards.clear();
}

int Hand::getTotal() const
{
    if (_cards.empty())
    {
        return 0;
    }
    
    if (_cards[0]->getValue() == 0)
    {
        return 0;
    }
    
    int total = 0;
    
    vector<Card *>::const_iterator cardIterator;
    for (cardIterator = _cards.begin(); cardIterator != _cards.end(); cardIterator++)
    {
        total += (*cardIterator)->getValue();
    }
    
    bool containAce = false;
    for (cardIterator = _cards.begin(); cardIterator != _cards.end(); cardIterator++)
    {
        if ((*cardIterator)->getValue() == Card::ACE)
        {
            containAce = true;
        }
    }
    
    if (containAce && total <= 11)
    {
        total += 10;
    }
    
    return total;
}
