#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>

using namespace std;

#define SEED 7

#define DUNGEON_WIDTH 5
#define DUNGEON_HEIGHT 5

#define NUMBER_OF_FOES 3
#define NUMBER_OF_BLOCKS 3

enum eCell
{
    EMPTY = 0,
    FOE = 5,
    HERO = 7,
    BLOCK = 6,
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
eGameState foesMove(Dungeon& dungeon);

int randomNumberGenerator(int i);

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
            if (RUNNING == gameState)
            {
                gameState = foesMove(dungeon);
            }
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

    // Posiziono i nemici
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

    // Posiziono i blocchi
    for (int i = 0; i < NUMBER_OF_BLOCKS; ++i)
    {
        do
        {
            posX = rand() % DUNGEON_WIDTH;
            posY = rand() % DUNGEON_HEIGHT;
        }
        while(EMPTY != dungeon[posX][posY]);
        dungeon[posX][posY] = BLOCK;
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
    if (0 <= destinationX && destinationX < DUNGEON_WIDTH && 0 <= destinationY && destinationY < DUNGEON_HEIGHT && BLOCK != dungeon[destinationX][destinationY])
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

eGameState foesMove(Dungeon& dungeon)
{
    eGameState newState = RUNNING;

    // Ottengo le posizioni dei nemici
    vector<int> foesX;
    vector<int> foesY;

    for (int x = 0; x < DUNGEON_WIDTH; ++x)
    {
        for (int y = 0; y < DUNGEON_HEIGHT; ++y)
        {
            if (FOE == dungeon[x][y])
            {
                foesX.push_back(x);
                foesY.push_back(y);
            }
        }
    }

    // Muovo tutti i nemici in base alle posizioni ricavate
    for (int count = 0; count < foesX.size(); ++count)
    {
        int foeX = foesX[count];
        int foeY = foesY[count];

        int destinationX = foeX;
        int destinationY = foeY;

        vector<int> possibleMoves;
        possibleMoves.push_back(1);
        possibleMoves.push_back(2);
        possibleMoves.push_back(3);
        possibleMoves.push_back(4);
        random_shuffle(possibleMoves.begin(), possibleMoves.end(), randomNumberGenerator);

        // Tento lo spostamento in tutte le direzioni possibili
        for (int i = 0; i < possibleMoves.size(); ++i)
        {
            int possibleDestinationX = foeX;
            int possibleDestinationY = foeY;

            switch (possibleMoves[i])
            {
                case 1:
                    possibleDestinationX++;
                    break;
                case 2:
                    possibleDestinationX--;
                    break;
                case 3:
                    possibleDestinationY++;
                    break;
                case 4:
                    possibleDestinationY--;
                    break;
                default:
                    break;
            }

            if (0 <= possibleDestinationX && possibleDestinationX < DUNGEON_WIDTH && 0 <= possibleDestinationY && possibleDestinationY < DUNGEON_HEIGHT 
                && BLOCK != dungeon[possibleDestinationX][possibleDestinationY]
                && TRESURE != dungeon[possibleDestinationX][possibleDestinationY]
                && FOE != dungeon[possibleDestinationX][possibleDestinationY])
            {
                // Direzione valida! Assegno ed esco dal ciclo
                destinationX = possibleDestinationX;
                destinationY = possibleDestinationY;
                break;
            }

        }    

        // Aggiorno la griglia e lo stato di gioco in base alla nuova posizione del nemico
        switch (dungeon[destinationX][destinationY])
        {
            case EMPTY:
                dungeon[destinationX][destinationY] = FOE;
                dungeon[foeX][foeY] = EMPTY;
                break;
            case HERO:
                newState = DEFEAT;
                break;
            default:
                break;

        }
    }

    return newState;
}

int randomNumberGenerator(int i)
{
    return rand() % i;
}


