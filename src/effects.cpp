#include "game.hpp"

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
