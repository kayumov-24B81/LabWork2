#include "game.hpp"

/* EVENT */

eventType Event :: getType() const
{
    return type;
}

void Event :: setType(eventType eType)
{
    type = eType;
}

/* DAMAGE EVENT */

DamageEvent :: DamageEvent(Player* attacker, Player* target, int damage):
    attacker(attacker), target(target), damage(damage)
{
    this->setType(RESULT);
}

std :: string DamageEvent :: formatMessage() const
{
    return "- " + attacker->getName() + " deals " + std :: to_string(damage) + " damage to " + target->getName() + "\n";
}

/* EFFECT EVENT */

EffectEvent :: EffectEvent(Player* target, Effect* effect):
    target(target), effect(effect)
{
    this->setType(RESULT);
}

std :: string EffectEvent :: formatMessage() const
{
    return "- Applied effect " + effect->getName() + " to " + target->getName() + ": " + effect->getDesc() + "\n";
}

/* ATTACK EVENT */

AttackEvent :: AttackEvent(Player* attacker, Player* target):
    attacker(attacker), target(target)
{
    this->setType(ACTION);
}

std :: string AttackEvent :: formatMessage() const
{
    return attacker->getName() + " attacks " + target->getName() + "\n";
}

/* GUARD EVENT */

GuardEvent :: GuardEvent(Player* attacker, Player* target):
    attacker(attacker), target(target)
{
    this->setType(ACTION);
}

std :: string GuardEvent :: formatMessage() const
{
    std :: string message = target->getName() + " gets into a defensive stance\n";
    if(attacker != nullptr)
    {
        message += target->getName() + " succesfully blocks " + attacker->getName() + "'s attack\n";
    }
    return message;
}

/* EMPOWER EVENT */

EmpowerEvent :: EmpowerEvent(Player* attacker, Player* target):
    attacker(attacker), target(target)
{
    this->setType(ACTION);
}

std :: string EmpowerEvent :: formatMessage() const
{
    std :: string message = target->getName() + " is focusing on the fight\n";
    if(attacker != nullptr)
    {
        message += attacker->getName() + " interrupts " + target->getName() + "\n";
    }
    return message;
}
