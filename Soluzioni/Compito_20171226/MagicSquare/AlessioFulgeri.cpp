//
//  main.cpp
//  MagicSquare
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

// Errori:
// 1) Mancano i prototipi delle funzioni prima del main;
// 2) isMagico non usata
// 3) Mancano le inizializzazioni a zero di sumsI e sumsJ;
// 4) Assegnazione a sums non dichiarato
// 5) sintassi sbagliata nel for;
// 6) partenza dell'indice i fuori dai bound dell'array;

#include <iostream>

using namespace std;

int ** mat;

// Errore 1
void acquisisci(int r);
bool isQuadratoMagico(int r);
void liberaMemoria(int r);

int main(int argc, const char * argv[])
{
    int r = 0;
    
    do{
        cout << "inserisci r:" << endl;
        cin >> r;
    }
    while (r <= 0);
    
    acquisisci(r);
    
    if (isQuadratoMagico(r))
    {
        cout << "e' un quadrato magico!" << endl;
    }
    else
    {
        cout << "non e' un quadrato magico" << endl;
    }
    
    liberaMemoria(r);
    
    return 0;
}

void acquisisci(int r)
{
    mat = new int*[r];
    for (int i = 0; i < r; i++)
    {
        mat[i] = new int[r];
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "inserisci num " << i << " - " << j << endl;
            cin >> mat[i][j];
        }
    }
}

bool isQuadratoMagico(int r)
{
    int isMagico = 0; // Errore 2
    int * sumsI;
    int * sumsJ;
    int sumsD[2];
    
    sumsI = new int[r];
    sumsJ = new int[r];
    
    // Errore 2
    for (int i = 0; i < r; i++)
    {
        sumsI[i] = 0;
        sumsJ[i] = 0;
    }
    
    for (int i = 0; i < r; i++)
    {
//        sums[i] = 0; // Errore 3
        for (int j = 0; j < r; j++)
        {
            sumsI[i] += mat[i][j];
            sumsJ[i] += mat[j][i];
        }
    }
    sumsD[0] = 0;
    sumsD[1] = 0;
    
    //for (int i = 0, int j = 0; i < r; i++, j++) // Errore 4 -> for (int i = 0, j = 0; i < r; i++, j++)
    for (int i = 0, j = 0; i < r; i++, j++)
    {
        sumsD[0] += mat[i][j];
    }
    
//    for (int i = r, int j = 0; i >= 0; i--, j++) // Errore 4 - 5 -> for (int i = r - 1, j = 0; i >= 0; i--, j++)
    for (int i = r-1, j = 0; i >= 0; i--, j++)
    {
        sumsD[1] += mat[i][j];
    }
    
    // controllo se le somme sono tutte uguali
    int * sums;
    sums = new int[r * 2 + 2];
    
    for (int i = 0; i < r; i++)
    {
        sums[i] = sumsI[i];
        sums[i + r] = sumsJ[i];
    }
    
    sums[r*2 + 1] = sumsD[1];
    sums[r*2] = sumsD[0];
    int controllo = sums[0];
    
    for (int i = 1; i < r * 2 + 2; i++)
    {
        if (controllo != sums[i])
        {
            delete sums;
            delete sumsI;
            delete sumsJ;
            return 0;
            
        }
    }
    
    delete sums;
    delete sumsI;
    delete sumsJ;
    return 1;
}

void liberaMemoria(int r)
{
    for (int i = 0; i < r; i++)
    {
        delete mat[i];
    }
    delete mat;
}
