#ifndef EVENT_HPP
#define EVENT_HPP
#include "player.hpp"

enum eventType {ACTION = 0, RESULT = 1};

/**
    \brief Parent Event class.
    
    Has vritual method formatMessage() that converts data stored in an object into text.
*/

class Event
{
    private:
        eventType type;
    public:
        virtual std :: string formatMessage() const = 0;
        eventType getType() const;
        void setType(eventType eType);
};

/**
    \brief Event that is responsible for logging of damage dealt to an entity.
*/

class DamageEvent : public Event
{
    private:
        Player* attacker;
        Player* target;
        int damage;
    public:
        DamageEvent(Player* attacker, Player* target, int damage);
        std :: string formatMessage() const override;
};

/**
    \brief Event that is responsible for logging of effect application to an entity.
*/

class EffectEvent : public Event
{
    private:
        Player* target;
        Effect* effect;
        eventType type;
    public:
        EffectEvent(Player* target, Effect* effect);
        std :: string formatMessage() const override;
};

/**
    \brief Event that is responsible for logging result of attack action.
*/

class AttackEvent : public Event
{
    private:
        Player* attacker;
        Player* target;
    public:
        AttackEvent(Player* attacker, Player* target);
        std :: string formatMessage() const override;
};

/**
    \brief Event that is responsible for logging result of guard action.
    
    If attacker pointer is null then regular guard message will be passed to logger, in the other case succesfull parry message will be passed.
*/

class GuardEvent : public Event
{
    private:
        Player* attacker;
        Player* target;
        int blockedDamage;
    public:
        GuardEvent(Player* attacker, Player* target);
        std :: string formatMessage() const override;
};

/**
    \brief Event that is responsible for logging result of empower action.
    
    If attacker pointer is null then regular empower message will be passed to logger, in the other case a message about the interrupted empowering will be passed.
*/

class EmpowerEvent : public Event
{
    private:
        Player* attacker;
        Player* target;
    public:
        EmpowerEvent(Player* attacker, Player* target);
        std :: string formatMessage() const override;
};

#endif
