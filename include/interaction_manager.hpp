#ifndef INT_MANAGER_HPP
#define INT_MANAGER_HPP
#include "logger.hpp"

/**

    \brief Class that handles interactions between entities and creates logs through Event class objects.

    Interaction manager is responsible for calculating the results of interactions and directly changing the state of characters. When resolveInteractions() function is called, depending on the actions selected by the entities, a scenario and corresponding function is selected according to which their interactions will take place. Some interactions may have different outcomes, which are randomly selected from the possible ones. For every major action and change in characters condition a coressponding Event class object is created and passed to Logger class object.
*/

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
