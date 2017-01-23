//
//  Player.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player(string name)
: GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::isHitting() const
{
    cout << _name << ", do you want to hit? (y/n): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << _name << " win!" << endl;
}

void Player::lose() const
{
    cout << _name << " loses..." << endl;
}

void Player::push() const
{
    cout << _name << " pushes." << endl;
}
