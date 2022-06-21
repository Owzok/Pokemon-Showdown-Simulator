#include "lib_enum.cpp"

class Move{
    private:
        string name;
        int pp;
        int currentPP;
        Category category;
        int power;
        int acurracy;
        string side_effect;
        PkmnTypes type;
    public:    
        Move(string name, int pp, Category category, int power, int acurracy, string side_effect, PkmnTypes type);
        const string getName() const;
        const int getPP() const;
        const int getCurrentPP() const;
        const Category getCategory() const;
        const int getPower() const;
        const int getAccurracy() const;
        const string getSideEffect() const;
        const PkmnTypes getMoveType() const;
        void lessPP();

        string moveTypeString(PkmnTypes tipo);
        void printMove();

        ~Move();
};