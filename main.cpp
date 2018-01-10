#include <iostream>
#include "game.h"


using namespace miller;

int main(/*int argc, char *argv[]*/)
{
    cout << "Buy the ""NEW MOON"" DLC now for only $99.99!" << endl;
    srand((unsigned)time(NULL));
    game Game;
#ifdef DEBUG
    cout << "Players in game: "<< static_cast<int>(Game.playersInGame()) << endl;
#endif
    return 0;
}
