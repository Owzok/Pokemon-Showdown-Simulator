#include "pokemonDataBase.cpp"

//Lucas
vector<Pokemon> LucasParty = {Chimchar, Starly};
Trainer Lucas {"Lucas",RICH_BOY,LucasParty};

//Kaitlin
vector<Pokemon> KaitlinParty = {Budew, Bidoof, Starly, Abra};
Trainer Kaitlin {"Kaitlin",LASS,KaitlinParty};

//Cynthia
vector<Pokemon> CynthiaParty = {Spiritomb, Roserade, Gastrodon, Lucario, Milotic, Garchomp};
Trainer Cynthia = {"Cynthia",CHAMPION,CynthiaParty};

void updateTrainers(){
    //Trainer->setPkmn(Pokemon,level,moveset);
    //Lucas
    Lucas.setPkmn(Chimchar,7,new vector<Move*>{Scratch, Leer});
    Lucas.setPkmn(Starly,7,new vector<Move*>{Tackle, Growl});
    for(auto pkmn: LucasParty){
        pkmn.updateStats();
    }

    //Kaitlin
    Kaitlin.setPkmn(Starly,4,new vector<Move*>{Tackle,Growl});
    Kaitlin.setPkmn(Bidoof,4,new vector<Move*>{Tackle,Growl});
    Kaitlin.setPkmn(Budew,4,new vector<Move*>{Absorb,StunSpore});
    Kaitlin.setPkmn(Abra,4,new vector<Move*>{Teleport});
    for(auto pkmn: KaitlinParty){
        pkmn.updateStats();
    }

    //Cynthia
    Cynthia.setPkmn(Spiritomb,61,new vector<Move*>{DarkPulse,ShadowBall,Psychic,Embargo});
    Cynthia.setPkmn(Roserade,60,new vector<Move*>{EnergyBall,SludgeBomb,ShadowBall,Extrasensory});
    Cynthia.setPkmn(Gastrodon,60,new vector<Move*>{MuddyWater,Earthquake,StoneEdge,SludgeBomb});
    Cynthia.setPkmn(Lucario,63,new vector<Move*>{AuraSphere,DragonPulse,Psychic,Earthquake});
    Cynthia.setPkmn(Milotic,63,new vector<Move*>{Surf,IceBeam,MirrorCoat,AquaRing});
    Cynthia.setPkmn(Garchomp,66,new vector<Move*>{DragonRush,Earthquake,BrickBreak,GigaImpact});
    for(auto pkmn: CynthiaParty){
        pkmn.updateStats();
    }
}