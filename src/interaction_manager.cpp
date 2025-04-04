#include "game.hpp"

InteractionManager :: InteractionManager()
{
}

void InteractionManager :: setPlayerAction(Action act)
{
    playerAction = act;
}

void InteractionManager :: setEnemyAction(Action act)
{
    enemyAction = act;
}

void InteractionManager :: resolveInteractions(Player* player, Player* enemy)
{
    switch(static_cast<int>(playerAction))
    {
        case 0:
            player->attack(enemy);
            break;
        case 1:
            player->guard();
            break;
        case 2:
            player->empower();
            break;
    }
    
    switch(static_cast<int>(enemyAction))
    {
        case 0:
            enemy->attack(player);
            break;
        case 1:
            enemy->guard();
            break;
        case 2:
            enemy->empower();
            break;
    }
}
    
    
    
    
    
    
    
