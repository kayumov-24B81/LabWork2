#include "player.hpp"

Player :: Player(std :: string name):
    name(name), health(20), damage(0), defense(0), weapon(nullptr)
{
}

std :: string Player :: getName()
{
    return name;
}

int Player :: getHealth()
{
    return health;
}

int Player :: getDamage()
{
    return damage;
}

int Player :: getDefense()
{
    return defense;
}

void Player :: changeHealth(int hp)
{
    health += hp;
}

void Player :: changeDamage(int dmg)
{
    damage += dmg;
}

void Player :: changeDefense(int def)
{
    defense += def;
}









