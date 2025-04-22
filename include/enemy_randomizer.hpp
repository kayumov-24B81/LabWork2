#ifndef ENEMY_RANDOMIZER_HPP
#define ENEMY_RANDOMIZER_HPP

#include "player.hpp"

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
