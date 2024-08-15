#include "player.h"
#include <cstdlib> // for std::rand
#include <ctime>   // for std::time

// Implementation of the attack method
int Player::attack() const {
    return std::rand() % 151; // Random damage between 0 and 150
}
