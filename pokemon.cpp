#include "pokemon.h"

Pokemon::Pokemon(string name, int id, int level, int HP, int ATK, int DEF, int SPE, string ability, PkmnTypes type1, 
        PkmnTypes type2, vector<Move*> *moveset, vector<Move*> *movepool, PkmnStatus Status
        ):name(name),id(id),level(level),ability(ability),type1(type1),type2(type2),HP(HP),ATK(ATK),DEF(DEF),
        SPE(SPE),moveset(moveset),movepool(movepool),Status(Status){
    startStats();
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
void Pokemon::setCurrentHP(const int &HP){
    Pokemon::cur_hp=HP;
}
const int Pokemon::getMaxHP() const{
    return max_hp;
}
const int Pokemon::getHP() const{
    return cur_hp;
}
const int Pokemon::getATK() const{
    return cur_atk;
}
const int Pokemon::getDEF() const{
    return cur_def;
}
const int Pokemon::getSPE() const{
    return cur_spe;
}
const int Pokemon::get_baseHP() const{
    return HP;
}
const int Pokemon::get_baseATK() const{
    return ATK;
}
const int Pokemon::get_baseDEF() const{
    return DEF;
}
const int Pokemon::get_baseSPE() const{
    return SPE;
}
const string Pokemon::getAB() const{
    return ability;
}
const PkmnStatus Pokemon::getStatus() const{
    return Status;
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

string Pokemon::printData(){
    string data = ("\tPokemon: "+name+"\n\tLevel: "+to_string(level)+"\n\tType 1: " + typeString(type1)+"\n\tType 2: " + typeString(type2)+"\n\tAbility: "+ability+"\n\tStatus: "+statusString(Status)+"\n\tHp: "+to_string(HP)+"\n\tAttack: "+to_string(ATK)+"\n\tDefense: "+to_string(DEF)+"\n\tSpeed: "+to_string(SPE)+"\n");
    return data;
}

void Pokemon::startStats(){
    int IV = 15;
    int EV = 85;
    cur_atk = (0.01*(2*ATK+IV+(0.25*EV))*level) + 5;
    cur_def = (0.01*(2*DEF+IV+(0.25*EV))*level) + 5;
    cur_spe = (0.01*(2*SPE+IV+(0.25*EV))*level) + 5;
    cur_hp = (0.01*(2*HP+IV+(0.25*EV))*level) + level + 10;
    max_hp = (0.01*(2*HP+IV+(0.25*EV))*level) + level + 10;
}

void Pokemon::updateStats(){
    startStats();
    switch (Status){
    case PkmnStatus::PARALYZED:
        cur_spe /= 2;
        break;
    case PkmnStatus::BURNED:
        cur_atk /= 2;
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

string Pokemon::getStatusString(){
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