#ifndef EFFECT_HPP
#define EFFECT_HPP
#include <string>

class Player;

class Effect
{
    private:
        std :: string name;
        std :: string description;
        unsigned duration;
    public:
        Effect(std :: string name, std :: string desc, unsigned dur);
        virtual ~Effect() = 0;
        std :: string getName();
        std :: string getDesc();
        unsigned getDuration();
        void setDuration(unsigned dur);
        void tick();
        virtual void apply(Player* target) = 0;
        virtual void revert(Player* target) = 0;
};

#endif
        
