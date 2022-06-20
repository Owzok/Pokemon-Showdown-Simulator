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



    fill(Kaitlin);

    //Cynthia
    Cynthia->setPkmn(pokemones.at("Spiritomb"),61,{moves.at("Dark Pulse"),moves.at("Shadow Ball"),moves.at("Psychic"),moves.at("Embargo")});
    Cynthia->setPkmn(pokemones.at("Roserade"),60,{moves.at("Energy Ball"),moves.at("Sludge Bomb"),moves.at("Shadow Ball"),moves.at("Extrasensory")});
    Cynthia->setPkmn(pokemones.at("Gastrodon"),60,{moves.at("Muddy Water"),moves.at("Earthquake"),moves.at("Stone Edge"),moves.at("Sludge Bomb")});
    Cynthia->setPkmn(pokemones.at("Lucario"),63,{moves.at("Aura Sphere"),moves.at("Dragon Pulse"),moves.at("Psychic"),moves.at("Earthquake")});
    Cynthia->setPkmn(pokemones.at("Milotic"),63,{moves.at("Surf"),moves.at("Ice Beam"),moves.at("Mirror Coat"),moves.at("Aqua Ring")});
    Cynthia->setPkmn(pokemones.at("Garchomp"),66,{moves.at("Dragon Rush"),moves.at("Earthquake"),moves.at("Brick Break"),moves.at("Giga Impact")});

    fill(Cynthia);

}