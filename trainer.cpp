#include "trainer.h"

Trainer::Trainer(string name, TrainerClass tc, vector<Pokemon*> party):name(name),tc(tc),party(party){}

const string Trainer::getName() const{
    return name;
}

const TrainerClass Trainer::getTC() const{
    return tc;
}

vector<Pokemon*> Trainer::getParty(){
    return party;
}

void Trainer::updateTeam(){
    int partySize = Trainer::party.size();
    vector<Pokemon*> newParty;
    for(auto pk: party){
        cout<<partySize<<","<<party.size()<<endl;
        if(partySize == party.size()){
            partySize--;
            
        } else {
            newParty.push_back(pk);
            cout<<"Added: "<<pk->getName() <<" to the new party"<<endl;
        }
    }
    party = newParty;
}

const int Trainer::getPartySize() const{
    return party.size();
}

void Trainer::setPkmn(Pokemon* pkmn, int lvl, vector<Move*>ms){
    pkmn->setLevel(lvl);
    pkmn->setMoveset(ms);
    party.push_back(pkmn);
    /*
    for(auto pk: party){
        if(pk == pkmn){
            pk->setLevel(lvl);
            pk->setMoveset(ms);
        }
    }*/
}
void Trainer::setName(const string &nm){
    name = nm;
}

void Trainer::setParty(const vector<Pokemon*> &par){
    party = par;
}

int Trainer::getPartyPokemonIndex(Pokemon* pkmn){
    int temp = 0;
    for(const auto &p : party){
        if(p->getName() == pkmn->getName())
            return temp;

        temp++;
    }
    return -1;
}


Pokemon* Trainer::getLeadPkmn(){
    Pokemon* pk = *party.begin();

    return pk;
}

string Trainer::classtring(TrainerClass tc){
    switch(tc){
        case TrainerClass::ROOKIE:
            return "Rookie";
        break;
        case TrainerClass::RICH_BOY:
            return "Rich boy";
        break;
        case TrainerClass::FISHERMAN:
            return "Fisherman";
        break;
        case TrainerClass::BUG_CATCHER:
            return "Bug Catcher";
        break;
        case TrainerClass::GYM_LEADER:
            return "Leader";
        break;
        case TrainerClass::LASS:
            return "Lass";
        case TrainerClass::CHAMPION:
            return "Champion";
        break;
    }
    return "";
}

void Trainer::mostrarEquipo(){
    cout << "||||||||||||||||| " << classtring(tc) << " " << name << " ||||||||||||||||||||" << endl;
    for(auto pkmn : party){
        pkmn->mostrar();
    }
}