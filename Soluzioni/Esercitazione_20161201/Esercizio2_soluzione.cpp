#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>      // std::rand, std::srand

using namespace std;

#define SEED 7

#define DUNGEON_WIDTH 5
#define DUNGEON_HEIGHT 5

#define NUMBER_OF_FOES 3

enum eCell
{
    EMPTY = 0,
    FOE = 5,
    HERO = 7,
    TRESURE = 1
};

enum eGameState
{
    RUNNING,
    DEFEAT,
    VICTORY
};

typedef vector<eCell> DungeonColumn;
typedef vector<DungeonColumn> Dungeon;

void printDungeon(const Dungeon& dungeon);

void initDungeon(Dungeon& dungeon);

eGameState playerMove(Dungeon& dungeon);

int main()
{
    srand(SEED);

    Dungeon dungeon;

    eGameState gameState = RUNNING;

    while(RUNNING == gameState)
    {
        initDungeon(dungeon);
        

        while(RUNNING == gameState)
        {
            printDungeon(dungeon);

            gameState = playerMove(dungeon);
        }

        if (VICTORY == gameState)
        {
            cout << "Congratulazioni! Hai preso il tesoro!" << endl;
        }
        else if (DEFEAT == gameState)
        {
            cout << "Peccato! Hai perso..." << endl;
        }

        int restart = -1;
        cout << "Vuoi ricominciare? (si = 1): ";
        cin >> restart;

        if (1 == restart)
        {
            gameState = RUNNING;
        }
    }

    return 0;
}

void printDungeon(const Dungeon& dungeon)
{
    cout << endl;
    // Stampo le righe al contrario perché voglio che la coordinata Y = 0 sia in basso 
    for (int y = DUNGEON_HEIGHT - 1; y >= 0; --y)
    {
        for (int x = 0; x < DUNGEON_WIDTH; ++x)
        {
            cout << dungeon[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initDungeon(Dungeon& dungeon)
{
    dungeon.clear();

    for (int x = 0; x < DUNGEON_WIDTH; ++x)
    {
        DungeonColumn  column;
        for (int y = 0; y < DUNGEON_HEIGHT; ++y)
        {
            column.push_back(EMPTY);
        }
        dungeon.push_back(column);
    }

    int posX = 0;
    int posY = 0;

    // Posiziono l'eroe
    do
    {
        posX = rand() % DUNGEON_WIDTH;
        posY = rand() % DUNGEON_HEIGHT;
    }
    while(EMPTY != dungeon[posX][posY]);
    dungeon[posX][posY] = HERO;

    // Posiziono il tesoro
    do
    {
        posX = rand() % DUNGEON_WIDTH;
        posY = rand() % DUNGEON_HEIGHT;
    }
    while(EMPTY != dungeon[posX][posY]);
    dungeon[posX][posY] = TRESURE;

    // Posiziono le trappole
    for (int i = 0; i < NUMBER_OF_FOES; ++i)
    {
        do
        {
            posX = rand() % DUNGEON_WIDTH;
            posY = rand() % DUNGEON_HEIGHT;
        }
        while(EMPTY != dungeon[posX][posY]);
        dungeon[posX][posY] = FOE;
    }
}

eGameState playerMove(Dungeon& dungeon)
{
    eGameState newState = RUNNING;

    cout << "Dove vuoi andare (1 = destra, 2 = sinistra, 3 = su, 4 = giù):";

    // Ottengo la scelta del giocatore
    int input = -1;
    do
    {
        cin >> input;
    }
    while(input < 1 || 4 < input);

    // Individuo le coordinate dell'eroe
    int heroX = -1;
    int heroY = -1;

    for (int x = 0; x < DUNGEON_WIDTH; ++x)
    {
        for (int y = 0; y < DUNGEON_HEIGHT; ++y)
        {
            if (HERO == dungeon[x][y])
            {
                heroX = x;
                heroY = y;
            }
        }
    }

    // Calcolo la destinazione in base all'input del giocatore
    int destinationX = heroX;
    int destinationY = heroY;

    switch (input)
    {
        case 1:
            destinationX++;
            break;
        case 2:
            destinationX--;
            break;
        case 3:
            destinationY++;
            break;
        case 4:
            destinationY--;
            break;
        default:
            break;
    }

    // Aggiorno la griglia e lo stato di gioco in base alla nuova posizione del giocatore
    if (0 <= destinationX && destinationX < DUNGEON_WIDTH && 0 <= destinationY && destinationY < DUNGEON_HEIGHT)
    {
        switch (dungeon[destinationX][destinationY])
        {
            case EMPTY:
                dungeon[destinationX][destinationY] = HERO;
                dungeon[heroX][heroY] = EMPTY;
                break;
            case FOE:
                newState = DEFEAT;
                break;
            case TRESURE:
                newState = VICTORY;
                break;
            default:
                break;

        }
    }

    return newState;
}


