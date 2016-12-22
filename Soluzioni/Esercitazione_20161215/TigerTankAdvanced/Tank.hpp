//
//  Tank.hpp
//  TigerTank
//
//  Created by Leonardo Passeri on 08/01/16.
//  Copyright © 2016 Ever Dream. All rights reserved.
//

#ifndef Tank_hpp
#define Tank_hpp

enum eTankUpgrade
{
    ENGINE = 1 << 0,
    ARMOR = 1 << 1,
    SHELL = 1 << 2
};

class Tank
{
public:
    
    Tank(int health = 100, int fuel = 100, int ammo = 100);
    void patrol(int distance);
    void attack(int enemyStrength);
    void rest(int supplies);
    bool isDestroyed() const;
    void printStatus();
    bool hasUpgrade(eTankUpgrade tankUpgrade);
    void purchaseUpgrade(eTankUpgrade tankUpgrade);
    
private:
    
    int _health;
    int _fuel;
    int _ammo;
    
    int _upgrades;
    
    void decreaseFuel(int decrease);
    void decreaseHealth(int decrease);
    void decreaseAmmo(int decrease);
};

#endif /* Tank_hpp */
