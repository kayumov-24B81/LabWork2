#include "game.hpp"

Game :: Game(): player(nullptr), enemy(nullptr)
{
}

void Game :: initialize()
{
    player = new Player("Player");
    enemy = new Player("Enemy");
    
    player->setWeapon(new Sword());
    enemy->setWeapon(new Sword());
    
    isRunning = true;
}

void Game :: run()
{
    initialize();
    while(isRunning)
    {
        isRunning = false;
    }
    shutdown();
}

void Game :: shutdown()
{
    delete player;
    delete enemy;
}
