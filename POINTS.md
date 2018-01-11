# Points list
- [x] useful class
- [ ] correct base class
- [ ] correct inheritance
- [x] seperate header files
- [ ] useful virtual function
- [x] useful polymorfism
- [ ] correct abstract base class
- [ ] no mistake in object-oriented programming
- [x] useful member function
- [x] useful member variabel
- [ ] correct protections
- [x] getters and setters for member variables
- [x] at least 2 default constructors
- [x] at least 2 specific constructors
- [x] at least 2 destructors
- [x] useful container class
- [ ] useful Qt class
- [x] clean main (i.e. nothing in the main that shoud be in a class)
- [ ] operator overloading
- [x] useful pointer usage
- [x] useful string usage
- [x] dynamic memory allocation (new)
- [x] dynamic memory removing (delete)
- [x] at least 4 useful const
- [x] at least 4 useful bool
- [x] 2 unsigned chars or other better usage of memory efficient type
- [ ] template function or class
- [ ] 2 (modern) call-by-references
- [x] everything in one or more self-made namespace(s)
- [x] default values in function definition
- [ ] function overloading
- [x] useful useage of this
- [x] no globals, but statics if needed
- [x] friend function or class
- [x] maintanability by good function naming and/or comments everywhere
- [ ] useful usage of stringstreams
- [ ] using the correct type on a lot of places (almost everywhere possible)
- [ ] correctly using const on a lot of places (almost everywhere possible)
- [x] correct useage of inline function
- [x] useful recursive function
- [ ] non-type template arguments
- [x] useful usage of nullptr
- [ ] useful usage of (modern) file-I/O
- [ ] correct usage of command line parameters
- [x] useful usage of struct
- [ ] nesting of classes
- [ ] useful usage of union
- [x] useful usage of enum
- [ ] multiple inheritance
- [x] member initialization in constructors
- [ ] useful usage of signals/slots
- [ ] useful network communication
- [ ] useful usage of threads
- [ ] robust program that has been extensively tested (proof it)
- [ ] one complete project that compiles and does not crash
- [ ] usage of a GUI
- [ ] usage of OpenGL or other 3D engine
- [ ] useful usage of an external library
- [ ] project that works with hardware
- [x] a nice extra that you think that should deserve grading (stuff you put time in and is not rewarded by an item above)

--------------------------------------------------------------------------------------------------------------------------

## userfull class
in game.h
```cpp
class game {
friend class cupid;
public:
    game();
    ~game();
    unsigned char playersInGame();
    void startGame();
```
## seperate header files
Header files enough

## userfull polyforfism
in card.h
```cpp
    inline std::string roleToString(player *playerObj) const;
    inline std::string roleToString(ROLE role) const;
```

## useful member function
in player.h
```cpp
    inline ROLE getRole() const { return this->role; }
    void setRole(ROLE asignedRole) { this->role = asignedRole; }
    void setLover(player &lover) { this->inLoveWith = &lover;}
    std::string getName() const { return name; }
```

## useful member variabel
in player.h
```cpp
private:
    std::string name = "";
    std::string passwd = "";
    ROLE role = NA;
    player *inLoveWith = nullptr;
    bool major = 0;
    bool isAI = 0;
    bool isDead = 0;
    unsigned char hang = 0;
```

## getters and setters for member variables
in player.h
```cpp
    void setRole(ROLE asignedRole) { this->role = asignedRole; }
    void setLover(player &lover) { this->inLoveWith = &lover;}
```

## at least 2 default constructors
in card.h & hunter.h
```cpp
class card {
public:
    card();
    
class hunter {
public:
    hunter();
```

## at least 2 specific constructors
in player.h
```cpp
    player(std::string name, std::string passwd, bool isAI)
        : name(name), passwd(passwd), isAI(isAI) {}      
```
in game.cpp
```cpp
game::game() // constructor
{
    mainMenu();
    assignRole();
}
```

## at least 2 destructors
almost everywhere
```cpp
Almost every class has a destructor, and there are at LEAST 2 classes.
```

## userfull container class
in game.h
```cpp
std::vector<player *> players;
```

## clean main
in main.cpp
```cpp
#include "global.h"
#include "game.h"

using namespace miller;

int main(/*int argc, char *argv[]*/)
{
    srand((unsigned)time(NULL));

    auto gameObj = new game;

#ifdef DEBUG
    cout << "Players in game: "<< static_cast<int>(gameObj->playersInGame()) << endl;
#endif

    gameObj->startGame();

    delete gameObj;

    return 0;
}
```
## usefull pointer usage
pointer everywhere

## userfull string usage
in player.h
```cpp
    std::string name = "";
    std::string passwd = "";
```

## dynamic memory allocation (new)
in game.cpp
```cpp
        case '1': // sart game
            gameStart = 1;
            if (players.size() != 24) {
                for (int i = 0; players.size() != 24; i++) {
                    string name = "AI " + to_string(i);
                    addPlayer(new player(name, name, 1));
                }
            }
            break;
```

## dynamic memory removing (delete)
in game.cpp
```cpp
game::~game() // deconstructor
{
    for (unsigned int i = 0; i < players.size(); i++) { // Loop trough all the
        delete players[i];                              // created players and
    }                                                   // free the memory.
#ifdef DEBUG
    cout << "game::~game() at: " << this << endl;
#endif
}
```

## at least 4 userful bool
in player.h
```cpp
    bool major = 0;
    bool isAI = 0;
    bool isDead = 0;
```

in game.h
```cpp
protected:
    bool time;
```

## at least 4 useful const 
in game.h
```cpp
    void mainArt() const;
    void playersArt(unsigned char players) const;
```

in player.h
```cpp
    inline ROLE getRole() const { return this->role; }
    std::string getName() const { return name; }
```

## 2 unsigned chars or other better usage of memory efficient type
almost everywhere
in game.h
```cpp
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
```

## everything in one or more self-made namespace(s)
in everything
```cpp
namespace miller { ... }
```

## default values in function definition
in card.h
```cpp
    inline std::string roleToString(player *playerObj = nullptr) const;
    inline std::string roleToString(ROLE role = NA) const;
```

## useful useage of this
in player.h
```cpp
    inline ROLE getRole() { return this->role; }
    void setRole(ROLE asignedRole) { this->role = asignedRole; }
    void setLover(player &lover) { this->inLoveWith = &lover;}
```

## no globals, but statics if needed
in game.cpp
```cpp
    static player *major = nullptr;

    if (players[tmp]->isAI == 1) {
        game::gameHost();
    }
```

## friend function or class
in player.h
```cpp
class player {

friend class game;
friend class card;
friend class cupid;
```

## maintanability by good function naming and/or comments everywhere
Tried to name functions so it says what they do.

## useful recursive function
in game.cpp
```cpp
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
```

## correct useage of inline function
in card.h
```cpp
    inline std::string roleToString(player *playerObj = nullptr) const;
    inline std::string roleToString(ROLE role = NA) const;
```

## useful usage of nullptr
in player.h
```cpp
    player *inLoveWith = nullptr;
```

## useful usage of struct
in game.h
```cpp
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
```

## useful usage of enum
in role.h
```cpp
#ifndef ROLES_H
#define ROLES_H

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

#endif // ROLES_H
```

## member initialization in constructors
in player.h
```cpp
    player(std::string name, std::string passwd, bool isAI)
        : name(name), passwd(passwd), isAI(isAI) {}
```

## nice extra
* Code uploaded to github
* Learnt to work with mercurial SCM
* Learnt to work with Bitbucket instead of github
* Tried working with SDL -> Failed very fk*** hard -> stress 5 hours before deadline -> recode everything
