#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "effects.hpp"

/**
    \brief Parent class for various weapons. This class and its subclasses are responsible for applying effects when certain actions occur and changing the characteristics of the wearer.
    
    Weapons will increase the wearer stats when equipped and revert when removed using the coressponding functions. This class has virtual methods for each possible player action that generally aplly effects on target or owner. Destructor is virtual too.
*/

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
