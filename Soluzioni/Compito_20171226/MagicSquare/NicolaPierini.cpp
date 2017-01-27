//
//  main.cpp
//  MagicSquareNicolaPierini
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>

using namespace std;

// Errore  - Negli array C allocati staticamente, la dimensione degli array deve essere definita all'inizio
//int A[][];
#define MATRIX_SIDE 3
int A[MATRIX_SIDE][MATRIX_SIDE];

int getDimension();
void populate(int r);
int check(int r);

int main(int argc, const char * argv[])
{
    int dimension = getDimension();
//    void populate(dimension); // Errore - void non viene aggiunto nella chiamata funzione
    populate(dimension);
    
    int result = check(dimension);
    
    if(result == 1)
    {
        cout << "E' un quadrato magico" << endl;
    }
    else
    {
        cout << "Non e' un quadrato magico" << endl;
    }
    
    return 0;
}

int getDimension()
{
    bool flag = false;
    int dim = 0;
    
    do
    {
        cout << "Inserisci dimensione" << endl;
        cin >> dim;
        if (dim > 0)
        {
            flag = true;
        }
    }
    while(!flag);
    
    return dim;
}

void populate(int r)
{
    int value = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "Inserisci valore" << endl;
            cin >> value;
            A[i][j] = value;
        }
    }
}

int check(int r)
{
    int rst = 5; // inizializzazione casuale. Prof: "Perché...?"
    int fD = 0, sD = 0, fR = 0, sR = 0, tR = 0;
    int fC = 0, sC = 0, tC = 0;
    
    // Errore - Andrebbe bene per r == 3, ma r è una VARIABILE. L'algoritmo deve essere generalizzato.
    for (int i = 0; i < r; i++)
    {
        fR += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        sR += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        tR += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        fC += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        sC += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        tC += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        fR += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        fD += A[0][i];
    }
    for (int i = 0; i < r; i++)
    {
        sD += A[i][2-i];
    }
    
    // Errore - La tua logica mi è oscura... avresti dovuto controllare che tutte le somme sono uguali
    // la condizione che poni è necessaria ma non sufficiente affinché le somme siano uguali.
    if ((fD - sD + fR - sR + tR - fC + sC - tC) == 0)
    {
        rst = 1;
    }
    else
    {
        rst = 0;
    }
    
    return  rst;
    
}

