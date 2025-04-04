#ifndef EFFECTS_HPP
#define EFFECTS_HPP

class BrokenDefense : public Effect
{
    private:
        int defenseReduction;
    public:
        BrokenDefense(int defRed, unsigned dur);
        BrokenDefense();
        ~BrokenDefense();
        void apply(Player* target) override;
        void revert(Player* target) override;
};

#endif
