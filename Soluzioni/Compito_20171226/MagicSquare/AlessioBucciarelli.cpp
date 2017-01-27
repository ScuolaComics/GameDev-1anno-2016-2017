//
//  main.cpp
//  MagicSquareAlessioBucciarelli
//
//  Created by Leonardo Passeri on 27/01/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>
#include <time.h>
#define R 3

int A[R][R];

void acquisitionA();
int magicSquare();

using namespace std;

int main(int argc, const char * argv[])
{
    int ris;
    // Acquisizione e riempiemento matrice
    acquisitionA();
    // controllo se quadrato maggggico
    ris = magicSquare();
    // stampa il risultato
    if (ris == 1)
    {
        // Errore - usato >> al posto di <<
        cout << "E' un quadrato maggggico!" << endl; // Versione Prof
//        cout >> "E' un quadrato maggggico!" >> endl; // Versione Alessandro
    }
    else
    {
        // Errore - usato >> al posto di <<
        cout << "Non e' un quadrato maggggico!" << endl; // Versione Prof
//        cout >> "Non e' un quadrato maggggico!" >> endl; // Versione Alessandro
    }
    return 0;
}

// funzione x riempimento matrice
void acquisitionA()
{
    // Meglio con il cast
    srand(static_cast<unsigned int>(time(NULL))); // Versione Prof
//    srand(time(NULL)); // Versione Alessandro
    int i,j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < R; j++)
        {
            // Errore - I componenti possono assumere qualunque valore
            A[i][j] = rand() & 9 + 1;
        }
    }
}

// funzione di controllo del quadrato maggggico
int magicSquare()
{
    // Errore - l'algoritmo doveva essere valido per matrici quadrate di qualunque dimensione
    // il tuo algoritmo contempla solo per matrici 3x3.
    int result[8] {0,0,0,0,0,0,0,0};
    
    int i,j;
    int x = 0;
    // controllo righe & colonne
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < R; j++)
        {
            // Errore - Assumendo (cosa già errata) che la matrice sia 3x3 avresti dovuto variare l'indice di result
            // Versione Prof
            result[i] = result[i] + A[i][j];
            result[i + 3] = result[i + 3] + A[j][i];
            // Versione Alessandro
//            result[x] = result[x] + A[i][j];
//            result[x + 3] = result[x + 3] + A[j][i];
        }
    }
    // "controllo" 1° diagonale & 2° diagonale
    result[6] = A[0][0] + A[1][1] + A[2][2];
    result[7] = A[2][0] + A[1][1] + A[0][2];
    // vero controllo se quadrato maggggico o no
    for (i = 0,j = 1; i < 7; i++)
    {
        if (result[i] != result[i + 1])
        {
            // Prof: "Usare un indice come variabile da restituire è un po' troppo selvaggio (poco leggibile)
            j = 0;
        }
    }
    
    return j;
}



