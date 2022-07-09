#include "pokemon.cpp"

class Trainer{
    private:
        string name;
        TrainerClass tc;
        vector<Pokemon*> party;
    public:
        Trainer(string name, TrainerClass tc, vector<Pokemon*> party);
        const string getName() const;
        void setName(const string &nm);
        const TrainerClass getTC() const;
        vector<Pokemon*> getParty();
        const int getPartySize() const;
        void setPkmn(Pokemon* pkmn, int lvl, vector<Move*> ms);
        void updateTeam();

        void setParty(const vector<Pokemon*> &party);

        Pokemon* getLeadPkmn();

        string classtring(TrainerClass clase);
        
        int getPartyPokemonIndex(Pokemon* pkmn);

        void mostrarEquipo();
        
        ~Trainer();
};