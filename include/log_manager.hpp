#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP
#include "player.hpp"

class LogManager
{
    private:
        std :: vector<std :: string> logs;
        const unsigned ATTACK_POS = 0;
        const unsigned DEFENSE_POS = 1;
        const unsigned EMPOWER_POS = 2;
        const unsigned RESULT_POS = 3;
    public:
        LogManager();
        void addAttackMessage(Player* attacker, Player* target);
        void addGuardMessage(Player* player);
        void addEmpowerMessage(Player* player);
        void addDamageMessage(Player* attacker, Player* target, int damage);
        void addBlockMessage(Player* attacker, Player* target, int damageBlocked);
        void addHealingMessage(Player* player, int healing);
        void addEffectMessage(Player* target, Effect* effect);
        void clearLogs();
        std :: vector<std :: string> getLogs();
};

#endif
