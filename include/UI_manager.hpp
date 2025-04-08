#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP
#include "player.hpp"

class UIManager
{
    private:
       Player* player;
       Player* enemy;
    public:
       UIManager();
       void setEnemy(Player* enemyPtr);
       void setPlayer(Player* playerPtr);
       void clearConsole();
       void printStats(Player* player);
       void printUI();
       void continueGame();
};

#endif
