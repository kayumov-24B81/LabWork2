#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "weapons.hpp"
#include "effect_manager.hpp"

enum Action {ATTACK = 0, GUARD = 1, EMPOWER = 2};

/**
    \brief The Player class models an entity in a system where entities interact through actions (attack, defense, buff) and are affected by effects.
    
    Player class contains basic attributes (name, health, damage, defense) and provides methods to change them and perform actions. All interactions between entities and weapons and the effects manager occur through Player class methods. It is worth noting that one Player class object does not directly affect the state of another Player class object, but it is its methods that are used by the Effect and Interaction Manager classes.
*/

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
        void setDamage(int dmh);
        void setHealth(int hp);
        void setDefense(int def);
        void setName(std :: string newName);
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
