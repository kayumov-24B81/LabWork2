#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "weapon.hpp"

class Player
{
    private:
        std :: string name;
        int health;
        int damage;
        int defense;
        Weapon* weapon;
    public:
        Player(std :: string name);
        std :: string getName();
        int getHealth();
        int getDamage();
        int getDefense();
        void changeHealth(int hp);
        void changeDamage(int dmg);
        void changeDefense(int def);
};

#endif
