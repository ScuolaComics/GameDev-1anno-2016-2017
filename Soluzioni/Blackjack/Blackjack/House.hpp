//
//  House.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef House_hpp
#define House_hpp

#include "GenericPlayer.hpp"

class House : public GenericPlayer
{
public:
    
    House(string name);
    
    virtual ~House();
    
    bool isHitting() const override;
    
    void flipFirstCard();
    
};

#endif /* House_hpp */
