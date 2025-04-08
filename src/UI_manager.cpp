#include "game.hpp"
#include <unistd.h>
#include <limits>

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
    for(Effect* effect : effects)
    {
        std :: cout << effect->getName() << "(" << effect->getDuration() << ")";
    }
    std :: cout << "]" << std :: endl;
}

void UIManager :: printUI()
{
    std :: cout << "=== FIGHT === " << std :: endl;
    printStats(player);
    printStats(enemy);
    std :: cout << "Available actions:\n1. attack\n2. defend\n3. empower" << std :: endl;
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
        std :: cout << message;
    }
}
