#include "game.hpp"

InteractionManager :: InteractionManager():
    logs(nullptr)
{
}

InteractionManager :: ~InteractionManager()
{
    delete logs;
}

void InteractionManager :: setLogs(Logger* newLogs)
{
    logs = newLogs;
}

void InteractionManager :: dealDamage(Player* attacker, Player* target)
{
    int damage = 0;
    if(target->getAction() == GUARD)
    {
        damage = static_cast<int>(attacker->getDamage() * (1 - (target->getDefense() / 10.0)));
    }
    else
    {
        damage = attacker->getDamage();
    }
    logs->addEvent(DamageEvent(attacker, target, damage));
    target->changeHealth(-1 * damage);
}

void InteractionManager :: handleExactActions(Player* player, Player* enemy)
{
    if(playerAction == ATTACK)
    {
        logs->addEvent(AttackEvent(player, player));
        logs->addEvent(AttackEvent(enemy, enemy));
        if(rand() % 2 == 0)
        {
            dealDamage(player, enemy);
        }
        else
        {
            dealDamage(enemy, player);
        }
        return;
    }
    if(playerAction == GUARD)
    {
        logs->addEvent(GuardEvent(nullptr, player));
        logs->addEvent(GuardEvent(nullptr, enemy));
        return;
    }
    if(playerAction == EMPOWER)
    {
        logs->addEvent(EmpowerEvent(nullptr, player));
        logs->addEvent(EmpowerEvent(nullptr, enemy));
        return;
    }
}

void InteractionManager :: attackOnGuard(Player* attacker, Player* target)
{
    logs->addEvent(AttackEvent(attacker, target));
    if(rand() % 2 == 0)
    {
        logs->addEvent(GuardEvent(nullptr, target));
        dealDamage(attacker, target);
    }
    else
    {
        logs->addEvent(GuardEvent(attacker, target));
    }
}

void InteractionManager :: attackOnEmpower(Player* attacker, Player* target)
{
    logs->addEvent(AttackEvent(attacker, target));
    if(rand() % 2 == 0)
    {
        logs->addEvent(EmpowerEvent(attacker, target));
    }
    else
    {
        logs->addEvent(EmpowerEvent(nullptr, target));
    }
    dealDamage(attacker, target);
}

void InteractionManager :: guardAndEmpower(Player* guard, Player* empowerer)
{
    logs->addEvent(GuardEvent(nullptr, guard));
    logs->addEvent(EmpowerEvent(nullptr, empowerer));
}

void InteractionManager :: updateEffects(Player* player, Player* enemy)
{
    for(Effect* effect : player->getEffectsWaitList())
    {
        logs->addEvent(EffectEvent(player, effect));
    }
    player->updateEffects();
    for(Effect* effect : enemy->getEffectsWaitList())
    {
        logs->addEvent(EffectEvent(enemy, effect));
    }
    enemy->updateEffects();
}

void InteractionManager :: resolveInteractions(Player* player, Player* enemy)
{
    logs->resetLogger();
    
    playerAction = player->getAction();
    enemyAction = enemy->getAction();
    
    if(playerAction == enemyAction)
    {
        handleExactActions(player, enemy);
        return;
    }
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
    if(playerAction == EMPOWER and enemyAction == ATTACK)
    {
        attackOnEmpower(enemy, player);
        return;
    }
    if(playerAction == ATTACK and enemyAction == EMPOWER)
    {
        attackOnEmpower(player, enemy);
        return;
    }
    if(playerAction == GUARD and enemyAction == EMPOWER)
    {
        guardAndEmpower(player, enemy);
        return;
    }
    if(playerAction == EMPOWER and enemyAction == GUARD)
    {
        guardAndEmpower(enemy, player);
        return;
    }
    
    updateEffects(player, enemy);
}

std :: vector<std :: string> InteractionManager :: getLogs()
{
    return logs->getLogs();
}
    
    
    
    
    
    
