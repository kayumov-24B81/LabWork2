#ifndef GAME_HPP
#define GAME_HPP
#include "effect_manager.hpp"

class Game
{
    private:
        Player* player;
        Player* enemy;
        bool isRunning;
    public:
        Game();
        void initialize();
        void run();
        void shutdown();
};

#endif
