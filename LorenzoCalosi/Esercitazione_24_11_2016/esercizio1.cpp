#include <iostream>
#include <cstdlib>

using namespace std;

const int PLAYERNUMBER = 10;

int calcAvg();

int playerScore[PLAYERNUMBER];
int score;

int main()
{
    for(int i = 0; i < PLAYERNUMBER; i++)
    {
        cout << "Insert player " << i + 1 << " score: ";
        cin >> playerScore[i];
    }
    for(int i = PLAYERNUMBER - 1; i >= 0; i--)
    {
        cout << "Player " << i + 1 << " score: " << playerScore[i] << endl;
    }
    calcAvg();
    return 0;
}

int calcAvg()
{
    int avg = 0;
    for(int i = 0; i < PLAYERNUMBER; i++)
    {
        avg += playerScore[i];
    }
    avg /= PLAYERNUMBER;
    cout << "The average is: " << avg;
    return avg;
}
