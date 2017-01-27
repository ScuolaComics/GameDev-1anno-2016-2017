//
//  main.cpp
//  MagicSquareGiacomoVanni
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>

using namespace std;

// Errore  - Negli array C allocati staticamente, la dimensione degli array deve essere definita all'inizio
//int A[][]; // Versione Giacomo
// Versione Prof
#define MATRIX_SIDE 3
int A[MATRIX_SIDE][MATRIX_SIDE];

void insMat(int R)
{
    int x = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cout << "Inserisci il valore alla pos" << i << " " << j << endl;
            cin >> x;
            // Errore  - Manca l'assegnazione alla matrice A
            A[i][j] = x; // Aggiunto dal prof
        }
    }
}

bool controlloMat(int R)
{
    int contaDm = 0;
    int contaDM = 0;
    int contaRighe = 0;
    int contaColonne = 0;
    int controllo = 0;
    
    // Controllo somma righe
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            contaRighe += A[i][R - j]; // Errore - R - j -1
        }
    }
    
    // Errore  - I controlli sulle diagonali sommano ogni elemento R volte. Serviva un solo ciclo for
    
    // Controllo diagonale maggiore
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            contaDM += A[i][i];
        }
    }
    
    // Controllo diagonale maggiore
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            contaDm += A[i][R - 1 - i];
        }
    }
    
    // Errore  - Il controllo sulle colonne è identico a quello delle righe, che cicla le colonne in un ordine
    // diverso. Andava invertito l'indice di accesso: es.: A[i][j] (righe), A[j][i] (colonne),
    // Controllo colonne
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            contaColonne += A[R - i][j]; // Errore - R - i - 1
        }
    }
    
    controllo = contaRighe;
    
    if (contaColonne == controllo && contaDM * R == controllo && contaDm * R == controllo)
    {
        // Errore  - contaRighe e contaColonne contengono solo la somma di tutti gli elementi della matrice
        // non garantiscono che la somma di righe è colonne sia uguale
        return 1;
    }
    else
    {
        return 0;
    }

}

int main(int argc, const char * argv[])
{
    int R;
    cout << "Inserisci la grandezza della matrice: " << endl;
    cin >> R;
    bool c;
    
    insMat(R);
    c = controlloMat(R);
    if (c == 1)
    {
        cout << "complimenti, quadrato magico" << endl;
    }
    else
    {
        cout << "quadrato non magico" << endl;
    }
    
    return 0;
}
