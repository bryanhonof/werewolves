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
