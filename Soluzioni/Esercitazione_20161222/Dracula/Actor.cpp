//
//  Actor.cpp
//  Dracula
//
//  Created by Leonardo Passeri on 21/12/2016.
//  Copyright © 2016 Balzo. All rights reserved.
//

#include "Actor.hpp"
#include <iostream>

using namespace std;

Actor::Actor(int health, int will, int attack, int intimidation)
: _currentHealth(health)
, _maxHealth(health)
, _currentWill(will)
, _maxWill(will)
, _attack(attack)
, _intimidation(intimidation)
{}

void Actor::attack(Actor& target)
{
    if (!isKilled())
    {
        int damage = _attack + rand() % 6;
        target.takeHealthDamage(damage);
    }
}

void Actor::scare(Actor& target)
{
    if (!isKilled())
    {
        int damage = _intimidation + rand() % 6;
        target.takeWillDamage(damage);
    }
}

void Actor::takeHealthDamage(int damage)
{
    if (!isKilled())
    {
        _currentHealth -= damage;
    }
}

void Actor::takeWillDamage(int damage)
{
    if (!isKilled())
    {
        _currentWill -= damage;
    }
}

void Actor::rest()
{
    if (!isKilled())
    {
        _currentHealth += (rand() % 6 + 5);
        
        if (_currentHealth > _maxHealth)
        {
            _currentHealth = _maxHealth;
        }
        
        _currentWill += (rand() % 6 + 5);
        
        if (_currentWill > _maxWill)
        {
            _currentWill = _maxWill;
        }
    }
}

bool Actor::isKilled() const
{
    return (_currentWill <= 0 || _currentHealth <= 0);
}

void Actor::printStatus() const
{
    if (!isKilled())
    {
        cout << "health: " << _currentHealth << ", will: " << _currentWill;
    }
    else
    {
        cout << "killed...";
    }
}
