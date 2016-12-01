#include <iostream>

using namespace std;

#define GRID_WIDTH 10
#define GRID_HEIGHT 10

#define SEED 7

int main()
{
    // seed per il generatore randomico (versione deterministica)
    srand(static_cast<unsigned int>(SEED));
    
    bool game = true;

    while (game)
    {
        int enemyX = rand() % GRID_WIDTH;
        int enemyY = rand() % GRID_HEIGHT;

        int playerChoiceX = -1;
        int playerChoiceY = -1;

        bool hit = false;
        while (hit == false)
        {
            cout << "Scegli la coordinata X da colpire: " << endl;
            cin >> playerChoiceX;
            cout << "Scegli la coordinata Y da colpire: " << endl;
            cin >> playerChoiceY;

            if (0 <= playerChoiceX && playerChoiceX < GRID_WIDTH && 0 <= playerChoiceY && playerChoiceY < GRID_HEIGHT)
            {
                if (playerChoiceX == enemyX && playerChoiceY == enemyY)
                {
                    hit = true;
                }
                else
                {
                    int deltaX = playerChoiceX - enemyX;
                    int deltaY = playerChoiceY - enemyY;
                    if (-1 <= deltaX && deltaX <= 1 && -1 <= deltaY && deltaY <= 1)
                    {
                        cout << "Fuoco!" << endl;
                    }
                    else if (-2 <= deltaX && deltaX <= 2 && -2 <= deltaY && deltaY <= 2)
                    {
                        cout << "Fuochino!" << endl;
                    }
                    else
                    {
                        cout << "Acqua..." << endl;
                    }
                }
            }
            else
            {
                cout << "Coordinate non valide!" << endl;
            }
        }

        // Richiesta di restart
        bool invalidInput = false;
        do
        {
            cout << "Colpito!!! Vittoria!" << endl;
            cout << "Vuoi ricominciare?\n1) Si;\n2) No." << endl;
            int restartChoice;
            cin >> restartChoice;

            invalidInput = false; 
            switch (restartChoice)
            {
                case 1:
                    game = true; // Superfluo ma per chiarezza
                    break;
                case 2:
                    game = false;
                    break;
                default:
                    invalidInput = true;
                    break;

            }
        }
        while (invalidInput);
    }

    return 0;
}
