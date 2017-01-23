//
//  Hand.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include "Card.hpp"
#include <vector>

using namespace std;

class Hand
{
public:
    
    virtual ~Hand();
    
    // Aggiunge una carta alla mano
    void addCard(Card * card);
    
    // Rimuove tutte le carte dalla mano
    void clear();
    
    // Restituisce il valore totale della mano, trattando gli assi come 1 e 11 a seconda della situazione
    int getTotal() const;
    
protected:
    
    vector<Card *> _cards;
};

#endif /* Hand_hpp */
