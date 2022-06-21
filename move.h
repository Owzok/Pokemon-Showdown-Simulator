#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <map>
using namespace std;

enum PkmnTypes{BUG, DARK, DRAGON, ELECTRIC, FAIRY, FIGHTING, FIRE, FLYING, GHOST, GRASS, GROUND, ICE, NORMAL, POISON, PSYCHIC, ROCK, STEEL, WATER, NONE };
enum Category{PHYSICAL,SPECIAL,STATUS };
enum PkmnStatus{ SLEEP, FROZEN, PARALYZED, BURNED, POISONED, BADLY_POISONED, CONFUSED, ATTRACTED, HEALTHY};

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