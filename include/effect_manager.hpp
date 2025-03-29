#ifndef EFFECT_MANAGER_HPP
#define EFFECT_MANAGER_HPP

#include "player.hpp"
#include <algorithm>
#include <vector>

class EffectManager
{
    private:
       std :: vector<Effect*> effects;
    public:
       Player* owner;
       EffectManager();
       void addEffect(Effect* effect);
       void update();
};

#endif
