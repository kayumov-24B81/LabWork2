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
        
        rand.randomizeEntity(enemy);
        
        isRunning = true;
    }
    catch (std::exception& e)
    {
        std::cerr << "Initialization fault: " << e.what() << std::endl;
    }
}

void Game :: pickAction()
{
    std :: string action;
    bool picked_action = false;
    std :: cout << "Pick your next action :" << std :: endl;
    std :: cin >> action;
    while(!picked_action)
    {
        picked_action = true;
        if(action == "1" || action == "attack")
        {
            player->setAction(ATTACK);
        }
        else if(action == "2" || action == "guard")
        {
            player->setAction(GUARD);
        }
        else if(action == "3" || action == "empower")
        {
            player->setAction(EMPOWER);
        }
        else
        {
            picked_action = false;
            std :: cout << "Incorrect action: write the name or the number of action" << std :: endl;
            std :: cout << "Pick your next action :" << std :: endl;
            std :: cin >> action;
        }
    }
    ai.chooseAction();
}

void Game :: update()
{
    interaction.resolveInteractions(player, enemy);
}

void Game :: checkEnd()
{
    if(player->getHealth() == 0)
    {
        ui.gameEnd(enemy);
        isRunning = false;
    }
    if(enemy->getHealth() == 0)
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
