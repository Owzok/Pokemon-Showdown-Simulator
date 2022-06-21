#include "move.h"

Move::Move(string name, int pp, Category category, int power, int acurracy, string side_effect, PkmnTypes type):name(name),pp(pp),category(category),power(power),acurracy(acurracy),side_effect(side_effect),type(type){
    currentPP = pp;
}
const string Move::getName() const{
    return name;
}
const int Move::getCurrentPP() const{
    return currentPP;
}
const int Move::getPP() const{
    return pp;
}
const Category Move::getCategory() const{
    return category;
}
const int Move::getPower() const{
    return power;
}
const int Move::getAccurracy() const{
    return acurracy;
}
const string Move::getSideEffect() const{
    return side_effect;
}
const PkmnTypes Move::getMoveType() const{
    return type;
}

void Move::lessPP(){
    currentPP--;
}

string Move::moveTypeString(PkmnTypes tipo){
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
        case PkmnTypes::ELECTRIC:
            return "ELECTRIC";
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
}

void Move::printMove(){
    cout<<name<<"       \t"<<moveTypeString(type)<<"\t\t"<<power<<"\t"<<currentPP<<"/"<<pp<<endl;
}

Move::~Move(){
    pp=0;
    power=0;
    acurracy=0;
    side_effect="";
}