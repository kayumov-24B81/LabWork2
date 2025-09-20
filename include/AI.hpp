#ifndef AI_HPP
#define AI_HPP
#include "player.hpp"

/**
 * \brief Class responsible for enemies action logic
 
   Simple enemy AI. When chooseAction() function is called randomly selects action and calls corresponding entity method.
*/

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
