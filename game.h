#ifndef GAME_H
#define GAME_H

#include "global.h"
#include "cards.h"
#include "player.h"

namespace miller {
    class game {
    friend class cards;

    public:
        game();
        unsigned char playersInGame();

    protected:
        bool time;

    private:
        unsigned char day = 0;
        std::vector<player *> players;

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

        void setNight();
        void setDay();
        void mainMenu();
        void mainArt();
        void playersArt(unsigned char players);
        void addPlayer(player *newPlayer);
        void assignRole();
    };
}

#endif // GAME_H
