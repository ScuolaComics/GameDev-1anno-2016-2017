//
//  Actor.hpp
//  Dracula
//
//  Created by Leonardo Passeri on 21/12/2016.
//  Copyright © 2016 Balzo. All rights reserved.
//

#ifndef Actor_hpp
#define Actor_hpp

class Actor
{
public:
    
    Actor(int health, int will, int attack, int intimidation);
    void scare(Actor& target);
    void attack(Actor& target);
    void rest();
    void takeHealthDamage(int damage);
    void takeWillDamage(int damage);
    bool isKilled() const;
    void printStatus() const;
    
private:
    
    int _currentHealth;
    int _maxHealth;
    int _currentWill;
    int _maxWill;
    int _attack;
    int _intimidation;
};

#endif /* Actor_hpp */
