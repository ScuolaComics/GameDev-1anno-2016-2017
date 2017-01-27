//
//  main.cpp
//  MagicSquareLorenzoCalosi
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

void Acquisci(const int& R)
{
    // Errore - Con i vector il popolamento è diverso:
    // Versione Prof
    for (int i = 0; i < R; i++)
    {
        vector<int> row;
        for (int j = 0; j < R; j++)
        {
            cout << "Inserisci valore (" << i << "," << j << "):";
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    // Versione Lorenzo
//    for (int i = 0; i < R; i++)
//    {
//        for (int j = 0; j < R; j++)
//        {
//            cout << "Inserisci valore (" << i << "," << j << "):";
//            cin >> matrix[i][j];
//        }
//    }
}

bool Verifica()
{
    bool firstTime = true;
    
    // Usare nomi di variabili più leggibili
    // Inizializzare le variabili
    
    // Piccolezza: meglio castare perché size non resituisce un intero.
    int mVal, tVal, dVal, size = (int)matrix.size(); // Versione Prof
//    int mVal, tVal, dVal, size = matrix.size(); // Versione Lorenzo
    
    for (int i = 0; i < size; i++)
    {
        tVal = 0;
        dVal = 0;
        for (int j = 0; j < size; j++)
        {
            tVal += matrix[i][j];
            dVal += matrix[j][i];
        }
        if (firstTime)
        {
            mVal = tVal;
            firstTime = false;
        }
        if (mVal != tVal || mVal != dVal)
        {
            return false;
        }
    }
    tVal = 0;
    dVal = 0;
    for (int i = 0; i < size; i++)
    {
        tVal += matrix[i][i];
        // Errore - tVal e dVal contengono la somma della stessa diagonale
        // la prima partendo da 0,0 fino a size - 1,size -1, la seconda al contrario.
        // Inoltre size - i è fuori dall'array per i = 0;
        dVal += matrix[i][size - i - 1]; // Versione Prof
//        dVal += matrix[size - i][size - i]; // Versione Lorenzo
    }
    if (mVal != tVal || mVal != dVal)
    {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int R;
    
    // Errore - invertito operatore << con >> e viceversa
    // Versione Prof
    cout << "Grandezza Quadrato Magico?" << endl;
    cin >> R;
     // Versione Lorenzo
//    cout >> "Grandezza Quadrato Magico?" >> endl;
//    cin << R;
    Acquisci(R);
    if (Verifica())
    {
        cout << "E' un quadrato magico!" << endl;
    }
    else
    {
        cout << "NON e' un quadrato magico!" << endl;
    }
    
    return 0;
}
