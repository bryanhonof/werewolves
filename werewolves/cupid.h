#ifndef CUPID_H
#define CUPID_H

#include <vector>
#include "card.h"
#include "game.h"

namespace miller {
class cupid : public card {
friend class game;

public:
    cupid();
    ~cupid();

private:
    void arrowOfLove(unsigned char select1, unsigned char select2);
};
}

#endif // CUPID_H
