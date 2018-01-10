#include "game.h"

using namespace miller;

game::game() //constructor
{
    mainMenu();
    assignRole();
}

void game::setNight() //self explanatory
{
    time = 1;
    cout << "It is now night" << endl;
    return;
}

void game::setDay() //self explanatory
{
    time = 0;
    cout << "It is now day" << endl;
    return;
}

void game::mainMenu() //display the main menu screen on start up and
                      //handle user input
{
    bool gameStart = 0;
    string name = "";
    string passwd = "";
    static unsigned char playerCount = 0;

    mainArt();

    while (gameStart == 0) {
        unsigned char input = '0';
        cin >> input;

        switch (input) {
        case '1': //sart game
            gameStart = 1;
            if (players.size() != 24) {
                for (int i = 0; players.size() != 24; i++) {
                    string name = "AI";
                    addPlayer(new player(name, "AI"));
                }
            }
            break;

        case '2': //add new players
            if (players.size() < 24) {
                cout << "Name: "; cin >> name;
                cout << "Password: "; cin >> passwd;
                playerCount++;
                addPlayer(new player(name, passwd));
                mainArt();
            } else {
                cout << "Max amount of players reached" << endl;
                system("PAUSE");
                mainArt();
            }
            break;

        case '3': //list currently added players
            playersArt(playerCount);
            mainArt();
            break;

        case '4': //exit
            return;
        }
    }
    return;
}

void game::mainArt() //self explanatory
{
    system("CLS");

    cout << endl;
    cout << "+++++++++++[The Werewolves of Millers Hollow]+++++++++++" << endl;
    cout << "+                                                      +" << endl;
    cout << "+                      1. Start                        +" << endl;
    cout << "+                      2. Add Player                   +" << endl;
    cout << "+                      3. List players                 +" << endl;
    cout << "+                      4. Exit                         +" << endl;
    cout << "+                                                      +" << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << endl;
    return;
}

void game::playersArt(unsigned char playerCount)
{
    system("CLS");

    cout << +playerCount << endl;

    for (int i = 0; i < playerCount; i++) {
        cout << "NAME : " << players[i]->getName() << "\n";
#ifdef DEBUG
        cout << "PSWD : " << players[i]->getPasswd() << "\n";
#endif
        cout << "\n";
    }

    system("PAUSE");
    return;
}

void game::addPlayer(player *newPlayer) //self explanatory
{
    players.push_back(newPlayer);
    return;
}

void game::assignRole()
{
    for (unsigned int i; i < players.size(); i++) {
        unsigned char tmp = rand() % players.size();

        if (players[tmp]->getRole() != NA)  {
            i--;
        } else if (players[tmp]->getRole() == NA && ingame.werewolves < 4) {
            players[tmp]->setRole(WEREWOLVES);
            ingame.werewolves++;
        } else if (players[tmp]->getRole() == NA && ingame.townfolks < 12) {
            players[tmp]->setRole(TOWNFOLKS);
            ingame.townfolks++;
        } else if (players[tmp]->getRole() == NA && !ingame.witch) {
            players[tmp]->setRole(WITCH);
            ingame.witch++;
        } else if (players[tmp]->getRole() == NA && !ingame.thief) {
            players[tmp]->setRole(THIEF);
            ingame.thief++;
        } else if (players[tmp]->getRole() == NA && !ingame.little_girl) {
            players[tmp]->setRole(LITTLE_GIRL);
            ingame.little_girl++;
        } else if (players[tmp]->getRole() == NA && !ingame.hunter) {
            players[tmp]->setRole(HUNTER);
            ingame.hunter++;
        } else if (players[tmp]->getRole() == NA && !ingame.cupid) {
            players[tmp]->setRole(CUPID);
            ingame.cupid++;
        } else if (players[tmp]->getRole() == NA && !ingame.seer) {
            players[tmp]->setRole(SEER);
            ingame.seer++;
        } else if (players[tmp]->getRole() == NA && !ingame.sheriff) {
            players[tmp]->setRole(SHERIFF);
            ingame.sheriff++;
        } else {
            // Do nothing :3
        }
    }
#ifdef DEBUG
    for (unsigned int i = 0; i < players.size(); i++) {
        cout << "Name: " << players[i]->getName() << "\t";
        cout << "Role: " << players[i]->getRole() << endl;
    }
#endif
    return;
}

unsigned char game::playersInGame()
{
    return players.size();
}
