#ifndef INT_MANAGER_HPP
#define INT_MANAGER_HPP
#include "logger.hpp"

class InteractionManager
{
    private:
        Logger* logs;
        Action playerAction;
        Action enemyAction;
    public:
        InteractionManager();
        ~InteractionManager();
        void setLogs(Logger* newLogs);
        void dealDamage(Player* attacker, Player* target);
        void handleExactActions(Player* player, Player* enemy);
        void attackOnGuard(Player* attacker, Player* target);
        void attackOnEmpower(Player* attacker, Player* target);
        void guardAndEmpower(Player* guard, Player* empowerer);
        void updateEffects(Player* player, Player* enemy);
        void resolveInteractions(Player* player, Player* enemy);
        std :: vector<std :: string> getLogs();
};

#endif
