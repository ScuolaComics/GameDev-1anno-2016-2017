//
//  Player.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "GenericPlayer.hpp"

class Player : public GenericPlayer
{
public:
    Player(string name);
    
    virtual ~Player();
    
    bool isHitting() const override;
    void win() const;
    void lose() const;
    void push() const;
};

#endif /* Player_hpp */
