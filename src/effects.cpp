#include "game.hpp"

/* BROKEN DEFENSE */

BrokenDefense :: BrokenDefense(int defRed, unsigned dur):
    Effect("Broken defense", "defense decreased by " + std :: to_string(defRed), dur),
    defenseReduction(defRed)
{
}

BrokenDefense :: BrokenDefense():
    Effect("Broken defense", "defense decreased by 2", 2), defenseReduction(2)
{
}

BrokenDefense :: ~BrokenDefense()
{
}

void BrokenDefense :: apply(Player* target)
{
    target->changeDefense(-defenseReduction);
}

void BrokenDefense :: revert(Player* target)
{
    target->changeDefense(defenseReduction);
}

/* DAMAGE INCREASE */

DamageIncrease :: DamageIncrease(int dmgMagn, unsigned dur):
    Effect("Damage increase", "damage increased by " + std :: to_string(dmgMagn), dur),
    damageMagnification(dmgMagn)
{
}

DamageIncrease :: DamageIncrease():
    Effect("Damage increase", "damage increased by 2", 2),
    damageMagnification(2)
{
}

DamageIncrease :: ~DamageIncrease()
{
}

void DamageIncrease :: apply(Player* target)
{
    target->changeDamage(damageMagnification);
}

void DamageIncrease :: revert(Player* target)
{
    target->changeDamage(-damageMagnification);
}

/* NECESSARY SACRIFICE */

NecessarySacrifice :: NecessarySacrifice(int dmgMagn, int hpRed, unsigned dur):
    Effect("Necessary sacrifice", "damage increased by " + std :: to_string(dmgMagn) + ", target takes " + std :: to_string(hpRed) + " when effect wears off", dur),
    damageMagnification(dmgMagn), healthReduction(hpRed)
{
}

NecessarySacrifice :: NecessarySacrifice():
    Effect("Necessary sacrifice", "damage increased by 2, target takes 4 damage when effect wears off", 2),
    damageMagnification(2), healthReduction(4)
{
}

NecessarySacrifice :: ~NecessarySacrifice()
{
}

void NecessarySacrifice :: apply(Player* target)
{
    target->changeDamage(damageMagnification);
}

void NecessarySacrifice :: revert(Player* target)
{
    target->changeDamage(-damageMagnification);
    target->changeHealth(-healthReduction);
}

