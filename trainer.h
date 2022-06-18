#include "pokemon.cpp"

enum TrainerClass{ ACE_TRAINER, AROMA_LADY, ATHLETE, BACKPACKER, BIKER, BIRD_KEEPER, BUG_MANIAC, CAMERAMAN, COOK, CHAMPION, COOL_BEAUTY, CUTE_MANIAC, ELITE_FOUR, FIREBREATHER, GENTLEMAN, GUITARIST, GYM_TRAINER, ROOKIE, RICH_BOY, FISHERMAN, BUG_CATCHER, GYM_LEADER, LASS };

class Trainer{
    private:
        string name;
        TrainerClass tc;
        vector<Pokemon*> party;
    public:
        Trainer(string name, TrainerClass tc, vector<Pokemon*> party);
        const string getName() const;
        const TrainerClass getTC() const;
        vector<Pokemon*> getParty();
        const int getPartySize() const;
        void setPkmn(Pokemon* pkmn, int lvl, vector<Move*> *ms);
        void updateTeam();

        void setParty(const vector<Pokemon*> &party);

        Pokemon* getLeadPkmn();

        string classtring(TrainerClass clase);
        
        void mostrarEquipo();
        
        ~Trainer();
};