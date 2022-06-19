#include "pokemonDataBase.cpp"

//Lucas
Trainer *Lucas = new Trainer("Lucas",RICH_BOY,{});

//Kaitlin
Trainer *Kaitlin = new Trainer("Kaitlin",LASS,{});

//Cynthia
Trainer *Cynthia = new Trainer("Cynthia",CHAMPION,{});

Trainer *Tobias = new Trainer("Tobias", ACE_TRAINER, {});

void fill(Trainer* trainer){
    for(auto pkmn: trainer->getParty()){
        pkmn->startStats();
    }
}

void chooseTeam(){
    int partySize = 0;

}

void updateTrainers(){
    //Trainer->setPkmn(Pokemon,level,moveset);
    //Lucas
    Lucas->setPkmn(Chimchar,7,new vector<Move*>{Scratch, Leer});
    Lucas->setPkmn(Garchomp,66,new vector<Move*>{DragonRush,Earthquake,BrickBreak,GigaImpact});

    fill(Lucas);


    //Kaitlin
    Kaitlin->setPkmn(Starly,4,new vector<Move*>{Tackle,Growl});
    Kaitlin->setPkmn(Bidoof,4,new vector<Move*>{Tackle,Growl});
    Kaitlin->setPkmn(Budew,4,new vector<Move*>{Absorb,StunSpore});
    Kaitlin->setPkmn(Abra,4,new vector<Move*>{Teleport});

    fill(Kaitlin);

    //Cynthia
    Cynthia->setPkmn(Spiritomb,61,new vector<Move*>{DarkPulse,ShadowBall,Psychic,Embargo});
    Cynthia->setPkmn(Roserade,60,new vector<Move*>{EnergyBall,SludgeBomb,ShadowBall,Extrasensory});
    Cynthia->setPkmn(Gastrodon,60,new vector<Move*>{MuddyWater,Earthquake,StoneEdge,SludgeBomb});
    Cynthia->setPkmn(Lucario,63,new vector<Move*>{AuraSphere,DragonPulse,Psychic,Earthquake});
    Cynthia->setPkmn(Milotic,63,new vector<Move*>{Surf,IceBeam,MirrorCoat,AquaRing});
    Cynthia->setPkmn(Garchomp,66,new vector<Move*>{DragonRush,Earthquake,BrickBreak,GigaImpact});

    fill(Cynthia);

    Tobias->setPkmn(Darkrai,100,new vector<Move*>{IceBeam,DarkPulse,DreamEater,DarkVoid});
    Tobias->setPkmn(Latios,100,new vector<Move*>{GigaImpact, LusterPurge, LightScreen, Recover});

    fill(Tobias);

}