#ifndef INT_MANAGER_HPP
#define INT_MANAGER_HPP
#include "log_manager.hpp"

enum Action {ATTACK, GUARD, EMPOWER};

class InteractionManager
{
    private:
        LogManager* logs;
        Action playerAction;
        Action enemyAction;
    public:
        InteractionManager();
        ~InteractionManager();
        void setLogs(LogManager* log);
        void setPlayerAction(Action act);
        void setEnemyAction(Action act);
        void attackOnGuard(Player* attacker, Player* defender);
        void attackOnEmpower(Player* attacker, Player* empowerer);
        void attackOnAttack(Player* player1, Player* player2);
        void resprite(Player* player1, Player* player2);
        void resolveEffects(Player* player);
        void resolveInteractions(Player* player, Player* enemy);
        std :: vector<std :: string> getLogs();
};
#endif
