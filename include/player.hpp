#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "weapons.hpp"

class Player
{
    private:
        std :: string name;
        int health;
        int damage;
        int defense;
        Weapon* weaponPtr;
        EffectManager* effectsPtr;
    public:
        Player(std :: string name);
        ~Player();
        std :: string getName();
        int getHealth();
        int getDamage();
        int getDefense();
        void setWeapon(Weapon* ptr);
        void changeHealth(int hp);
        void changeDamage(int dmg);
        void changeDefense(int def);
        void attack(Player* target);
        void guard();
        void empower();
        void addEffect(Effect* effect);
        void updateEffects();
};

#endif
