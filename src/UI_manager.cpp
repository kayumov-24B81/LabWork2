#include "game.hpp"
#include <unistd.h>
#include <limits>
#include <chrono>
#include <thread>

UIManager :: UIManager():
    player(nullptr), enemy(nullptr)
{
}

void UIManager :: setEnemy(Player* enemyPtr)
{
    enemy = enemyPtr;
}

void UIManager :: setPlayer(Player* playerPtr)
{
    player = playerPtr;
}

void UIManager :: clearConsole()
{
    std :: cout << "\033[2J\033[1;1H";
}

void UIManager :: printStats(Player* player)
{
    Weapon* weapon = player->getWeapon();
    std :: vector<Effect*> effects = player->getEffects();
    
    std :: cout << player->getName() << ":" << std :: endl
    << "- Health: " << player->getHealth() << std :: endl
    << "- Damage: " << player->getDamage() << std :: endl
    << "- Defense: " << player->getDefense() << std :: endl
    << "- Weapon: " << weapon->getName()
    << "(" << weapon->getDamage() << ", " << weapon->getDefense() << ")" << std :: endl
    << "- Effects: [";
    if(!effects.empty())
    {
        std :: cout << effects[0]->getName() << "(" << effects[0]->getDuration() << ")";
        for(unsigned i = 1; i < effects.size(); ++i)
        {
            std :: cout << ", " << effects[i]->getName() << "(" << effects[i]->getDuration() << ")";
        }
    }
    std :: cout << "]" << std :: endl;
    std :: cout << std :: endl; 
}

void UIManager :: printUI()
{
    std :: cout << "=== FIGHT === " << std :: endl;
    printStats(player);
    printStats(enemy);
    std :: cout << "Available actions:\n1.attack\n2.guard\n3.empower" << std :: endl;
    std :: cout << std :: endl;
}

void UIManager :: continueGame()
{
    std :: cout << "Press enter to continue: " << std :: endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std :: cin.get();
    clearConsole();
}

void UIManager :: printLogs(std :: vector<std :: string> logs)
{
    for(std :: string message : logs)
    {
        printWithDelay(message);
    }
}

void UIManager :: gameEnd(Player* winner)
{
    std :: cout << std :: endl << "=== FIGHT RESULT ===" << std :: endl;
    std :: cout << winner->getName() << " won!" << std :: endl;
}

void UIManager :: printWithDelay(std :: string text)
{
    if(!text.empty())
    {
        for (char c : text) 
        {
            std :: cout << c << std::flush;
            std :: this_thread ::sleep_for(std::chrono::milliseconds(20));
        }
    }
}
