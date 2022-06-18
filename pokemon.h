#include "move.cpp"
using namespace std;

class Pokemon{
    private:
// ----------- IDENTIFIERS -----------
        int id;
        int level;

// ----------- STATS -----------
        int max_hp;

        int HP, ATK, DEF, SPE;

        int calcATK, calcDEF, calcSPE;

        int cur_hp, cur_atk, cur_def, cur_spe;

        int atk_stat_change, def_stat_change, spe_stat_change;

// ----------- DATA -----------
        string ability;
        string name;

        PkmnTypes type1, type2;

        vector<Move*> *moveset;
        vector<Move*> *movepool;

        PkmnStatus Status;

    public:
        Pokemon(string name, int id, int level, int HP, int ATK, int DEF, int SPE, string ability, PkmnTypes type1, 
        PkmnTypes type2, vector<Move*> *moveset, vector<Move*> *movepool, PkmnStatus Status
        );

// =============== GETTERS ===============
        const string getName() const;
        const int getId() const;
        const int getLevel() const;
        string getStatusString();
        const string getAB() const;
        const PkmnTypes getType1() const;
        const PkmnTypes getType2() const;
        const PkmnStatus getStatus() const;

// ----------- HP -----------
        const int getMaxHP() const;
        const int getHP() const;
        const int get_baseHP() const;

// ----------- ATK -----------
        const int getATKchange() const;
        const int get_baseATK() const;
        const int getATK() const;

// ----------- DEF -----------
        const int getDEFchange() const;
        const int get_baseDEF() const;
        const int getDEF() const;

// ----------- SPE -----------
        const int getSPEchange() const;
        const int get_baseSPE() const;
        const int getSPE() const; 

// ---------- MOVES ----------
        vector<Move*> *getMoveset();
        vector<Move*> *getMovepool();

// =============== SETTERS ===============
        void setLevel(const int &level);
        void setStatus(PkmnStatus status);

// ----------- HP -----------
        void setCurrentHP(const int &hp);

// ----------- ATK -----------
        void setATKChange(const int &change);

// ----------- DEF -----------
        void setDEFChange(const int &change);

// ----------- SPE -----------
        void setSPEChange(const int &change);

// ---------- MOVES ----------
        void setMoveset(vector<Move*> *moveset);

// =============== METHODS ===============
        void startStats();
        void updateStats();
        void boost(int stat, int amount);

// ---------- PRINTERS ----------
        void printMoveset();
        string printData();
        void mostrar();

// -------- CONVERTERS --------
        string statusString(PkmnStatus status);
        string typeString(PkmnTypes tipo);
};