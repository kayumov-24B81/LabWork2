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

void InteractionManager :: attackOnGuard(Player* attacker, Player* defender)
{
    if(rand() % 2 == 0)
    {
        defender->guard();
        attacker->attack(defender);
    }
}

void InteractionManager :: attackOnEmpower(Player* attacker, Player* empowerer)
{
    attacker->attack(empowerer);
    if(rand() % 2 == 0)
    {
        empowerer->empower();
    }
}

void InteractionManager :: attackOnAttack(Player* player1, Player* player2)
{
    if(rand() % 2 == 0)
    {
        player1->attack(player2);
    }
    else
    {
        player2->attack(player1);
    }
}

void InteractionManager :: resprite(Player* player1, Player* player2)
{
    player1->changeHealth(player2->getDefense());
    player2->changeHealth(player1->getDefense());
}

void InteractionManager :: resolveInteractions(Player* player, Player* enemy)
{
    if(playerAction == enemyAction)
    {
        if(playerAction == ATTACK)
        {
            attackOnAttack(player, enemy);
            return;
        }
        if(playerAction == GUARD)
        {
            resprite(player, enemy);
            player->guard();
            enemy->guard();
            return;
        }
        if(playerAction == EMPOWER)
        {
            resprite(player, enemy);
            player->empower();
            enemy->empower();
            return;
        }
    }
    else
    {
        if(playerAction == ATTACK and enemyAction == GUARD)
        {
            attackOnGuard(player, enemy);
            return;
        }
        if(playerAction == GUARD and playerAction == ATTACK)
        {
            attackOnGuard(enemy, player);
            return;
        }
        if(playerAction == EMPOWER and enemyAction == GUARD)
        {
            resprite(player, enemy);
            player->empower();
            enemy->guard();
            return;
        }
        if(playerAction == GUARD and enemyAction == EMPOWER)
        {
            resprite(player, enemy);
            player->empower();
            enemy->guard();
            return;
        }
        if(playerAction == ATTACK and enemyAction == EMPOWER)
        {
            attackOnEmpower(player, enemy);
            return;
        }
        if(playerAction == EMPOWER and enemyAction == ATTACK)
        {
            attackOnEmpower(enemy, player);
            return;
        }
            
    }
}
    
    
    
    
    
    
    
