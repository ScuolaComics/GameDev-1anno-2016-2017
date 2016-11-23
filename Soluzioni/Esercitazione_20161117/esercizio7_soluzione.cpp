#include <iostream>

using namespace std;

#define MAGIC_NUMBER 5

int main()
{
    int currentNumber = -1;
    do
    {
        cout << "Inserisci un numero diverso da " << MAGIC_NUMBER << endl; 
        cin >> currentNumber;
    }
    while (MAGIC_NUMBER != currentNumber);
    cout << "Ehi! non dovevi inserire il numero " << MAGIC_NUMBER << "!" << endl; 
   
    return 0;
}

