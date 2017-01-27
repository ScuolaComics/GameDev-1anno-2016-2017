//
//  main.cpp
//  MagicSquareCarmeloMammana
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>
#include <time.h>

// Errore - Manca "using namespace std;" per i cout e endl nel main
using namespace std; // Aggiunto dal Prof

// Errore  - Negli array C allocati staticamente, la dimensione degli array deve essere definita all'inizio
//int A[][]; // Versione Carmelo
// Versione Prof
#define MATRIX_SIDE 3
int A[MATRIX_SIDE][MATRIX_SIDE];

// Firma funzioni
void Acquisisci(int R);
bool Verifica (int R);

void Acquisisci(int R)
{
    int x = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            x = rand() % (9) + 1; // Numeri random tra 1 e 9. Prof: "Perché proprio tra 1 e 9...??"
            A[i][j] = x;
        }
    }
}

bool Verifica(int R)
{
    int DP = 0; // Diagonale Principale
    int DS = 0; // Diagonale Secondaria
    
    // Calcolo diagonale principale
    for (int i = 0; i < R; i++)
    {
        DP += A[i][i];
    }
    
    // Calcolo diagonale secondaria
    for (int i = 0; i < R; i++)
    {
        DS += A[i][R - i - 1];
    }
    
    // Controllo se tornano diversi i due risultati
    if (DS != DP)
    {
        return 0;
    }
    else
    { // Se sono uguali calcolo righe e colonne
        // Calcolo righe e colonne inserendoli in due vettori
        int resRow[R];
        int resCol[R];
        
        // Errore - Manca l'inizializzazione di resRow e resCol a zero
        
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < R; j++)
            {
                resRow[i] += A[i][j];
                resCol[i] += A[j][i];
            }
            if (resRow[i] != resCol[i]) // Controllo se sono uguali
            {
                return 0;
            }
        }
        
        // Controllo che le righe e le colonne siano uguali tra loro e uguali a DS e DP
        // Posso scegliere DS o DP perché ??? nella condizione che siano uguali
        for (int i = 0; i < R; i++)
        {
            int j = i + 1;
            // Errore - quando i = R - 1, j = R, per cui accedi fuori da resRow / resCol
            if (resRow[i] != resRow[j] || resRow[i] != DP || resCol[i] != resCol[j] || resCol[i] != DP)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    int R;
    bool v;
    cout << "Inserisci il numero di righe e colonne del tuo quadrato" << endl;
    while(R > 0)
    {
        cin >> R;
    }
    Acquisisci(R);
    v = Verifica(R);
    
    if (v == 1)
    {
        cout << "Wow! Questo quadrato è magico!" << endl;
    }
    else
    {
        cout << "Oh no... Questo quadrato non è magico..." << endl; // Prof: "Disperazione... ^^"
    }
    
    return 0;
}
