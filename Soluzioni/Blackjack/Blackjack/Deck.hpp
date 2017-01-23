//
//  Deck.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Hand.hpp"
#include "GenericPlayer.hpp"

class Deck : public Hand
{
public:
    Deck();
    
    virtual ~Deck();
    
    void populate();
    
    void shuffle();
    
    void deal(Hand& hand);
    
    void additionalCards(GenericPlayer& genericPlayer);
};

#endif /* Deck_hpp */
