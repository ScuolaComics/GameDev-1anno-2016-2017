//
//  main.cpp
//  MagicSquareEmanuelePacini
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>

void Popola();
int Verifica();

#define R 3
int A[R][R];

using namespace std;

int main(int argc, const char * argv[])
{
    Popola();
    
    if (Verifica() == 1)
    {
        cout << "La matrice e' un quadrato magico" << endl;
    }
    else
    {
        cout << "La matrice non e' un quadrato magico" << endl;
    }
    
    return 0;
}

void Popola()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cout << "Inserisci dato" << endl;
            cin >> A[i][j];
        }
    }
}

int Verifica()
{
    int ver[(R * 2) + 2];
    
    // inizializzo a 0
    for (int i = 0; i < (R * 2) + 2; i++)
    {
        ver[i] = 0;
    }
    // sommo le righe e metto la somma in ogni spazio di ver
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            ver[i] += A[i][j];
        }
    }
    // stessa cosa di prima con le colonne
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            ver[i + R] += A[i][j];
        }
    }
    // sommo la prima diagonale
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (i == j)
            {
                // Errore - indice sbagliato
                ver[R * 2] += A[i][j]; // Versione Prof
//                ver[R * 2 + 1] += A[i][j]; // Versione Emanuele
            }
        }
    }
    // sommo la seconda diagonale
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (i + j == R - 1)
            {
                // Errore - indice sbagliato
                ver[R * 2 + 1] += A[i][j]; // Versione Prof
//                ver[R * 2 + 2] += A[i][j]; // Versione Emanuele
            }
        }
    }
    
    for (int i = 0; i < (R * 2) + 1; i++) // Versions Prof
//    for (int i = 0; i < (R * 2) + 2; i++) // Versione Emanuele
    {
        // Errore - indice va fuori dall'array
        if (ver[i] == ver[i+1])
        {
            ver[i] = 0;
        }
    }
    
    int temp = 0;
    
    for (int i = 0; i < (R * 2) + 2; i++)
    {
        temp += ver[i];
    }
    
    // Errore - L'algoritmo genera falsi negativi: se ho somme diverse che accidentalmente
    // sono uguali alla prima somma moltiplicata per (R * 2) + 2, il tuo algoritmo lo classifica
    // come quadrato magico. Eh, lo so...
    if (temp == ver[0] * ((R * 2) + 2))
    {
        return 1;
    }
    return 0;
}













