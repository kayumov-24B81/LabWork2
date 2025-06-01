#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP
#include "player.hpp"

/**
    \brief Class responsible for outputting information about the game state to the console and formatting it.

    This class outputs information about enemy and player state, encounter logs and overall state of the game in the console. It also has a set of auxiliary functions for changing the output format.
*/

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
       void printLogs(std :: vector<std :: string> logs);
       void gameEnd(Player* winner);
       void printWithDelay(std :: string text);
};

#endif
