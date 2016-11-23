#include <iostream>

using namespace std;

int main()
{
    cout << "Il punteggio può variare da 0 a 100... Inserisci il tuo punteggio!" << endl;
    int score;
    cin >> score;
    if (90 <= score && score <=  100)
    {
        cout << "Hai ottenuto un punteggio alto!" << endl;
    }
   
    return 0;
}

