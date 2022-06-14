#include "pokemonDataBase.cpp"


//Lucas
vector<Pokemon*> *LucasParty = new vector<Pokemon*>{Chimchar, Starly};
Trainer *Lucas = new Trainer("Lucas",RICH_BOY,LucasParty);

//Kaitlin
vector<Pokemon*> *KaitlinParty = new vector<Pokemon*>{Budew, Bidoof, Starly, Abra};
Trainer *Kaitlin = new Trainer("Kaitlin",LASS,KaitlinParty);

//Cynthia
vector<Pokemon*> *CynthiaParty = new vector<Pokemon*>{Spiritomb, Roserade, Gastrodon, Lucario, Milotic, Garchomp};
Trainer *Cynthia = new Trainer("Cynthia",CHAMPION,CynthiaParty);

void updateTrainers(){
    //Trainer->setPkmn(Pokemon,level,moveset);
    //Lucas
    Lucas->setPkmn(Chimchar,9,new vector<Move*>{Scratch, Leer});
    Lucas->setPkmn(Starly,7,new vector<Move*>{Tackle, Growl});
    for(auto pkmn: *LucasParty){
        pkmn->updateStats();
    }

    //Kaitlin
    Kaitlin->setPkmn(Starly,4,new vector<Move*>{Tackle,Growl});
    Kaitlin->setPkmn(Bidoof,4,new vector<Move*>{Tackle,Growl});
    Kaitlin->setPkmn(Budew,4,new vector<Move*>{Absorb,Growth,StunSpore,WorrySeed});
    Kaitlin->setPkmn(Abra,4,new vector<Move*>{Teleport});
    for(auto pkmn: *KaitlinParty){
        pkmn->updateStats();
    }

    //Cynthia
    Cynthia->setPkmn(Spiritomb,61,new vector<Move*>{DarkPulse,ShadowBall,Psychic,Embargo});
    Cynthia->setPkmn(Roserade,60,new vector<Move*>{EnergyBall,SludgeBomb,ShadowBall,Extrasensory});
    Cynthia->setPkmn(Gastrodon,60,new vector<Move*>{MuddyWater,Earthquake,StoneEdge,SludgeBomb});
    Cynthia->setPkmn(Lucario,63,new vector<Move*>{AuraSphere,DragonPulse,Psychic,Earthquake});
    Cynthia->setPkmn(Milotic,63,new vector<Move*>{Surf,IceBeam,MirrorCoat,AquaRing});
    Cynthia->setPkmn(Garchomp,66,new vector<Move*>{DragonRush,Earthquake,BrickBreak,GigaImpact});
    for(auto pkmn: *CynthiaParty){
        pkmn->updateStats();
    }
}