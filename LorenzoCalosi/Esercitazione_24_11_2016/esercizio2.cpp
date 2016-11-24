#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const string NEAR     = "Fuochino";
const string NEARER   = "Fuoco";
const string HIT      = "Colpito!";
const string MISS     = "Acqua";
const string INPUTX   = "Inserisci la riga: ";
const string INPUTY   = "Inserisci la colonna: ";

const int SIZEX = 10;   //SIZEX MUST BE < 25
const int SIZEY = 10;   //SIZEY MUST BE < 25

struct position
{
    unsigned short int x;
    unsigned short int y;
};

struct ship
{
    position shipPosition;
    unsigned short int sizeX;
    unsigned short int sizeY;
};



ship enemyShip;
char playingGrid[SIZEX][SIZEY];
unsigned short int gameOver = 0;
char continueChar = 'y';

unsigned short int userInput();
unsigned short int insertValue(position input);
char continueQuestion();
void setupGrid();
void generateShip();
void printGrid();

int main()
{
    if(SIZEX>25||SIZEY>25)
    {
        cout << "Error! Wrong setup!" << endl;
        return 0;
    }
    do
    {
        setupGrid();
        do
        {
            printGrid();
            gameOver = userInput();
        }
        while(gameOver);
    }
    while(continueChar);
}

void setupGrid()
{
    for(int i = 0; i < SIZEX; i++)
    {
        for(int j = 0; j < SIZEY; j++)
        {
            playingGrid[i][j] = ' ';
        }
    }
    return;
}

void generateShip()
{
    srand(time(NULL));
    enemyShip.sizeX = 1;
    enemyShip.sizeY = 1;
    enemyShip.shipPosition.x = rand()%SIZEX;
    enemyShip.shipPosition.y = rand()%SIZEY;
}

void printGrid()
{
    cout << "\t";
    for(int i = 0; i < SIZEX; i++)
    {
        cout << ALPHABET[i];
    }
    cout << endl;
    for(int i = 0; i < SIZEX; i++)
    {
        cout << ALPHABET[i];
        for(int j = 0; j < SIZEY; j++)
        {
            cout << playingGrid[i][j];
        }
    }
    cout << endl;
}

unsigned short int userInput()
{
    position input;
    unsigned short int hitType;
    do
    {
        cout << "Insert the X position: ";
        cin >> input.x;
    }
    while(input.x>SIZEX||input.x<0);

    do
    {
        cout << "Insert the Y position: ";
        cin >> input.y;
    }
    while(input.y>SIZEX||input.y<0);

    switch(insertValue(input))
    {
        case 1:
            cout << HIT << "\nYou Win!!\n\n";
            return 1;
        case 2:
            cout << NEAR;
            return 0;
        case 3:
            cout << NEARER;
            return 0;
        default:
            cout << MISS;
            return 0;
    }
}

unsigned short int insertValue(position input)
{
    if(input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y)
    {
        return 1;
    }
    else if(input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y+1)
    {
        return 2;
    }
    else if(input.x == enemyShip.shipPosition.x-2 && input.y == enemyShip.shipPosition.y-2 ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y-2 ||
            input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y-2 ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y-2 ||
            input.x == enemyShip.shipPosition.x+2 && input.y == enemyShip.shipPosition.y-2 ||
            input.x == enemyShip.shipPosition.x-2 && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x+2 && input.y == enemyShip.shipPosition.y-1 ||
            input.x == enemyShip.shipPosition.x-2 && input.y == enemyShip.shipPosition.y ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y ||
            input.x == enemyShip.shipPosition.x+2 && input.y == enemyShip.shipPosition.y ||
            input.x == enemyShip.shipPosition.x-2 && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x+2 && input.y == enemyShip.shipPosition.y+1 ||
            input.x == enemyShip.shipPosition.x-2 && input.y == enemyShip.shipPosition.y+2 ||
            input.x == enemyShip.shipPosition.x-1 && input.y == enemyShip.shipPosition.y+2 ||
            input.x == enemyShip.shipPosition.x && input.y == enemyShip.shipPosition.y+2 ||
            input.x == enemyShip.shipPosition.x+1 && input.y == enemyShip.shipPosition.y+2 ||
            input.x == enemyShip.shipPosition.x+2 && input.y == enemyShip.shipPosition.y+2)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
