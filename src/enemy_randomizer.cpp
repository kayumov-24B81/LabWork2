#include "game.hpp"

EnemyRandomizer :: EnemyRandomizer()
{
    names.push_back(std :: make_pair("goblin", std :: vector<float>{0.8, 0.8, 0.8}));
    names.push_back(std :: make_pair("crusader", std :: vector<float>{1.0, 1.2, 1.4}));
    characteristics.push_back(std :: pair("Furious", std :: vector<float>{0.8, 1.4, 0.6}));
    characteristics.push_back(std :: pair("Armored", std :: vector<float>{1.0, 0.9, 1.2}));
    characteristics.push_back(std :: pair("Undying", std :: vector<float>{1.8, 0.6, 1.0}));
    characteristics.push_back(std :: pair("Skilled", std :: vector<float>{1.0, 1.2, 1.0}));
}

void EnemyRandomizer :: randomizeEntity(Player* entity)
{
    std::pair<std::string, std::vector<float>> name = names[rand() % names.size()];
    std::pair<std::string, std::vector<float>> charc = characteristics[rand() % characteristics.size()];
    
    entity->setName(charc.first + " " + name.first);
    entity->setDamage(static_cast<int>(entity->getDamage() * name.second[DAMAGE_MOD_POS] * charc.second[DAMAGE_MOD_POS]));
    entity->setHealth(static_cast<int>(entity->getHealth() * name.second[HEALTH_MOD_POS] * charc.second[HEALTH_MOD_POS]));
    entity->setDefense(static_cast<int>(entity->getDefense() * name.second[DEFENSE_MOD_POS] * charc.second[DEFENSE_MOD_POS]));
}
