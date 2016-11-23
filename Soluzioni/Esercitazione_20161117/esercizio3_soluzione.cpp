#include <iostream>

using namespace std;

int main()
{
    cout << "Il punteggio puo' variare da 0 a 100... Inserisci il tuo punteggio!" << endl;
    
    int score;
    cin >> score;
    
    if (0 <= score && score <=  59)
    {
        cout << "Il tuo punteggio e' di categoria E" << endl;
    }
    else if (60 <= score && score <= 69)
    {
        cout << "Il tuo punteggio e' di categoria D" << endl;
    }
    else if (70 <= score && score <=  79)
    {
        cout << "Il tuo punteggio e' di categoria C" << endl;
    }
    else if (80 <= score && score <=  89)
    {
        cout << "Il tuo punteggio e' di categoria B" << endl;
    }
    else if (90 <= score && score <=  100)
    {
        cout << "Il tuo punteggio e' di categoria A" << endl;
    }
   
    return 0;
}