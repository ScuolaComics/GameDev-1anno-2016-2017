#include <iostream>

using namespace std;

int main()
{
    short int difficulty;
    
    cout << "Scegli la tua difficolta':" << endl;
    cout << "0 = Molto Facile" << endl;
    cout << "1 = Facile" << endl;
    cout << "2 = Media" << endl;
    cout << "3 = Difficile" << endl;
    cout << "4 = Molto Difficile" << endl;
    
    cin >> difficulty;
    
    switch(difficulty)
    {
        case 0:
            cout << "Difficolta' scelta: Molto Facile" << endl;
            break;
        case 1:
            cout << "Difficolta' scelta: Facile" << endl;
            break;
        case 2:
            cout << "Difficolta' scelta: Media" << endl;
            break;
        case 3:
            cout << "Difficolta' scelta: Difficile" << endl;
            break;
        case 4:
            cout << "Difficolta' scelta: Molto Difficile" << endl;
            break;
        default:
            cout << "Mi dispiace, ma non esiste questa difficolta'" << endl;
            break;
    }
    
    return 0;
}