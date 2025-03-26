#include "player.hpp"

Weapon :: Weapon(std :: string name, int dmg, int def):
    name(name), damage(dmg), defense(def)
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

void revertStats(Player* owner)
{
    /*to be done*/
}

