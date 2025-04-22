#ifndef EFFECTS_HPP
#define EFFECTS_HPP
#include "effect.hpp"

/**
    \brief A class used to temporarily reduce a character's armor.
    
    Default field values: defenseReduction = 2, duration = 2.
*/

class BrokenDefense : public Effect
{
    private:
        int defenseReduction;
    public:
        BrokenDefense(int defRed, unsigned dur);
        BrokenDefense();
        ~BrokenDefense() override;
        void apply(Player* target) override;
        void revert(Player* target) override;
};

/**
    \brief A class used to temporarily increase a character's damage.
    
    Default field values: damageMagnification = 2, duration = 2.
*/

class DamageIncrease : public Effect
{
    private:
       int damageMagnification;
    public:
       DamageIncrease(int dmgMagn, unsigned dur);
       DamageIncrease();
       ~DamageIncrease() override;
       void apply(Player* target) override;
       void revert(Player* target) override;
};

/**
    \brief A class used to temporarily increase a character's damage in exchange for their health.
    
    When effect applied character gets damage boost. When effect wears off player gets damage.
    Default field values: damageMagnification = 2, healthReduction = 4, duration = 2.
*/

class NecessarySacrifice : public Effect
{
    private:
        int damageMagnification;
        int healthReduction;
    public:
        NecessarySacrifice(int dmgMagn, int hpRed, unsigned dur);
        NecessarySacrifice();
        ~NecessarySacrifice() override;
        void apply(Player* target) override;
        void revert(Player* target) override;
};

#endif
