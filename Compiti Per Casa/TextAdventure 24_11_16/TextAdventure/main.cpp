#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int choice;
    char input;
    bool win = false;
    do
    {
        input = 'n';
        do
        {
            cout << "You wake up in the middle of a dark castle.\n\n1.Look around\n2.Look at the suits of armor\n3.Go in the catacombs\n4.Go in the master chamber\n\nYour choice: ";
            cin >> choice;
            system("CLS");
        }
        while(choice < 1 || choice > 4);
        switch(choice)
        {
            case 1:
                cout << "As you were looking around for things to do, a huge chandelier falls on you and kills you instantly!\n";
                break;
            case 2:
                cout << "The armors dislike being looked at! They chop you up into tiny pieces!\n";
                break;
            case 3:
                cout << "The catacombs are infested by the undead! They eat you up!\n";
                break;
            case 4:
                cout << "Inside the master chamber you find the lord of this mansion. After you beg and cry, he decides to exile you to the dungeon!\n";
                win = true;
                break;
        }
        if(win == true)
        {
            win = false;
            do
            {
                cout << "You're in the dungeon, where everyone gets lost! What do you do?\n\n1.Go Left\n2.Go Right\n3.Cry for help\n4.Stand still\n\nYour choice: ";
                cin >> choice;
                system("CLS");
            }
            while(choice < 1 || choice > 4);
            switch(choice)
            {
                case 1:
                    cout << "Left seems to lead the wrong way! You've fallen into the Pig Demon's pit! His stench kills you instantly!\n";
                    break;
                case 2:
                    cout << "You remember a trick! If you always follow the right path, you can't get lost! You get out of the dungeon, but end up in the middle of a dwarven pub!\n";
                    win = true;
                    break;
                case 3:
                    cout << "Your screams attract a hungry lion! He chases you and hunts you down!\n";
                    break;
                case 4:
                    cout << "You stand still until you're nothing but bones!\n";
                    break;
            }
            if(win == true)
            {
                win = false;
                do
                {
                    cout << "You're in a dwarven pub, where several drunken dwarfs and adventurers are partying! How do you get out of this one?\n\n1.Walk out of the door.\n2.Get a drink\n3.Start a bar fight.\n4.Befriend a female dwarf.\n\nYour choice: ";
                    cin >> choice;
                    system("CLS");
                }
                while(choice < 1 || choice > 4);
                switch(choice)
                {
                    case 1:
                        cout << "If only it were that easy! A burly dwarf decides it would be fun to snap your spinal chord in half, and proceeds to do so with relative ease!\n";
                        break;
                    case 2:
                        cout << "Bad move! This dwarven ale is too strong for your feeble human body! The solution melts its way down your to your feet!\n";
                        break;
                    case 3:
                        cout << "You make an adventurer and a dwarf fight over a bag of coins, and after a little while, the whole tavern has transformed into an all out brawl! You try to sneak out during the confusion, but a dwarf picks you up by your back and hurls you out of the tavern! You've managed to escape!\n";
                        win = true;
                        break;
                    case 4:
                        cout << "You're swooned over by a dwarven maiden! You spend the night together, but it turns out to be a bad move, as her 'lower beard' was not very clean! The STD you contracted was so strong it made your balls explode!\n";
                        break;
                }
            }
        }
        if(win == true)
        {
            cout << "You Win!! Good Job!!\n";
        }
        else
        {
            cout << "You died! Sorry!\n";
            do
            {
                cout << "Do you wish to play again?\ny/n\n\nYour choice: ";
                cin >> input;
                system("CLS");
            }
            while(input!='y'&&input!='n');
        }
    }
    while(input=='y');
    return 0;
}
