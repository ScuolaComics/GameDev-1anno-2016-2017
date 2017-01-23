//
//  GenericPlayer.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef GenericPlayer_hpp
#define GenericPlayer_hpp

#include "Hand.hpp"
#include <string>

using namespace std;

class GenericPlayer : public Hand
{
public:
    
    GenericPlayer(string name);
    
    virtual ~GenericPlayer();
    
    // restituisce se il giocatore generico continua o meno a prendere carte
    virtual bool isHitting() const = 0;
    
    // restituisce se il giocatore ha sballato o meno
    bool isBusted() const;
    
    // annuncia che il giocatore ha sballato
    void bust() const;
    
    void printStatus() const;
    
protected:
    
    string _name;
};

#endif /* GenericPlayer_hpp */
