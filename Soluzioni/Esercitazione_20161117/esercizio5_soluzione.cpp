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
    
    if (0 == difficulty)
    {
        cout << "Difficolta' scelta: Molto Facile" << endl;
    }
    else if (1 == difficulty)
    {
        cout << "Difficolta' scelta: Facile" << endl;
    }
    else if (2 == difficulty)
    {
        cout << "Difficolta' scelta: Media" << endl;
    }
    else if (3 == difficulty)
    {
        cout << "Difficolta' scelta: Difficile" << endl;
    }
    else if (4 == difficulty)
    {
        cout << "Difficolta' scelta: Molto Difficile" << endl;
    }
   
    return 0;
}
