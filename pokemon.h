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

        int max_hp;
        int cur_hp;
        int cur_atk;
        int cur_def;
        int cur_spe;

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
        void setCurrentHP(const int &hp);

        const int getMaxHP() const;
        const int getHP() const;
        const int getATK() const;
        const int getDEF() const;
        const int getSPE() const; 

        const int get_baseHP() const;
        const int get_baseATK() const;
        const int get_baseDEF() const;
        const int get_baseSPE() const;

        const string getAB() const;
        const PkmnTypes getType1() const;
        const PkmnTypes getType2() const;
        const PkmnStatus getStatus() const;
        vector<Move*> *getMoveset();
        vector<Move*> *getMovepool();
        void setMoveset(vector<Move*> *moveset);
        void printMoveset();
        void startStats();
        void updateStats();
        void levelup();
        string printData();
        string statusString(PkmnStatus status);
        string typeString(PkmnTypes tipo);
        string getStatusString();
        void setStatus(PkmnStatus status);
        void mostrar();

        ~Pokemon();
};