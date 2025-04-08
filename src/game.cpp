#include "game.hpp"

Game :: Game(): player(nullptr), enemy(nullptr)
{
}

void Game :: initialize()
{
    try
    {
        player = new Player("Player");
        enemy = new Player("Enemy");
    
        ui.setPlayer(player);
        ui.setEnemy(enemy);
    
        player->setWeapon(new Sword());
        enemy->setWeapon(new Sword());
    
        isRunning = true;
    }
    catch (std::exception& e)
    {
        std::cerr << "Initialization fault: " << e.what() << std::endl;
    }
}

void Game :: pickAction()
{
    int action;
    std :: cout << "Pick your next action :" << std :: endl;
    std :: cin >> action;
    interaction.setPlayerAction(static_cast<Action>(action - 1));
    interaction.setEnemyAction(ATTACK);
}

void Game :: update()
{
    interaction.resolveInteractions(player, enemy);
}

void Game :: checkEnd()
{
    if(player->getHealth() < 0)
    {
        std :: cout << "You are dead" << std :: endl;
        isRunning = false;
    }
    if(enemy->getHealth() < 0)
    {
        std :: cout << "Enemy is dead" << std :: endl;
        isRunning = false;
    }
}

void Game :: run()
{
    initialize();
    while(isRunning)
    {
        ui.printUI();
        pickAction();
        update();
        checkEnd();
        ui.continueGame();
    }
    shutdown();
}

void Game :: shutdown()
{
    delete player;
    delete enemy;
}
