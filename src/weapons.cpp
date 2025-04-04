#include "game.hpp"

Sword :: Sword(int dmg, int def):
    Weapon("Sword",  dmg, def)
{
}

Sword :: Sword():
    Weapon("Sword", 3, 3)
{
}

Sword :: ~Sword()
{
}

void Sword :: atkEffect(Player* owner, Player* target)
{
    target->changeHealth(-1 * this->getDamage());
    target->addEffect(new BrokenDefense)());
}

void Sword :: defEffect(Player* owner)
{
    owner->changeHealth(this->getDefense());
}

void Sword :: empEffect(Player* owner)
{
    owner->changeDamage(2);
}
