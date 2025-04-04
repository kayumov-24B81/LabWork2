#ifndef WEAPONS_HPP
#define WEAPONS_HPP

#include "weapon.hpp"

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
        
