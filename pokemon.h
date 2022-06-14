#include "move.cpp"
using namespace std;

class Pokemon{
    private:
        int id;
        string name;
        int level;

        PkmnTypes type1;
        PkmnTypes type2;
        string ability;

        int HP;
        int ATK;
        int DEF;
        int SPE;

        vector<Move*> *moveset;
        vector<Move*> *movepool;

        PkmnStatus Status;

    public:
        Pokemon(string name, int id, int level, int HP, int ATK, int DEF, int SPE, string ability, PkmnTypes type1, 
        PkmnTypes type2, vector<Move*> *moveset, vector<Move*> *movepool, PkmnStatus Status
        );

        const string getName() const;
        const int getId() const;
        const int getLevel() const;
        void setLevel(const int &level);
        const int getHP() const;
        void setHP(const int &hp);
        const int getATK() const;
        const int getDEF() const;
        const int getSPE() const; 
        const string getAB() const;
        const PkmnTypes getType1() const;
        const PkmnTypes getType2() const;
        vector<Move*> *getMoveset();
        vector<Move*> *getMovepool();
        void setMoveset(vector<Move*> *moveset);
        void printMoveset();
        void updateStats();
        void levelup();
        string statusString(PkmnStatus status);
        string typeString(PkmnTypes tipo);
        string getStatus();
        void setStatus(PkmnStatus status);
        void mostrar();

        ~Pokemon();
};