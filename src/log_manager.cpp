#include "game.hpp"

LogManager :: LogManager()
{
    logs.resize(4);
}

void LogManager :: addAttackMessage(Player* attacker, Player* target)
{
    logs[ATTACK_POS] += attacker->getName() + " attacks " + target->getName() + "\n";
}

void LogManager :: addGuardMessage(Player* player)
{
    logs[DEFENSE_POS] = player->getName() + " gets into a defensive stance\n";
}

void LogManager :: addEmpowerMessage(Player* player)
{
    logs[EMPOWER_POS] = player->getName() + " is focusing on the fight\n";
}

void LogManager :: addDamageMessage(Player* attacker, Player* target, int damage)
{
    logs[RESULT_POS] = "- " + attacker->getName() + " deals " + std :: to_string(damage) + " to " + target->getName() + "\n";
}

void LogManager :: addBlockMessage(Player* attacker, Player* target, int damageBlocked)
{
    logs[RESULT_POS] = "- " + target->getName() + " blocks " + std :: to_string(damageBlocked) + " damage from " + attacker->getName() + "\n";
}

void LogManager :: addHealingMessage(Player* player, int healing)
{
    logs[RESULT_POS] = "- " + player->getName() + " heals for " + std :: to_string(healing) + " health";
}

void LogManager :: addEffectMessage(Player* target, Effect* effect)
{
    logs[RESULT_POS] += "- Applied effect " + effect->getName() + " to " + target->getName() + ": " + effect->getDesc() + "\n";
}

void LogManager :: clearLogs()
{
    logs.clear();
    logs.resize(4);
}

std :: vector<std :: string> LogManager :: getLogs()
{
    return logs;
}






