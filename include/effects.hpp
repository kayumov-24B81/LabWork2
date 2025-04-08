#ifndef EFFECTS_HPP
#define EFFECTS_HPP
#include "effect.hpp"

class BrokenDefense : public Effect
{
    private:
        int defenseReduction;
    public:
        BrokenDefense(int defRed, unsigned dur);
        BrokenDefense();
        ~BrokenDefense() override;
        void apply(Player* target) override;
        void revert(Player* target) override;
};

#endif
