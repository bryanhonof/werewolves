#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"
#include "game.h"

namespace miller {
enum ROLE {
    NA          = 0x0,
    TOWNFOLKS   = 0x1,
    WEREWOLVES  = 0x2,
    SEER        = 0x3,
    WITCH       = 0x4,
    THIEF       = 0x5,
    LITTLE_GIRL = 0x6,
    HUNTER      = 0x7,
    CUPID       = 0x8,
    SHERIFF     = 0x9
};

class player {

friend class game;

public:
    player(string name, string passwd) : name(name), passwd(passwd) {}
    ROLE getRole() { return this->role; }
    void setRole(ROLE asignedRole) { this->role = asignedRole; }
    string getName() { return name; }
#ifdef DEBUG
    string getPasswd() { return passwd; } //No security issue here...
#endif
private:
    string name = "";
    string passwd = "";
    ROLE role = NA;
    bool major = 0;
};
}

#endif // PLAYER_H
