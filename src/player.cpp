#include "player.hpp"

Player :: Player(std :: string name):
    name(name), health(20), damage(0), defense(0), weaponPtr(nullptr)
{
    effectsPtr = new EffectManager();
    effectsPtr->owner = this;
}

Player :: ~Player()
{
    delete weaponPtr;
    delete effectsPtr;
}

std :: string Player :: getName()
{
    return name;
}

int Player :: getHealth()
{
    return health;
}

int Player :: getDamage()
{
    return damage;
}

int Player :: getDefense()
{
    return defense;
}

std :: vector<Effect*> Player :: getEffects()
{
    return effectsPtr->getEffects();
}

Weapon* Player :: getWeapon()
{
    return weaponPtr;
}

Action Player :: getAction()
{
    return action;
}

void Player :: setWeapon(Weapon* ptr)
{
    if(weaponPtr)
    {
        weaponPtr->revertStats(this);
    }
    weaponPtr = ptr;
    weaponPtr->updateStats(this); 
}

void Player :: changeHealth(int hp)
{
    health += hp;
}

void Player :: changeDamage(int dmg)
{
    damage += dmg;
}

void Player :: changeDefense(int def)
{
    defense += def;
}

void Player :: attack(Player* target)
{
    weaponPtr->atkEffect(this, target);
    action = ATTACK;
}

void Player :: guard()
{
    weaponPtr->defEffect(this);
    action = GUARD;
}

void Player :: empower()
{
    weaponPtr->empEffect(this);
    action = EMPOWER;
}

void Player :: addEffect(Effect* effect)
{
    effectsWaitList.push_back(effect);
}

void Player :: updateEffects()
{
    for(Effect* effect : effectsWaitList)
    {
        effectsPtr->addEffect(effect);
    }
    effectsPtr->update();
    effectsWaitList.clear();
}

std :: vector<Effect*> Player :: getEffectsWaitList()
{
    return effectsWaitList;
}
