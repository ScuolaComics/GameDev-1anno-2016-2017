//
//  Card.hpp
//  Blackjack
//
//  Created by Leonardo Passeri on 12/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

class Card
{
public:
    
    enum Rank
    {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };
    
    enum Suit
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    
    Card(Rank rank, Suit suit, bool isFaceUp = true);
    
    // Ritorna il valore della carta. L'asso varrà 1.
    int getValue() const;
    
    // Gira una carta. Se era coperta diventa scoperta e vice versa.
    void flip();
    
    void printCard();
    
private:
    
    Rank _rank;
    Suit _suit;
    bool _isFaceUp;
    
};

#endif /* Card_hpp */
