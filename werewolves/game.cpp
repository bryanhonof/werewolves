#include "game.h"

using namespace miller;

game::game() // constructor
{
    mainMenu();
    assignRole();
}

game::~game() // deconstructor
{
    for (unsigned int i = 0; i < players.size(); i++) { // Loop trough all the
        delete players[i];                              // created players and
    }                                                   // free the memory.
#ifdef DEBUG
    cout << "game::~game() at: " << this << endl;
#endif
}

void game::setNight() // self explanatory
{
    time = 1;
    cout << "It is now night" << endl;
    return;
}

void game::setDay() // self explanatory
{
    time = 0;
    cout << "It is now day" << endl;
    return;
}

void game::mainMenu()     // display the main menu screen on start up and
{                         // handle user input
    bool gameStart = 0;
    string name = "";
    string passwd = "";
    static unsigned char playerCount = 0;

    mainArt();

    while (gameStart == 0) {
        unsigned char input = '0';
        cin >> input;

        switch (input) {
        case '1': // sart game
            gameStart = 1;
            if (players.size() != 24) {
                for (int i = 0; players.size() != 24; i++) {
                    string name = "AI " + to_string(i);
                    addPlayer(new player(name, name, 1));
                }
            }
            break;

        case '2': // add new players
            if (players.size() < 24) {
                cout << "Name: ";
                cin >> name;
                cout << "Password: ";
                cin >> passwd;
                playerCount++;
                addPlayer(new player(name, passwd, 0));
                mainArt();
            } else {
                cout << "Max amount of players reached" << endl;
                system("PAUSE");
                mainArt();
            }
            break;

        case '3': // list currently added players
            playersArt(playerCount);
            mainArt();
            break;

        case '4': // exit
            return;
        }
    }
    return;
}

void game::mainArt() const // self explanatory
{
    system("CLS");
    cout << "Buy the ""NEW MOON"" DLC now for only $99.99!" << endl;
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

void game::playersArt(unsigned char playerCount) const // self explanatory
{
    system("CLS");

    cout << +playerCount << endl;

    for (int i = 0; i < playerCount; i++) {
        cout << "NAME: " << players[i]->getName() << "\t";
#ifdef DEBUG
        cout << "PSWD: " << players[i]->getPasswd() << endl;
#endif
        cout << "\n";
    }

    system("PAUSE");
    return;
}

void game::addPlayer(player *newPlayer) // self explanatory
{
    players.push_back(newPlayer);
    return;
}

void game::assignRole() // Assign roles
{
    for (unsigned int i = 0; i < players.size(); i++) {
        unsigned char tmp = rand() % players.size();

        if (players[tmp]->getRole() != NA)  {
            i--;
        } else if (players[tmp]->getRole() == NA && ingame.werewolves < 4) {
            players[tmp]->setRole(WEREWOLVES);
            ingame.werewolves++;
        } else if (players[tmp]->getRole() == NA && ingame.townfolks < 13) {
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
    system("PAUSE");
#endif
    return;
}

unsigned char game::playersInGame() // Give back the number of players currently
{                                   // in the game
    return players.size();
}

void game::startGame() // Starts the game :P
{
    card cards;
    thief thieves;
    cupid cupido;
    player *major = &gameHost();
    major->major = true;

    system("CLS");
    cout << "Game host is " << major->getName() << endl;
    cout << "Give the PC to the game host." << endl;
    system("PAUSE");

    for (unsigned int i = 0; i < players.size(); i++) {
        if (players[i]->isAI == 0) {
            system("CLS");
            cout << "Ready to show " << players[i]->getName() << "'s role..." << endl;
            system("PAUSE"); system("CLS");
            cout << "Your role is: " << cards.roleToString(players[i]) << endl;
            system("PAUSE");
        }
    }

    system("CLS");
    cout << "Return PC to host..." << endl; system("PAUSE");
    cout << "Ready to start?" << endl;      system("PAUSE");

    while (checkIfWin() == 0) {
        system("CLS");
        cout << "Day: " << static_cast<int>(this->day) << endl;

        if (this->time == 0) { //actions while day
            cout << "ID \t Role \t\tName \t Is dead?" << endl;
            for (unsigned int i = 0; i < players.size(); i++) {
                if (players[i]->major == true)
                    cout << i << "\t [Major]: \t" << players[i]->getName() << "\t Dead? " << players[i]->isDead << endl;
                else
                    cout << i << "\t [Villager]: \t" << players[i]->getName() << "\t Dead? " << players[i]->isDead << endl;
            }

            if (this->day == 0) {
                // First day no votes!
            } else if (this->day > 0) { // VOTE TO HANG!
                for (unsigned int i = 0; i < players.size(); i++) {
                    unsigned char vote = 0;

                    system("CLS");
                    cout << "Pass the PC to " << players[i]->getName() << endl;
                    system("PAUSE");

                    while (!players[i]->major && !players[i]->isDead) {
                        cin >> vote;
                        players[i]->hang++;
                    }
                }
            } else {
                cout << "something went wrong D;";
            }
            system("PAUSE");
            this->setNight();
            // end day
        } else if (this->time == 1) { // actions while night
            if (this->day == 0) { // first night setup
                for (unsigned int i = 0; i < players.size(); i++) {
                    system("CLS");
                    cout << "Pass the PC to " << players[i]->getName() << endl;
                    system("PAUSE");
                    // werewolves don't do anything first night
                    // townfolks are asleep
                    // Thief wakes first night
                    // Cupid makes people fall in love
                    // Lovers get to know each other
                    if (players[i]->getRole() == TOWNFOLKS
                            || players[i]->getRole() == WEREWOLVES
                            || players[i]->getRole() == SEER
                            || players[i]->getRole() == WITCH
                            || players[i]->getRole() == SHERIFF
                            || players[i]->getRole() == HUNTER) {
                        system ("CLS");
                        cout << "You are asleep" << endl;
                        system("PAUSE");
                        system ("CLS");
                    }

                    if (players[i]->getRole() == THIEF) {
                        system ("CLS");
                        ROLE choise = thieves.chooseCard();
                        players[i]->setRole(choise);
                        cout << "You are now a: " << cards.roleToString(players[i]->getRole()) << endl;
                        system ("PAUSE");
                        system ("CLS");
                    }

                    if (players[i]->getRole() == CUPID) {
                        system("CLS");
                        cout << "select your 2 lovers!" << endl;

                        for (unsigned int i = 0; i < players.size(); i++) {
                            cout << i << ": " << players[i]->getName() << endl;
                        }

                        auto select1 = 0;
                        auto select2 = 0;

                        cout << "First lover: "; cin >> select1;
                        cout << endl << "second lover:"; cin >> select2;

                        players[select1]->setLover(*players[select2]);
                        players[select2]->setLover(*players[select1]);

                        cout << players[select1]->inLoveWith->getName() << endl;
                        cout << players[select2]->inLoveWith->getName() << endl;
                        system("PAUSE");
                    }
                }

                for (unsigned int i = 0; i < players.size(); i++) {
                    if (players[i]->inLoveWith != nullptr) {
                        cout << "Pass PC to " << players[i]->getName() << endl;
                        system("PAUSE");
                        cout << players[i]->getName() << " <3 " << players[i]->inLoveWith->getName() << endl;
                        system("CLS");
                    } else if (this->day > 0) {

                    } else {
                        // do nothing
                    }
                }
            this->day++;
            system("PAUSE");
            this->setDay();

            } else {
                cout << "Something went wrong D:" << endl;
            }
        }
    }
}

player &game::gameHost() // Assign the host/major label to a random player
{
    unsigned char tmp = rand() % players.size();
#ifdef DEBUG
    cout << "game::gameHost() trying to make " << players[tmp]->getName() << " a host" << endl;
#endif
    static player *major = nullptr;

    if (players[tmp]->isAI == 1) {
        game::gameHost();
    }
    else
        major = players[tmp];

#ifdef DEBUG
    cout << major << endl;
#endif

    return *major;
}

unsigned char game::checkIfWin() const // Checks if there is a winner
{
    return 0;
}
