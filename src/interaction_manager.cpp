#include "game.hpp"

InteractionManager :: InteractionManager():
    logs(nullptr)
{
}

InteractionManager :: ~InteractionManager()
{
    delete logs;
}

void InteractionManager :: setLogs(LogManager* log)
{
    logs = log;
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
        logs->addGuardMessage(defender);
        logs->addAttackMessage(attacker, defender);
    }
}

void InteractionManager :: attackOnEmpower(Player* attacker, Player* empowerer)
{
    attacker->attack(empowerer);
    logs->addAttackMessage(attacker, empowerer);
    if(rand() % 2 == 0)
    {
        empowerer->empower();
        logs->addEmpowerMessage(empowerer);
        return;
    }
}

void InteractionManager :: attackOnAttack(Player* player1, Player* player2)
{
    if(rand() % 2 == 0)
    {
        player1->attack(player2);
        logs->addAttackMessage(player1, player2);
    }
    else
    {
        player2->attack(player1);
        logs->addAttackMessage(player2, player1);
    }
}

void InteractionManager :: resprite(Player* player1, Player* player2)
{
    player1->changeHealth(player1->getDefense());
    player2->changeHealth(player2->getDefense());
    logs->addHealingMessage(player1, player1->getDefense());
    logs->addHealingMessage(player2, player2->getDefense());
}

void InteractionManager :: resolveEffects(Player* player)
{
    std :: vector<Effect*> effects = player->getEffectsWaitList();
    for(Effect* effect : effects)
    {
        logs->addEffectMessage(player, effect);
    }
}

void InteractionManager :: resolveInteractions(Player* player, Player* enemy)
{
    logs->clearLogs();
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
            logs->addGuardMessage(player);
            logs->addGuardMessage(enemy);
            return;
        }
        if(playerAction == EMPOWER)
        {
            resprite(player, enemy);
            player->empower();
            enemy->empower();
            logs->addEmpowerMessage(player);
            logs->addEmpowerMessage(enemy);
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
        if(playerAction == GUARD and enemyAction == ATTACK)
        {
            attackOnGuard(enemy, player);
            return;
        }
        if(playerAction == EMPOWER and enemyAction == GUARD)
        {
            resprite(player, enemy);
            player->empower();
            enemy->guard();
            logs->addEmpowerMessage(player);
            logs->addGuardMessage(enemy);
            return;
        }
        if(playerAction == GUARD and enemyAction == EMPOWER)
        {
            resprite(player, enemy);
            player->guard();
            enemy->empower();
            logs->addGuardMessage(player);
            logs->addEmpowerMessage(enemy);
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
    
std :: vector<std :: string> InteractionManager :: getLogs()
{
    return logs->getLogs();
}
    
    
    
    
    
