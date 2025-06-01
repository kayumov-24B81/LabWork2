#ifndef EFFECT_MANAGER_HPP
#define EFFECT_MANAGER_HPP

#include "effect.hpp"
#include <algorithm>
#include <vector>

/**
    \brief Class responsible for storing effects, applying or reversing changes to entities characteristics.
    
    This class when addEffect() method is called checks the effects vector for coincidences and applies corresponding changes to its owner or extends duration of existing effect. After effect is stored in vector it checks effects for expiration and reverts changes caused by expired effects, deleting corresponding Effect class object.

*/

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
