#include "game.hpp"
#include <ctime>

Game :: Game(): player(nullptr), enemy(nullptr)
{
}

void Game :: initialize()
{
    try
    {
        srand(time(NULL));
        
        player = new Player("Player");
        enemy = new Player("Enemy");
        
        ui.setPlayer(player);
        ui.setEnemy(enemy);
        
        interaction.setLogs(new Logger);
        
        ai.setEntity(enemy);
        ai.setTarget(player);
    
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
    switch(action)
    {
        case 1:
            player->setAction(ATTACK);
            break;
        case 2:
            player->setAction(GUARD);
            break;
        case 3:
            player->setAction(EMPOWER);
            break;
        default:
            std :: cout << "Incorrect action nubmer!" << std :: endl;
            std :: cout << "Pick your next action :" << std :: endl;
            std :: cin >> action;
    }
    ai.chooseAction();
}

void Game :: update()
{
    interaction.resolveInteractions(player, enemy);
}

void Game :: checkEnd()
{
    if(player->getHealth() < 0)
    {
        ui.gameEnd(enemy);
        isRunning = false;
    }
    if(enemy->getHealth() < 0)
    {
        ui.gameEnd(player);
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
        ui.printUI();
        update();
        ui.printLogs(interaction.getLogs());
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
