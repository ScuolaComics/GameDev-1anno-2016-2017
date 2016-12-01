#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>    // std::sort, std::find

using namespace std;

#define SEED 7

typedef vector<string> Hold;

// Serve per garantire la casualità dello shuffle
int getRandomNumberGenerator (int i);

void printHold(const Hold& hold);

void loadHold(Hold& hold);
void accidentalDrop(Hold& hold);
void friendGift(Hold& hold);
void marketExchange(Hold& hold);
void pirateAttack(Hold& hold);
void orderMania(Hold& hold);
void tempest(Hold& hold);
void sellAll(Hold& hold);

int main()
{
    srand(SEED);

    Hold hold;

    printHold(hold);

    loadHold(hold);
    printHold(hold);

    accidentalDrop(hold);
    printHold(hold);

    friendGift(hold);
    printHold(hold);

    marketExchange(hold);
    printHold(hold);

    pirateAttack(hold);
    printHold(hold);

    orderMania(hold);
    printHold(hold);

    tempest(hold);
    printHold(hold);

    sellAll(hold);
    printHold(hold);

    return 0;
}

void printHold(const Hold& hold)
{
    cout << "Contenuto della stiva" << endl;
    for (int i = 0; i < hold.size(); ++i)
    {
        cout << hold[i] << endl;
    }
    cout << endl;
}

void loadHold(Hold& hold)
{
    cout << "Caricamento della stiva" << endl;

    hold.push_back("vino");
    hold.push_back("lana");
    hold.push_back("avorio");
    hold.push_back("legno");
}

void accidentalDrop(Hold& hold)
{
    cout << "L'ultimo carico di merce cade accidentalmente in mare" << endl;

    hold.pop_back();
}

void friendGift(Hold& hold)
{
    const string GIFT_NAME = "té";

    cout << "Un mercante amico dona " << GIFT_NAME << endl;

    hold.push_back(GIFT_NAME);
}

void marketExchange(Hold& hold)
{
    const string GIVEN_GOOD = "lana";
    const string RECEIVED_GOOD = "frumento";

    cout << "Scambio " << GIVEN_GOOD << " in cambio di " << RECEIVED_GOOD << endl;

    vector<string>::iterator iter = find(hold.begin(), hold.end(), GIVEN_GOOD);
    if (iter != hold.end())
    {
        (*iter) = RECEIVED_GOOD;
    }
}

void pirateAttack(Hold& hold)
{
    const string STOLEN_GOOD = "vino";

    cout << "I pirati rubano " << STOLEN_GOOD << endl;

    vector<string>::iterator iter = find(hold.begin(), hold.end(), STOLEN_GOOD);
    if (iter != hold.end())
    {
        hold.erase(iter);
    }
}

void orderMania(Hold& hold)
{
    cout << "Mania dell'ordine" << endl;

    sort(hold.begin(), hold.end());
}

void tempest(Hold& hold)
{
    cout << "Una tempesta mette in disordine la stiva" << endl;

    random_shuffle(hold.begin(), hold.end(), getRandomNumberGenerator);
}

void sellAll(Hold& hold)
{
    const string RECEIVED_GOOD = "oro";

    cout << "Vendi tutto in cambio di " << RECEIVED_GOOD << endl;

    hold.clear();
    hold.push_back(RECEIVED_GOOD);
}

int getRandomNumberGenerator (int i)
{
    return rand()%i;
}


