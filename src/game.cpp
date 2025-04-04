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

void Game :: pickAction()
{
    int action;
    std :: cout << "Pick your next action :" << std :: endl;
    std :: cout <<"1.attack\n2.guard\n3.empower" << std :: endl;
    std :: cin >> action;
    interaction.setPlayerAction(static_cast<Action>(action - 1));
    interaction.setEnemyAction(ATTACK);
}

void Game :: update()
{
    interaction.resolveInteractions(player, enemy);
    std :: cout << "player hp: " << player->getHealth() << std :: endl;
    std :: cout << "enemy hp: " << enemy->getHealth() << std :: endl;
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
        pickAction();
        update();
        checkEnd();
    }
    shutdown();
}

void Game :: shutdown()
{
    delete player;
    delete enemy;
}
