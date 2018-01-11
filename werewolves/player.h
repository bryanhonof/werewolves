#ifndef PLAYER_H
#define PLAYER_H

#include "roles.h"
#include <string>

namespace miller {

class player {

friend class game;
friend class card;
friend class cupid;

public:
    player(std::string name, std::string passwd, bool isAI)
        : name(name), passwd(passwd), isAI(isAI) {}
#ifndef DEBUG
    ~player() {}
#else
    ~player() { cout << "player::~player() at: " << this << endl; }
#endif
    inline ROLE getRole() const { return this->role; }
    void setRole(ROLE asignedRole) { this->role = asignedRole; }
    void setLover(player &lover) { this->inLoveWith = &lover;}
    std::string getName() const { return name; }
#ifdef DEBUG
    string getPasswd() { return passwd; } // No security issue here...
#endif

private:
    std::string name = "";
    std::string passwd = "";
    ROLE role = NA;
    player *inLoveWith = nullptr;
    bool major = 0;
    bool isAI = 0;
    bool isDead = 0;
    unsigned char hang = 0;
};
}

#endif // PLAYER_H
