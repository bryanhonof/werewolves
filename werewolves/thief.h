#ifndef THIEF_H
#define THIEF_H

#include "card.h"
#include "roles.h"
#include <iostream>

using namespace std;

namespace miller {
class thief : public card {
friend class game;

public:
    thief();

private:
    ROLE chooseCard ();
};
}

#endif // THIEF_H
