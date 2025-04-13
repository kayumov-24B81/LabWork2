#ifndef EVENT_HPP
#define EVENT_HPP
#include "player.hpp"

enum eventType {ACTION = 0, RESULT = 1};

class Event
{
    private:
        eventType type;
    public:
        virtual std :: string formatMessage() const = 0;
        eventType getType() const;
        void setType(eventType eType);
};

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

class AttackEvent : public Event
{
    private:
        Player* attacker;
        Player* target;
    public:
        AttackEvent(Player* attacker, Player* target);
        std :: string formatMessage() const override;
};

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
