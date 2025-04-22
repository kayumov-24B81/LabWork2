#include "game.hpp"

Player :: Player(std :: string name):
    name(name), health(100), damage(0), defense(0), weaponPtr(nullptr)
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
    if(health > 0) return health;
    else return 0;
}

int Player :: getDamage()
{
    if(damage > 0) return damage;
    else return 0;
}

int Player :: getDefense()
{
    if(defense > 0) return defense;
    else return 0;
}

std :: vector<Effect*> Player :: getEffects()
{
    return effectsPtr->getEffects();
}

void Player :: setName(std :: string newName)
{
    name = newName;
}

Weapon* Player :: getWeapon()
{
    return weaponPtr;
}

Action Player :: getAction()
{
    return action;
}

void Player :: setDamage(int dmg)
{
    damage = dmg;
}

void Player :: setHealth(int hp)
{
    health = hp;
}

void Player :: setDefense(int def)
{
    defense = def;
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

void Player :: setAction(Action newAction)
{
    action = newAction;
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
