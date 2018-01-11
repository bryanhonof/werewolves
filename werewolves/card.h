#ifndef CARD_H
#define CARD_H

#include "roles.h"
#include "player.h"
#include <string>

namespace miller {
class card {
public:
    card();
    ~card();

    inline std::string roleToString(player *playerObj = nullptr) const;
    inline std::string roleToString(ROLE role = NA) const;
};

inline std::string card::roleToString(player *playerObj) const
{
    switch (playerObj->getRole()) {
    case TOWNFOLKS:
        return "TOWNFOLKS";
        break;
    case WEREWOLVES:
        return "WEREWOLVES";
        break;
    case SEER:
        return "SEER";
        break;
    case WITCH:
        return "WITCH";
        break;
    case THIEF:
        return "THIEF";
        break;
    case LITTLE_GIRL:
        return "LITTLE GIRL";
        break;
    case HUNTER:
        return "HUNTER";
        break;
    case CUPID:
        return "CUPID";
        break;
    case SHERIFF:
        return "SHERIFF";
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

inline std::string card::roleToString(ROLE role) const
{
    switch (role) {
    case TOWNFOLKS:
        return "TOWNFOLKS";
        break;
    case WEREWOLVES:
        return "WEREWOLVES";
        break;
    case SEER:
        return "SEER";
        break;
    case WITCH:
        return "WITCH";
        break;
    case THIEF:
        return "THIEF";
        break;
    case LITTLE_GIRL:
        return "LITTLE GIRL";
        break;
    case HUNTER:
        return "HUNTER";
        break;
    case CUPID:
        return "CUPID";
        break;
    case SHERIFF:
        return "SHERIFF";
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

}

#endif // CARD_H
