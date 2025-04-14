#include "game.hpp"

AI :: AI(): entity(nullptr)
{
}

void AI :: setEntity(Player* newEntity)
{
    entity = newEntity;
}

void AI :: setTarget(Player* newTarget)
{
    target = newTarget;
}

void AI :: chooseAction()
{
    entity->setAction(static_cast<Action>(rand() % 3));
}
