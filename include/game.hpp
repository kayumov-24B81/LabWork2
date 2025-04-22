#ifndef GAME_HPP
#define GAME_HPP
#include "effect_manager.hpp"
#include "interaction_manager.hpp"
#include "UI_manager.hpp"
#include "logger.hpp"
#include "AI.hpp"
#include <iostream>
#include <cstdlib>
#include "enemy_randomizer.hpp"

/**
   \brief Class responsible for initializing all entities, the game loop and clearing memory.

   The methods of this class are used to call the methods of various managers to change the state of the game. It also manages the player's choice and passes the results to the interaction manager.
*/

class Game
{
    private:
        Player* player;
        Player* enemy;
        bool isRunning;
        InteractionManager interaction;
        UIManager ui;
        AI ai;
        EnemyRandomizer rand;
    public:
        Game();
        void initialize();
        void pickAction();
        void update();
        void checkEnd();
        void run();
        void shutdown();
};

#endif
