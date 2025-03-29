#include "player.hpp"

Effect :: Effect(std :: string name, std :: string desc, unsigned dur):
    name(name), description(desc), duration(dur)
{
}

std :: string Effect :: getName()
{
    return name;
}

std :: string Effect :: getDesc()
{
    return description;
}

unsigned Effect :: getDuration()
{
    return duration;
}

void Effect :: setDuration(unsigned dur)
{
    duration = dur;
}

void Effect :: tick()
{
    duration -= 1;
}
