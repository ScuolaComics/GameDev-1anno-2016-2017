#include <iostream>

using namespace std;

int main()
{
    // E' buona prassi inizializzare sempre le variabili!
    int currentNumber = -1;
    int currentIteration = -1;
    do
    {
        currentIteration++;
        cout << "Inserisci un numero diverso da " << currentIteration << endl; 
        cin >> currentNumber;
    }
    while (currentNumber != currentIteration);
    
    cout << "Ehi! non dovevi inserire il numero " << currentIteration << "!" << endl; 
   
    return 0;
}