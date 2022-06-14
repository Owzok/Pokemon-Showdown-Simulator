#include "pokemon.h"

Pokemon::Pokemon(string name, int id, int level, int HP, int ATK, int DEF, int SPE, string ability, PkmnTypes type1, 
        PkmnTypes type2, vector<Move*> *moveset, vector<Move*> *movepool, PkmnStatus Status
        ):name(name),id(id),level(level),ability(ability),type1(type1),type2(type2),HP(HP),ATK(ATK),DEF(DEF),
        SPE(SPE),moveset(moveset),movepool(movepool),Status(Status){
    updateStats();
}
const string Pokemon::getName() const{
    return name;
}
const int Pokemon::getId() const{
    return id;
}
const int Pokemon::getLevel() const{
    return level;
}
void Pokemon::setLevel(const int &level){
    Pokemon::level = level;
}
const int Pokemon::getHP() const{
    return HP;
}
void Pokemon::setHP(const int &HP){
    Pokemon::HP=HP;
}
const int Pokemon::getATK() const{
    return ATK;
}
const int Pokemon::getDEF() const{
    return DEF;
}
const int Pokemon::getSPE() const{
    return SPE;
}
const string Pokemon::getAB() const{
    return ability;
}

const PkmnTypes Pokemon::getType1() const{
    return type1;
}
const PkmnTypes Pokemon::getType2() const{
    return type2;
}
vector<Move*> *Pokemon::getMoveset(){
    return moveset;
}
vector<Move*> *Pokemon::getMovepool(){
    return movepool;
}

void Pokemon::setMoveset(vector<Move*> *moveset){
    Pokemon::moveset = moveset;
}

void Pokemon::printMoveset(){
    for(auto mve: *moveset){
        mve->printMove();
    }
}

void Pokemon::updateStats(){
    int IV = 15;
    int EV = 85;
    ATK = floor(0.01*(2*ATK+IV+floor(0.25*EV))*level) + 5;
    DEF = floor(0.01*(2*DEF+IV+floor(0.25*EV))*level) + 5;
    SPE = floor(0.01*(2*SPE+IV+floor(0.25*EV))*level) + 5;
    HP = floor(0.01*(2*HP+IV+floor(0.25*EV))*level) + level + 10;

    switch (Status){
    case PkmnStatus::PARALYZED:
        SPE /= 2;
        break;
    case PkmnStatus::BURNED:
        ATK /= 2;
        break;
    }

}

void Pokemon::levelup(){
    level++;
    updateStats();
}

string Pokemon::statusString(PkmnStatus status){
    switch(status){
        case PkmnStatus::FROZEN:
            return "FRZ";
        break;
        case PkmnStatus::BURNED:
            return "BRN";
        break;
        case PkmnStatus::POISONED:
            return "PSN";
        break;
        case PkmnStatus::BADLY_POISONED:
            return "PSN";
        break;
        case PkmnStatus::PARALYZED:
            return "PAR";
        break;
        case PkmnStatus::SLEEP:
            return "SLP";
        break;
        case PkmnStatus::CONFUSED:
            return "CFD";
        break;
        case PkmnStatus::ATTRACTED:
            return "ATT";
        break;
        case PkmnStatus::HEALTHY:
            return "";
        break;
    }
    return "";
}

string Pokemon::typeString(PkmnTypes tipo){
    switch(tipo){
        case PkmnTypes::BUG:
            return "BUG";
        break;
        case PkmnTypes::DARK:
            return "DARK";
        break;
        case PkmnTypes::DRAGON:
            return "DRAGON";
        break;
        case PkmnTypes::ELECRTRIC:
            return "ELECRTRIC";
        break;
        case PkmnTypes::FAIRY:
            return "FAIRY";
        break;
        case PkmnTypes::FIGHTING:
            return "FIGHTING";
        break;
        case PkmnTypes::FIRE:
            return "FIRE";
        break;
        case PkmnTypes::FLYING:
            return "FLYING";
        break;
        case PkmnTypes::GHOST:
            return "GHOST";
        break;
        case PkmnTypes::GRASS:
            return "GRASS";
        break;
        case PkmnTypes::GROUND:
            return "GROUND";
        break;
        case PkmnTypes::ICE:
            return "ICE";
        break;
        case PkmnTypes::NORMAL:
            return "NORMAL";
        break;
        case PkmnTypes::POISON:
            return "POISON";
        break;
        case PkmnTypes::PSYCHIC:
            return "PSYCHIC";
        break;
        case PkmnTypes::ROCK:
            return "ROCK";
        break;
        case PkmnTypes::STEEL:
            return "STEEL";
        break;
        case PkmnTypes::WATER:
            return "WATER";
        break;
        default:
            return "NONE";
        break;
    }
    return "";
}

string Pokemon::getStatus(){
    return statusString(Status);
}

void Pokemon::setStatus(PkmnStatus status){
    Pokemon::Status = status;
}

void Pokemon::mostrar(){
    cout << "\n-------------" << endl;
    cout << getName() << "\tID: " << getId() << endl;
    cout << "\nLevel: " << getLevel() << "\t";
    cout << "HP: " << getHP() << "\t";
    cout << "ATK: " << getATK() << "\t";
    cout << "DEF: " << getDEF() << "\t";
    cout << "SPE: " << getSPE() << endl;
    cout << "\nTypes: ";
    cout << typeString(getType1());
    if(typeString(getType2()) != "NONE"){
        cout << ", " << typeString(getType2());
    }
    cout << "\tAbility: " << getAB() << endl;
    cout << "\nMoves: \t name \t power \t acc \t pp's \t type" << endl;
    for(auto m: *moveset){
        cout << "\t" << m->getName() << "\t" << m->getPower() << "\t" << m->getAccurracy() << "\t" << m->getPP() << "\t" << typeString(m->getMoveType()) << endl;
    }
    cout<<endl;
}

Pokemon::~Pokemon(){
    name="";
    id=0;
    level=0;
    HP=0;
    ATK=0;
    DEF=0;
    SPE=0;
}