#include "game.hpp"

EffectManager :: EffectManager()
{
    owner = nullptr;
}

EffectManager :: ~EffectManager()
{
    for(Effect* e : effects)
    {
        delete e;
    }
}

std :: vector<Effect*> EffectManager :: getEffects()
{
    return effects;
}

void EffectManager :: addEffect(Effect* effect)
{
    bool isSame = false;
    for(unsigned i = 0; i < effects.size(); ++i)
    {
        if(effect->getName() == effects[i]->getName())
        {
            effects[i]->setDuration(std :: max(effect->getDuration(), effects[i]->getDuration()));
            delete effect;
            isSame = true;
            break;
        }
    }
    if(!isSame)
    {
        effects.push_back(effect);
        effect->apply(owner);
    }
}

void EffectManager :: update()
{
    unsigned i = 0;
    while(i < effects.size())
    {
        effects[i]->tick();
        if(effects[i]->getDuration() == 0)
        {
            effects[i]->revert(owner);
            delete effects[i];
            effects.erase(effects.begin() + i);
        }
        else
        {
            i += 1;
        }
    }
}
            
