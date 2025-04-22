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
