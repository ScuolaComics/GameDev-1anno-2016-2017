#include <iostream>

using namespace std;

#define MAGIC_NUMBER 5
#define MAX_ITERATIONS 10

int main()
{
    // E' buona prassi inizializzare sempre le variabili!
    int currentNumber = -1;
    int currentIteration = 0;
    do
    {
        cout << "Inserisci un numero diverso da " << MAGIC_NUMBER << endl; 
        cin >> currentNumber;
        currentIteration++;
    }
    while (MAGIC_NUMBER != currentNumber && currentIteration < MAX_ITERATIONS);
    
    if (MAGIC_NUMBER == currentNumber)
    {
        cout << "Ehi! non dovevi inserire il numero " << MAGIC_NUMBER << "!" << endl; 
    }
    else
    {
        cout << "Uao, sei piu' paziente di quanto sono io... Complimenti, hai vinto!" << endl; 
    }
   
    return 0;
}

