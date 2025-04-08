#ifndef GAME_HPP
#define GAME_HPP
#include "effect_manager.hpp"
#include "interaction_manager.hpp"
#include "UI_manager.hpp"
#include "log_manager.hpp"
#include <iostream>
#include <cstdlib>

class Game
{
    private:
        Player* player;
        Player* enemy;
        bool isRunning;
        InteractionManager interaction;
        UIManager ui;
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
