//
//  Tank.cpp
//  TigerTank
//
//  Created by Leonardo Passeri on 08/01/16.
//  Copyright © 2016 Ever Dream. All rights reserved.
//

#include "Tank.hpp"
#include <iostream>

#define MAX_HEALTH 100
#define MAX_FUEL 100
#define MAX_AMMO 100

using namespace std;

Tank::Tank(int health, int fuel, int ammo)
{
    if (health > MAX_HEALTH)
    {
        health = MAX_HEALTH;
    }
    _health = health;
    
    if (fuel > MAX_FUEL)
    {
        fuel = MAX_FUEL;
    }
    _fuel = fuel;
    
    if (ammo > MAX_AMMO)
    {
        ammo = MAX_AMMO;
    }
    _ammo = ammo;
    
    _upgrades = 0;
}

void Tank::patrol(int distance)
{
    if (!isDestroyed())
    {
        this->decreaseHealth(distance * 2);
        this->decreaseFuel(distance * 8);
        this->decreaseAmmo(distance * 2);
    }
}

void Tank::attack(int enemyStrength)
{
    if (!isDestroyed())
    {
        this->decreaseHealth(enemyStrength * 7);
        this->decreaseFuel(enemyStrength * 3);
        this->decreaseAmmo(enemyStrength * 7);
    }
}

void Tank::rest(int supplies)
{
    if (!isDestroyed())
    {
        _health += (supplies * 5);
        if (_health > MAX_HEALTH)
        {
            _health = MAX_HEALTH;
        }
        
        _fuel += (supplies * 5);
        if (_fuel > MAX_FUEL)
        {
            _fuel = MAX_FUEL;
        }
        
        _ammo += (supplies * 5);
        if (_ammo > MAX_AMMO)
        {
            _ammo = MAX_AMMO;
        }
    }
}

bool Tank::isDestroyed() const
{
    return (_health <= 0 || _fuel <= 0 || _ammo <= 0);
}

void Tank::printStatus()
{
    if (!isDestroyed())
    {
        cout << "health: " << _health << ", fuel: " << _fuel << ", ammo: " <<  _ammo;
        cout << ", upgrades: ";
        cout << ((this->hasUpgrade(ENGINE)) ? "E" : "");
        cout << ((this->hasUpgrade(ARMOR)) ? "A" : "");
        cout << ((this->hasUpgrade(SHELL)) ? "S" : "");
    }
    else
    {
        cout << "destroyed...";
    }
    
}

bool Tank::hasUpgrade(eTankUpgrade tankUpgrade)
{
    return (_upgrades & tankUpgrade);
}

void Tank::purchaseUpgrade(eTankUpgrade tankUpgrade)
{
    _upgrades |= tankUpgrade;
}

void Tank::decreaseFuel(int decrease)
{
    _fuel -= (this->hasUpgrade(ENGINE)) ? decrease / 2 : decrease;
}

void Tank::decreaseHealth(int decrease)
{
    _health -= (this->hasUpgrade(ARMOR)) ? decrease / 2 : decrease;
}

void Tank::decreaseAmmo(int decrease)
{
    _ammo -= decrease;
}
