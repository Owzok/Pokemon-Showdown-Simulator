#include "pokemonDataBase.cpp"
#include <conio.h>

void clearScreen(){ system("cls"); }

//Lucas
Trainer *Lucas = new Trainer("Lucas",RICH_BOY,{});

//Kaitlin
Trainer *Kaitlin = new Trainer("Kaitlin",LASS,{});

//Cynthia
Trainer *Cynthia = new Trainer("Cynthia",CHAMPION,{});

Trainer *Tobias = new Trainer("Tobias", ACE_TRAINER, {});

Trainer* player = new Trainer("",RICH_BOY,{});


void fill(Trainer* trainer){
    for(auto pkmn: trainer->getParty()){
        pkmn->startStats();
    }
}

vector<Move*> chooseMoveset(Pokemon* pkmn){
    cout << pkmn->getName() << " attacks: " << endl;
    vector<Move*> movepool = pkmn->getMovepool();
    vector<Move*> new_moveset;
    int index = 1;

    int chosen_move;

    for(auto &move : movepool){
        cout << "["<<index<<"] ";
        move->printMove();
        index++;
    }

    for(int i = 0; i < 4; i++){
        do{
            cout << "Choose an attack. ["<<i<<"/4]: \t";
            cin >> chosen_move;
        } while(chosen_move < 0 || chosen_move > index);

        new_moveset.push_back(movepool[chosen_move-1]);
    }
    return new_moveset;
}

template<typename Map>
Pokemon* choosePkmn(Map &m){
    Pokemon* pkmn;
    string chosenPokemon;
    int index = 1;
    bool exists = false;

    for (auto &item : m) {
        pkmn = item.second;
        cout << "["<<index<<"] ";
        pkmn->mostrar();
        cout << "-------------------------" << endl;
        index++;
    }
    do{
        cout << "Choose a pokemon." << endl;
        cin >> chosenPokemon;

        for (auto &item : m) {
            if(chosenPokemon == item.first){
                exists = true;
                pkmn = item.second;
            }
        }
        if(exists == false)
            cout << "The chosen pokemon doesn't exists" << endl;
    } while(exists == false);
    clearScreen();
    return pkmn;
}

void chooseTeam(Trainer* player){
    int partySize = 0;
    do{
        cout << "Set your party size.\t";
        cin >> partySize;
    } while(partySize < 1 || partySize > 6);

    vector<Pokemon*> party;

    for(int i = 0; i < partySize; i++){
        clearScreen();
        Pokemon* pkmn = choosePkmn(pokemones);
        vector<Move*> moveset = chooseMoveset(pkmn);
        int level;
        cout << "Choose the level for the pokemon [1-100].\t";
        do{
            cin >> level;
        } while(level < 1 || level > 100);

        player->setPkmn(pkmn,level,moveset);
    }
}

void updateTrainers(){
    string name;
    cout << "Choose your name: " << endl; cin >> name;
    player->setName(name);
    chooseTeam(player);

    fill(player);

    //Trainer->setPkmn(Pokemon,level,moveset);
    //Lucas
    Lucas->setPkmn(Chimchar,7,{Scratch, Leer});
    Lucas->setPkmn(Garchomp,66,{DragonRush,Earthquake,BrickBreak,GigaImpact});

    fill(Lucas);


    //Kaitlin
    Kaitlin->setPkmn(Starly,4,{Tackle,Growl});
    Kaitlin->setPkmn(Bidoof,4,{Tackle,Growl});
    Kaitlin->setPkmn(Budew,4,{Absorb,StunSpore});
    Kaitlin->setPkmn(Abra,4,{Teleport});

    fill(Kaitlin);

    //Cynthia
    Cynthia->setPkmn(Spiritomb,61,{DarkPulse,ShadowBall,Psychic,Embargo});
    Cynthia->setPkmn(Roserade,60,{EnergyBall,SludgeBomb,ShadowBall,Extrasensory});
    Cynthia->setPkmn(Gastrodon,60,{MuddyWater,Earthquake,StoneEdge,SludgeBomb});
    Cynthia->setPkmn(Lucario,63,{AuraSphere,DragonPulse,Psychic,Earthquake});
    Cynthia->setPkmn(Milotic,63,{Surf,IceBeam,MirrorCoat,AquaRing});
    Cynthia->setPkmn(Garchomp,66,{DragonRush,Earthquake,BrickBreak,GigaImpact});

    fill(Cynthia);

    Tobias->setPkmn(Darkrai,100,{IceBeam,DarkPulse,DreamEater,DarkVoid});
    Tobias->setPkmn(Latios,100,{GigaImpact, LusterPurge, LightScreen, Recover});

    fill(Tobias);

}