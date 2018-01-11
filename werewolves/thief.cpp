#include "thief.h"

using namespace miller;

thief::thief()
{

}

ROLE thief::chooseCard()
{
    card cards;

    ROLE card1 = static_cast<ROLE>(rand() % 0x8 + 0x1);
    ROLE card2 = static_cast<ROLE>(rand() % 0x8 + 0x1);

    unsigned char choise = 0;

    std::cout << "Your first option is: \t" << cards.roleToString(card1) << endl;
    std::cout << "Your second option is: \t" << cards.roleToString(card2) << endl;

    cin >> choise;

    if (choise == '1') {
        return card1;
    } else if (choise == '2') {
        return card2;
    } else {
        cout << "error chose card1 for you..." << endl;
        return card1;
    }
}
