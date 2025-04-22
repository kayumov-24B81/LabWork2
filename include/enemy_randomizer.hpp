#ifndef ENEMY_RANDOMIZER_HPP
#define ENEMY_RANDOMIZER_HPP

#include "player.hpp"

/**
    \brief Class responsible for creating a variety of enemies using presets
    
    In constructor vectors "names" and "characteristics" are initialized with some enemies presets, containing coefficients for basic characteristics. When randomizeEntity() function is called characteristics changes with corresponding entity name are applied.
*/

class EnemyRandomizer
{
    private:
        const unsigned HEALTH_MOD_POS = 0;
        const unsigned DAMAGE_MOD_POS = 1;
        const unsigned DEFENSE_MOD_POS = 2;
        std::vector<std::pair<std::string, std::vector<float>>> names;
        std :: vector<std :: pair<std :: string, std :: vector<float>>> characteristics;
    public:
        EnemyRandomizer();
        void randomizeEntity(Player* entity);
};

#endif
