#ifndef EFFECT_MANAGER_HPP
#define EFFECT_MANAGER_HPP

#include "effect.hpp"
#include <algorithm>
#include <vector>

class EffectManager
{
    private:
       std :: vector<Effect*> effects;
    public:
       Player* owner;
       EffectManager();
       ~EffectManager();
       std :: vector<Effect*> getEffects();
       void addEffect(Effect* effect);
       void update();
};

#endif
