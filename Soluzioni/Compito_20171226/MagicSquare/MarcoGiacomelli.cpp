//
//  main.cpp
//  MagicSquareMarcoGiacomelli
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>
using namespace std;
const int R = 3;

int MATRICE[3][3]; // Hai definito R e poi non lo usi ?

void ACQUISISCI(int R)
{
    int c;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            std::cout << "INSERIRE UN NUMERO:";
            std::cin >> c; std::cout << std::endl;
            MATRICE[i][j] = c;
        }
    }
}

bool VERIFICA(int R)
{
    // Da qui a RINUNCIO non capisco cosa tu voglia fare...
    bool VALID = false; // Variabile non usata
    // usare una sola lettera come nome di variabile peggiora la leggibilità
    int c; int d; int a; int b; c = 0; b = 0; // "d" non viene usato
    
    for (int i = 0; i < R; i++)
    {
        a = 0;
        // Errore - Sintassi errata + variabile non dichiarata (j)
//        c += MATRICE[i,j];
        if (b != a)
        {
            return false;
        }
        for (int j = 0; j < R; j++)
        {
            // Errore - Sintassi errata
            a += MATRICE[i][j]; // Versione Prof
//            a += MATRICE[i,j]; // Versione Marco
        }
        b = a;
    } // Errore - Parentesi chiusa mancante
    
    // RINUNCIO <- ????
    
    // Errore - l'algoritmo doveva valere per matrici quadrate di qualsiasi dimensione, non solo 3x3
    int r1 = MATRICE[0][1] + MATRICE[0][2] + MATRICE[0][0];
    int r2 = MATRICE[1][0] + MATRICE[1][1] + MATRICE[1][2];
    int r3 = MATRICE[2][0] + MATRICE[2][1] + MATRICE[2][2];
    int c1 = MATRICE[0][0] + MATRICE[1][0] + MATRICE[2][0];
    int c2 = MATRICE[0][1] + MATRICE[1][1] + MATRICE[2][1];
    int c3 = MATRICE[0][2] + MATRICE[1][2] + MATRICE[2][2];
    int d1 = MATRICE[0][0] + MATRICE[1][1] + MATRICE[2][2];
    int d2 = MATRICE[2][0] + MATRICE[1][1] + MATRICE[0][2];
    
    if (r1 == r2 && r1 == r3 && r1 == c1 && r1 == c2 && r1 == c3 && r1 == d1 && r1 == d2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, const char * argv[])
{
    ACQUISISCI(R);
    bool b = VERIFICA(R);
    // Errore: operatore >> usato al posto di <<
    cout << b << endl; // Versione Prof
//    cout >> b >> endl; // Versione Marco
    return 0;
}
