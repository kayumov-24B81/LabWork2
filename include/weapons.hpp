#ifndef WEAPONS_HPP
#define WEAPONS_HPP

#include "weapon.hpp"

/**
    \brief Child weapon class. The only weapon class for now.
    
    This weapon applies "Broken Defense" with default fields values effect on attack, "Damage Increase" with damage magnification of 1 and duration of 2 on guard and "Necessary sacrifice" with default field values on empower.
    Default fields values are: damage = 10, defense = 3.

*/

class Sword : public Weapon
{
    public:
        Sword(int dmg, int def);
        Sword();
        ~Sword() override;
        void atkEffect(Player* owner, Player* target) override;
        void defEffect(Player* owner) override;
        void empEffect(Player* owner) override;
};

#endif
        
