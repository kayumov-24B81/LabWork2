#ifndef GAME_HPP
#define GAME_HPP
#include "effect_manager.hpp"
#include "interaction_manager.hpp"
#include <iostream>

class Game
{
    private:
        Player* player;
        Player* enemy;
        bool isRunning;
        InteractionManager interaction;
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
