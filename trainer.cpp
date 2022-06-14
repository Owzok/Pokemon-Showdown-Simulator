#include "trainer.h"

Trainer::Trainer(string name, TrainerClass tc, vector<Pokemon*> *party):name(name),tc(tc),party(party){}

const string Trainer::getName() const{
    return name;
}

const TrainerClass Trainer::getTC() const{
    return tc;
}

const vector<Pokemon*> *Trainer::getParty() const{
    return party;
}

void Trainer::updateTeam(){
    int partySize = Trainer::party->size();
    vector<Pokemon*> newParty;
    for(auto pk: *party){
        cout<<partySize<<","<<party->size()<<endl;
        if(partySize == party->size()){
            partySize--;
            
        } else {
            newParty.push_back(pk);
            cout<<"Added: "<<pk->getName() <<" to the new party"<<endl;
        }
    }
    *party = newParty;
}

const int Trainer::getPartySize() const{
    return Trainer::party->size();
}

void Trainer::setPkmn(Pokemon* pkmn, int lvl, vector<Move*>*ms){
    for(auto pk: *party){
        if(pk == pkmn){
            pk->setLevel(lvl);
            pk->setMoveset(ms);
        }
    }
}


/*void del()(Pokemon*& e) // important to take pointer by reference!
{ 
    delete e;
    e = NULL;
}*/


Pokemon* Trainer::getLeadPkmn(){
    Pokemon* pk = *party->begin();

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
}

void Trainer::mostrarEquipo(){
    cout << "||||||||||||||||| " << classtring(tc) << " " << name << " ||||||||||||||||||||" << endl;
    for(auto pkmn : *party){
        pkmn->mostrar();
    }
}

Trainer::~Trainer(){
    name="";
}