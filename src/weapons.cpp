#include "game.hpp"

Sword :: Sword(int dmg, int def):
    Weapon("Sword",  dmg, def)
{
}

Sword :: Sword():
    Weapon("Sword", 3, 3)
{
}

void Sword :: atkEffect(Player* owner, Player* target)
{
    target->changeHealth(-this->getDamage());
}

void Sword :: defEffect(Player* owner)
{
    owner->changeHealth(this->getDefense());
}

void Sword :: empEffect(Player* owner)
{
    owner->changeDamage(2);
}
