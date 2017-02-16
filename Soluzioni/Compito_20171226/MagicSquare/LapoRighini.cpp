//
//  main.cpp
//  MagicSquareLapoRighini
//
//  Created by Leonardo Passeri on 16/02/2017.
//  Copyright © 2017 Balzo. All rights reserved.
//

#include <iostream>
// Errore - Se vuoi usare gli standard vector, serve includere la libreria:
#include <vector>

#define MATRIX_SIZE 3 // Aggiunto dal prof

// Errore: Manca la funzione acquisisci()

// Errore: non puoi definire un array C come parametro formale senza specificare il size
bool quadratoMagico(int A[MATRIX_SIZE][MATRIX_SIZE]) // Versione Prof
//bool quadratoMagico(int[][] A) // versione Lapo
{
    // Errore di sintassi
//    int vector B; // Versione Lapo
    std::vector<int> B; // Versione Prof
    
    // Errore di sintassi (gli array C non hanno la proprietà size
    // e per fare le potenze serve "pow" di math.h, l'operatore ^ fa lo XOR.
//    int I = A.size^0.5; // Versione Lapo
    int I = MATRIX_SIZE; // Versione Prof
    
    // Errore logico di tutti i for: per iterare al contrario devi partire dal size -1 (es.: int C = I - 1)
    
    int E = 0, F = 0, G = 0, H = 0;
    for (int C = I; C >= 0; C--)
    {
        E = 0;
        for (int D = I; D >= 0; D--)
        {
            E += A[C][D];
        }
        B.push_back(E);
    }
    
    for (int C = I; C >= 0; C--)
    {
        E = 0;
        for (int D = I; D >= 0; D--)
        {
            E += A[D][C];
        }
        B.push_back(E);
    }
    
    E = 0;
    for (int C = I; C >= 0; C--)
    {
        E += A[C][C];
        
    }
    B.push_back(E);
    
    E = 0;
    for (int C = I; C >= 0; C--)
    {
        E += A[F][C];
        F++;
    }
    B.push_back(E);
    
    E = 0;
    G = (int)B.size();
    for (int C = G; G >= 0; G--)
    {
        // Errore di sintassi (back() restituisce il valore, pop_back() lo cancella, senza restituirlo)
        E += B.back(); // Versione Prof
        B.pop_back();
//        E += B.pop_back(); // Versione Lapo
        if (C == B.size())
        {
            H = E;
        }
    }
    
    // Errore logico: fare la somma di tutte le somme, dividerla per il numero di somme e confrontarla
    // con l'ultima somma ottenuta non dimostra che tutte le somme sono uguali (è condizione necessaria
    // ma non suffciente). Dimostra solo che la loro media è uguale all'ultima somma.
    // Es.: B = [6, 5, 6, 7, 6] -> H = 6, E = 30, E = E / G <=> 6 = 30 / 5, H == E
    E = E/G;
    
    if (E == H)
    {
        return true;
    }
    else
    {
        return  false;
    }
}

int main(int argc, const char * argv[]) {
    
    // Errore: manca l'esecuzione di acquisisci() (che manca a sua volta)
    // e di quadratoMagico() (che si sarebbe dovuta chiamare "Verifica").
    
    std::cout << "Hello, World!\n";
    return 0;
}


