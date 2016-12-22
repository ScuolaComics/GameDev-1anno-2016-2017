//
//  Tank.hpp
//  TigerTank
//
//  Created by Leonardo Passeri on 08/01/16.
//  Copyright © 2016 Ever Dream. All rights reserved.
//

#ifndef Tank_hpp
#define Tank_hpp

class Tank
{
public:
    
    Tank(int health = 100, int fuel = 100, int ammo = 100);
    void patrol(int distance);
    void attack(int enemyStrength);
    void rest(int supplies);
    bool isDestroyed() const;
    void printStatus() const;
    
private:
    
    int _health;
    int _fuel;
    int _ammo;
};

#endif /* Tank_hpp */
