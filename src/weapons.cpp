#include "game.hpp"

Sword :: Sword(int dmg, int def):
    Weapon("Sword",  dmg, def)
{
}

Sword :: Sword():
    Weapon("Sword", 10, 3)
{
}

Sword :: ~Sword()
{
}

void Sword :: atkEffect(Player* owner, Player* target)
{
    target->addEffect(new BrokenDefense());
}

void Sword :: defEffect(Player* owner)
{
    owner->addEffect(new DamageIncrease(1, 2));
}

void Sword :: empEffect(Player* owner)
{
    owner->addEffect(new NecessarySacrifice());
}
