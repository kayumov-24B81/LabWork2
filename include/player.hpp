#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "weapons.hpp"
#include "effect_manager.hpp"

enum Action {ATTACK = 0, GUARD = 1, EMPOWER = 2};

class Player
{
    private:
        std :: string name;
        int health;
        int damage;
        int defense;
        Action action;
        Weapon* weaponPtr;
        EffectManager* effectsPtr;
        std :: vector<Effect*> effectsWaitList;
    public:
        Player(std :: string name);
        ~Player();
        std :: string getName();
        int getHealth();
        int getDamage();
        int getDefense();
        Action getAction();
        std :: vector<Effect*> getEffects();
        Weapon* getWeapon();
        void setWeapon(Weapon* ptr);
        void setAction(Action newAction);
        void changeHealth(int hp);
        void changeDamage(int dmg);
        void changeDefense(int def);
        void attack(Player* target);
        void guard();
        void empower();
        void addEffect(Effect* effect);
        void updateEffects();
        std :: vector<Effect*> getEffectsWaitList();
};

#endif
