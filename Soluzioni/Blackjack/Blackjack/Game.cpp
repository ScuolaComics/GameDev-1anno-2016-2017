//
//  Game.cpp
//  Blackjack
//
//  Created by Leonardo Passeri on 19/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include "Game.hpp"
#include <ctime>
#include <cstdlib>

Game::Game(vector<string> playerNames)
: _house("House")
{
    for (int i = 0; i < playerNames.size(); i++)
    {
        _players.push_back(Player(playerNames[i]));
    }
    
    srand(static_cast<unsigned int>(time(0)));
}

Game::~Game()
{}

void Game::playRound()
{
    // Preparo il mazzo
    _deck.populate();
    _deck.shuffle();
    
    vector<Player>::iterator playerIterator;
    
    // Assegno due carte a tutti i giocatori e al banco
    for (int i = 0; i < 2; i++)
    {
        for (playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
        {
            _deck.deal(*playerIterator);
        }
        _deck.deal(_house);
    }
    
    // Copro la prima carta del banco
    _house.flipFirstCard();
    
    // Mostro le carte di tutti
    for (playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
    {
        (*playerIterator).printStatus();
    }
    _house.printStatus();
    
    // Dai le carte addizionali ai giocatori
    for (playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
    {
        _deck.additionalCards(*playerIterator);
    }
    
    // Mostro la prima carta del banco
    _house.flipFirstCard();
    
    // Dai le carte addizionali al banco
    _deck.additionalCards(_house);
    
    //
    // Determino l'esito del round
    //
    
    // Se il banco ha sballato
    if (_house.isBusted())
    {
        // Allora tutti i giocatori che non hanno sballato vincono
        for (playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
        {
            if (!playerIterator->isBusted())
            {
                playerIterator->win();
            }
        }
    }
    else // Altrimenti
    {
        for (playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
        {
            if (!playerIterator->isBusted())
            {
                // I giocatori che hanno un punteggio più alto del banco vincono
                if (playerIterator->getTotal() > _house.getTotal())
                {
                    playerIterator->win();
                }
                // I giocatori che hanno un punteggio più basso del banco perdono
                else if (playerIterator->getTotal() < _house.getTotal())
                {
                    playerIterator->lose();
                }
                // I giocatori che hanno lo stesso punteggio del banco pareggiano
                else
                {
                    playerIterator->push();
                }
                
            }
        }
    }
    
    // Rimuovo tutte le carte dal banco e dai giocatori
    for (playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
    {
        playerIterator->clear();
    }
    _house.clear();
}









