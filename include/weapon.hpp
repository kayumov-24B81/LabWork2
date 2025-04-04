#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "effects.hpp"

class Weapon
{
    private:
        std :: string name;
        int damage;
        int defense;
    public:
        Weapon(std :: string name, int dmg, int def);
        virtual ~Weapon();
        std :: string getName();
        int getDamage();
        int getDefense();
        virtual void atkEffect(Player* owner, Player* target) = 0;
        virtual void defEffect(Player* owner) = 0;
        virtual void empEffect(Player* owner) = 0;
        void updateStats(Player* owner);
        void revertStats(Player* owner);
};

#endif
