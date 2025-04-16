#ifndef EFFECTS_HPP
#define EFFECTS_HPP
#include "effect.hpp"

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
