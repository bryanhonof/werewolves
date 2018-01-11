#ifndef GAME_H
#define GAME_H

#include "global.h"
#include "player.h"
#include "card.h"
#include "thief.h"
#include "cupid.h"

namespace miller {
class game {
friend class cupid;
public:
    game();
    ~game();
    unsigned char playersInGame();
    void startGame();

protected:
    bool time;

private:
    struct InGame {
        unsigned char townfolks = 0;
        unsigned char werewolves = 0;
        unsigned char witch = 0;
        unsigned char thief = 0;
        unsigned char little_girl = 0;
        unsigned char hunter = 0;
        unsigned char cupid = 0;
        unsigned char seer = 0;
        unsigned char sheriff = 0;
    } ingame;

    unsigned char day = 0;
    std::vector<player *> players;
    void setNight();
    void setDay();
    void mainMenu();
    void mainArt() const;
    void playersArt(unsigned char players) const;
    void addPlayer(player *newPlayer);
    void assignRole();
    player &gameHost();
    unsigned char checkIfWin() const;
};
}

#endif // GAME_H
