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
        void attackOnGuard(Player* attacker, Player* defender);
        void attackOnEmpower(Player* attacker, Player* empowerer);
        void attackOnAttack(Player* player1, Player* player2);
        void resprite(Player* player1, Player* player2);
        void resolveInteractions(Player* player, Player* enemy);
};
#endif
