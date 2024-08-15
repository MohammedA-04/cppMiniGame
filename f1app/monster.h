#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
public:
    Monster(int hp); // Constructor

    void takeDamage(int damage); // Method to take damage

    bool isMonsterAlive() const; // Method to check if the monster is alive

    int getHp() const; // Method to get the current HP

    void setHp(int hp); // sets monsta hp

private:
    int hp; // Health points
};

#endif // MONSTER_H
