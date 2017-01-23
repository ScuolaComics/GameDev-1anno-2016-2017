//
//  Deck.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "Deck.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

Deck::Deck()
{
    _cards.reserve(52);
    this->populate();
    this->shuffle();
}

Deck::~Deck()
{}

void Deck::populate()
{
    this->clear();
    
    for (int suit = Card::Suit::CLUBS; suit <= Card::Suit::SPADES; suit++)
    {
        for (int rank = Card::Rank::ACE; rank <= Card::Rank::KING; rank++)
        {
            this->addCard(new Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle(_cards.begin(), _cards.end());
}

void Deck::deal(Hand& hand)
{
    if (!_cards.empty())
    {
        hand.addCard(_cards.back());
        _cards.pop_back();
    }
    else
    {
        cout << "Out of cards! Unable to deal.";
    }
}

void Deck::additionalCards(GenericPlayer& genericPlayer)
{
    cout << endl;
    genericPlayer.printStatus();
    
    while (!genericPlayer.isBusted() && genericPlayer.isHitting())
    {
        this->deal(genericPlayer);
        genericPlayer.printStatus();
        
        if (genericPlayer.isBusted())
        {
            genericPlayer.bust();
        }
    }
}
