#ifndef AI_HPP
#define AI_HPP
#include "player.hpp"

class AI
{
    private:
        Player* entity;
        Player* target;
    public:
        AI();
        void setEntity(Player* newEntity);
        void setTarget(Player* target);
        void chooseAction();
};

#endif
