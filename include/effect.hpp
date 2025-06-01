#ifndef EFFECT_HPP
#define EFFECT_HPP
#include <string>

class Player;

/**
    \brief Parent class. This class and its child classes is responsible for short-term changes to the character's characteristics.
    
    Parent class for various effects Classes. Contains fully virtual methods that apply changes to player's stats and revert them. The changes are specified in child classes. 
*/

class Effect
{
    private:
        std :: string name;
        std :: string description;
        unsigned duration;
    public:
        Effect(std :: string name, std :: string desc, unsigned dur);
        virtual ~Effect();
        std :: string getName();
        std :: string getDesc();
        unsigned getDuration();
        void setDuration(unsigned dur);
        void tick();
        virtual void apply(Player* target) = 0;
        virtual void revert(Player* target) = 0;
};

#endif
        
