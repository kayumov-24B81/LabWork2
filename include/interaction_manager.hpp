#ifndef INT_MANAGER_HPP
#define INT_MANAGER_HPP
#include "player.hpp"

enum Action {ATTACK, GUARD, EMPOWER};

class InteractionManager
{
    private:
        Action playerAction;
        Action enemyAction;
    public:
        InteractionManager();
        void setPlayerAction(Action act);
        void setEnemyAction(Action act);
        void resolveInteractions(Player* player, Player* enemy);
};

#endif
