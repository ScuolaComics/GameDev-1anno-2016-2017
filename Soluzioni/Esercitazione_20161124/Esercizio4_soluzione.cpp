#include <iostream>
#include <ctime>

using namespace std;

int _fuel = 100;
int _ammo = 50;
int _supply = 100;

void explore();
void defend();
void escort();

int main()
{
    while (_fuel > 0 && _ammo > 0 && _supply > 0)
    {
        string mission = "";

        cout << "Carburante: " << _fuel << endl;
        cout << "Munizioni: " << _ammo << endl;
        cout << "Scorte: " << _supply << endl;
        cout << endl;
        cout << "Scegli la missione:" << endl;
        cout << "- Esplorazione (id: 'esplorazione')" << endl;
        cout << "- Difesa della Terra (id: 'difesa')" << endl;
        cout << "- Scorta ricercatori (id: 'scorta')" << endl;

        cin >> mission;
        if ("esplorazione" == mission)
        {
            explore();
        }
        else if ("difesa" == mission)
        {
            defend();
        }
        else if ("scorta" == mission)
        {
            escort();
        }
        else
        {
            cout << "Missione non valida!" << endl;
        }
    }

    cout << endl;
    if (_fuel <= 0)
    {
        cout << "Carburante terminato!" << endl;
    }
    if (_ammo <= 0)
    {
        cout << "Munizioni terminate!" << endl;
    }
    if (_supply <= 0)
    {
        cout << "Scorte terminate!" << endl;
    }
    cout << endl;
    cout << "Game Over!" << endl;

    return 0;
}

void explore()
{
    _fuel -= 20;
    _supply -= 20;
}

void defend()
{
    _fuel -= 5;
    _ammo -= 20;
    _supply -= 5;
}

void escort()
{
    _fuel -= 10;
    _ammo -= 10;
    _supply -= 10;
}
