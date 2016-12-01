#include <iostream>

using namespace std;

#define PLAYER_NUM 10

int main()
{
    int leaderboard[PLAYER_NUM];

    // Inserimento punteggi
    for (int player = 0; player < PLAYER_NUM; ++player)
    {
        cout << "Punteggio per il Giocatore " << player << ":";
        cin >> leaderboard[player];
    }  

    // Stampa invertita
    for (int player = PLAYER_NUM - 1; player >= 0; --player)
    {
        cout << "Giocatore " << player << ": " << leaderboard[player]  << endl;
    }    

    // Calcolo della media
    int totalScore = 0;
    for (int player = 0; player < PLAYER_NUM; ++player)
    {
        totalScore += leaderboard[player];
    }    
    cout << "Media punteggi: " << (float)totalScore / PLAYER_NUM  << endl;

    return 0;
}
