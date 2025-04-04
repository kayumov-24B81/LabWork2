#include "player.hpp"

Player :: Player(std :: string name):
    name(name), health(20), damage(0), defense(0), weaponPtr(nullptr)
{
    effectsPtr.owner = this;
}

Player :: ~Player()
{
    delete weaponPtr;
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
}

void Player :: guard()
{
    weaponPtr->defEffect(this);
}

void Player :: empower()
{
    weaponPtr->empEffect(this);
}

void Player :: addEffect(Effect* effect)
{
    effectsPtr->addEffect(effect);
}

void Player :: updateEffects()
{
    effectsPtr->update();
}

