#include "monster.h"

// Constructor implementation
Monster::Monster(int hp) : hp(hp) {}

// Method to take damage
void Monster::takeDamage(int damage) {
    hp = hp - damage;
    if (hp < 0) {
        hp = 0;
    }
}

// Method to check if the monster is alive
bool Monster::isMonsterAlive() const {
    return hp > 0;
}

// Method to get the current HP
int Monster::getHp() const {
    return hp < 0 ? 0 : hp; // return 0 if negative
}

void Monster::setHp(int hpArg) {
    hp = hpArg;

}
