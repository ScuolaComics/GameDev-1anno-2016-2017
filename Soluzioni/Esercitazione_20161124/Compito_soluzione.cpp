#include <iostream>
#include <string>

using namespace std;

#define BOARD_SIDE 3

#define RANDOM_SEED 9

enum OpponentIA
{
    eOpponentIAEasy,
    eOpponentIAHard,
};

enum GameState
{
    eRunning,
    eVictory,
    eTie,
    eDefeat,
};

enum CellValue
{
    eEmpty,
    ePlayer,
    eOpponent
};

void clearBoard();
void printBoard();
void resolvePlayerRound();
void resolveCPURound();
GameState getGameState();
void resolveGameEnd();

CellValue _board[BOARD_SIDE][BOARD_SIDE];

GameState _gameState = eRunning;
OpponentIA _currentIA = eOpponentIAEasy;

int main()
{
    _currentIA = eOpponentIAEasy;
    _gameState = eRunning;

    bool playerRound = true;

    srand(RANDOM_SEED);

    while (_gameState == eRunning)
    {
        clearBoard();
        printBoard();

        while (_gameState == eRunning)
        {
            if (playerRound)
            {
                resolvePlayerRound();
                playerRound = false;
            }
            else
            {
                resolveCPURound();
                playerRound = true;
            }
            printBoard();
            _gameState = getGameState();
        }

        resolveGameEnd();
    }

    return 0;
}

void clearBoard()
{
    for (int i = 0; i < BOARD_SIDE; ++i)
    {
        for (int j = 0; j < BOARD_SIDE; ++j)
        {
            _board[i][j] = eEmpty;
        }
    }
}

void printBoard()
{
    cout << endl;

    // Conto le righe al contrario perché voglio che le coordinate 0,0 siano in basso a sinistra
    for (int j = BOARD_SIDE - 1; j >= 0; --j)
    {

        for (int i = 0; i < BOARD_SIDE; ++i)
        {
            char cellSymbol = ' ';
            switch (_board[i][j])
            {
                case ePlayer:
                    cellSymbol = 'X';
                    break;
                case eOpponent:
                    cellSymbol = '0';
                    break;
                default:
                    cellSymbol = ' ';
                    break;
            } 
            cout << " " << cellSymbol << " ";

            // Il controllo serve per non stampare le linee verticali anche dopo l'ultima colonna
            if (i < BOARD_SIDE - 1)
            {
                cout << "|";
            }
        }
        cout << endl;

        // Il controllo serve per non stampare le linee orizzontali anche dopo l'ultima riga
        if (j > 0)
        {
            for (int i = 0; i < BOARD_SIDE; ++i)
            {
                cout << "--- ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

void resolvePlayerRound()
{
    bool invalidInput = false;
    int inputX = -1;
    int inputY = -1;

    do
    {
        cout << "E' il tuo turno" << endl;

        do 
        {
            cout << "Digita la coordinata X:";
            cin >> inputX;
        }
        while(inputX < 0 || BOARD_SIDE < inputX);

        do 
        {
            cout << "Digita la coordinata Y:";
            cin >> inputY;
        }
        while(inputY < 0 || BOARD_SIDE < inputY);
    }
    while (ePlayer == _board[inputX][inputY] || eOpponent == _board[inputX][inputY]);

    _board[inputX][inputY] = ePlayer;
}

void resolveCPURound()
{
    int posX = -1;
    int posY = -1;

    cout << "E' il turno del tuo avversario" << endl;

    if (_currentIA == eOpponentIAHard)
    {
        // Per ciascuna cella vuota, simulo che il giocatore la scelga al prossimo turno.
        // Se la scelta si traduce in una vittoria del giocatore, allora sarà la scelta per la CPU.
        for (int i = 0; i < BOARD_SIDE; ++i)
        {
            for (int j = 0; j < BOARD_SIDE; ++j)
            {
                if (0 == _board[i][j])
                {
                    _board[i][j] = ePlayer;
                    if (eVictory == getGameState())
                    {
                        posX = i;
                        posY = j;
                    }
                    _board[i][j] = eEmpty;
                }
            }
        }
    }

    if (-1 == posX || -1 == posY)
    {
        do
        {
            posX = rand() % BOARD_SIDE;
            posY = rand() % BOARD_SIDE;
        }
        while (ePlayer == _board[posX][posY] || eOpponent == _board[posX][posY]);
    }

    _board[posX][posY] = eOpponent;
}

GameState getGameState()
{
    // Controllo le colonne
    for (int i = 0; i < BOARD_SIDE; ++i)
    {
        if (_board[i][0] == _board[i][1] && _board[i][1] == _board[i][2])
        {
            if (ePlayer == _board[i][0])
            {
                return eVictory;
            }
            else if (eOpponent == _board[i][0])
            {
                return eDefeat;
            }
            
        }
    }

    // Controllo le righe
    for (int j = 0; j < BOARD_SIDE; ++j)
    {
        if (_board[0][j] == _board[1][j] && _board[1][j] == _board[2][j])
        {
            if (ePlayer == _board[0][j])
            {
                return eVictory;
            }
            else if (eOpponent == _board[0][j])
            {
                return eDefeat;
            }
            
        }
    }

    // Controllo le diagonali
    if (_board[0][0] == _board[1][1] && _board[1][1] == _board[2][2])
    {
        if (ePlayer == _board[1][1])
        {
            return eVictory;
        }
        else if (eOpponent == _board[1][1])
        {
            return eDefeat;
        }
    }
    if (_board[0][2] == _board[1][1] && _board[1][1] == _board[2][0])
    {
        if (ePlayer == _board[1][1])
        {
            return eVictory;
        }
        else if (eOpponent == _board[1][1])
        {
            return eDefeat;
        }
    }

    // Controllo il pareggio
    bool tie = true;
    for (int i = 0; i < BOARD_SIDE; ++i)
    {
        for (int j = 0; j < BOARD_SIDE; ++j)
        {
            if (0 == _board[i][j])
            {
                tie = false;
            }
        }
    }
    if (tie)
    {
        return eTie;
    }

    return eRunning;
}

void resolveGameEnd()
{
    int input = -1;
    switch (_gameState)
    {
        case eVictory:
        {
            switch (_currentIA)
            {
                case eOpponentIAEasy:
                    cout << "Bravo! Ma questa era facile... Alla prossima sarà più difficile...";
                    break;
                case eOpponentIAHard:
                    cout << "Congratulazioni! Sei un mago del tris!" << endl;
                    break;
                default:
                    break;
            }
            cout << "Per rigiocare, digitare '1'." << endl;
            cin >> input;
            if (1 == input)
            {
                _currentIA = eOpponentIAHard;
                _gameState = eRunning;
            }
            break;
        }
        case eTie:
            cout << "Pareggio! Per rigiocare, digitare '1'." << endl;
            cin >> input;
            if (1 == input)
            {
                _gameState = eRunning;
            }
            break;
        case eDefeat:
        {
            cout << "Peccato, hai perso. Per rigiocare, digitare '1'." << endl;
            cin >> input;
            if (1 == input)
            {
                _gameState = eRunning;
            }
            break;
        }
        default:
            break;
    }
}
