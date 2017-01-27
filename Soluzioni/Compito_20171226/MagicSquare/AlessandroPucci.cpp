//
//  main.cpp
//  MagicSquareAlessandroPucci
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>

using namespace std;


// Errore - Per passare un array C con questa sintassi, la dimensione R deve essere una costante già definita
// Errore - Non si può dichiarare array reference. L'array è già di per sé un puntatore, quindi passarlo senza la
// & sarebbe stato sufficiente.
#define MATRIX_SIDE 5 // Aggiunto dal Prof

void loadMatrix(int matrix[MATRIX_SIDE][MATRIX_SIDE], int R) // Versione Prof
//void loadMatrix(int& matrix[R][R], int R) // Versione Alessandro
{
    int maxNum = R * R; bool legit = false; int num = 0;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            // Errore - L'elemento non ha vincoli, può assumere qualunque valore intero
            cout << "Inserire numero tra 1 e " << maxNum << " nella posizione (" << i << "," << j << ")";
            while (legit)
            {
                cin >> num;
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < R; j++)
                    {
                        // Errore - Nulla vieta che possano essere inseriti numeri uguali
                        if (num == matrix[i][j])
                        {
                            cout << "Numero gia' inserito";
                        }
                        else
                        {
                            legit = true;
                        }
                        // Errore - maxNum a che serve, quindi?
                        // Errore - questo check avrebbe dovuto essere fuori da for, per evirare
                        // che venga stampato R * R volte
                        if (num < 1 || num > R)
                        {
                            cout << "Numero non corretto";
                        }
                    }
                }
            }
        }
    }
}

// Errore - Vedi loadMatrix
bool isMagicSquare(int matrix[MATRIX_SIDE][MATRIX_SIDE], int R) // Versione Prof
//bool isMagicSquare(int& matrix[R][R], int R) // Versione Alessandro
{
    bool isMagic = true;
    int rowSums[R]; int colSums[R]; int diag1Sums; int diag2Sums;
    for (int i = 0; i < R; i++)
    {
        int rSum = 0; int cSum = 0;
        for (int j = 0; j < R; j++)
        {
            rSum += matrix[i][j]; cSum += matrix[j][i];
            rowSums[i] = rSum; colSums[i] = cSum;
        }
    }
    
    // Errore - diag1Sums non è inizializzato a 0;
    for (int i = 0; i < R; i++)
    {
        diag1Sums += matrix[i][i];
    }
    
    // Errore - diag2Sums non è inizializzato a 0;
    // Errore - stai sommando la stessa diagonale di prima
    for (int i = R - 1; i >= 0; i--)
    {
        diag2Sums += matrix[i][i];
    }
    
    for (int i = 0; i < R; i++)
    {
        if (rowSums[i] != rowSums[i-1] || colSums[i] != colSums[i-1])
        {
            isMagic = false;
        }
    }
    if (isMagic)
    {
        if (rowSums[0] != colSums[0] ||
            rowSums[0] != diag1Sums ||
            rowSums[0] != diag2Sums)
        {
            isMagic = false;
        }
    }
    return isMagic;
}

int main(int argc, const char * argv[])
{
    // Versione Alessandro
//    int R;
//    cout << "Inserire dimensione R:"; cin >> R;
//    int matrix[R][R];
//    loadMatrix(matrix, R);
//    bool isMagic = isMagicSquare(matrix, R);
    
    // Versione Prof - ovviamente passare la size diventa superfluo
    int matrix[MATRIX_SIDE][MATRIX_SIDE];
    loadMatrix(matrix, MATRIX_SIDE);
    bool isMagic = isMagicSquare(matrix, MATRIX_SIDE);
    
    if (isMagic)
    {
        cout << "E' un quadrato magico" << endl;
    }
    else
    {
        cout << "Non e' un quadrato magico" << endl;
    }
    
    return 0;
}
