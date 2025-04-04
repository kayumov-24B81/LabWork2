#include "player.hpp"

Weapon :: Weapon(std :: string name, int dmg, int def):
    name(name), damage(dmg), defense(def)
{
}

Weapon :: ~Weapon()
{
}

std :: string Weapon ::  getName()
{
    return name;
}

int Weapon ::  getDamage()
{
    return damage;
}

int Weapon :: getDefense()
{
    return defense;
}

void updateStats(Player* owner)
{
    owner->changeDefense(defense);
    owner->changeDamage(damage);
}

void revertStats(Player* owner)
{
    owner->changeDefense(-defense);
    owner->changeDamage(-damage);
}

