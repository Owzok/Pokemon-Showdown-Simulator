#include "sampleTrainersDB.cpp"
#include <conio.h>

void clearScreen(){ system("cls"); }

//Cynthia
Trainer *Cynthia = new Trainer("Cynthia",CHAMPION,{});

Trainer *Tobias = new Trainer("Tobias", ACE_TRAINER, {});

Trainer *Flint = new Trainer("Flint", ELITE_FOUR, {});

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
    //Flint
    Flint->setPkmn(pokemones.at("Houndoom"),50,{moves.at("Flamethrower"),moves.at("Sludge Bomb"),moves.at("Dark Pulse"),moves.at("Sunny Day")});
    Flint->setPkmn(pokemones.at("Flareon"),50,{moves.at("Overheat"),moves.at("Giga Impact"),moves.at("Quick Attack"),moves.at("Will-O-Wisp")});
    Flint->setPkmn(pokemones.at("Rapidash"),50,{moves.at("Flare Blitz"),moves.at("Solar Beam"),moves.at("Bounce"),moves.at("Sunny Day")});
    Flint->setPkmn(pokemones.at("Infernape"),50,{moves.at("Flare Blitz"),moves.at("Thunder Punch"),moves.at("Mach Punch"),moves.at("Earthquake")});
    Flint->setPkmn(pokemones.at("Magmortar"),50,{moves.at("Flamethrower"),moves.at("Thunderbolt"),moves.at("Solar Beam"),moves.at("Hyper Beam")});

    fill(Flint);

    //Tobias
    Tobias->setPkmn(pokemones.at("Darkrai"), 50, {moves.at("Dark Pulse"), moves.at("Dark Void"), moves.at("Ice Beam"), moves.at("Nasty Plot")});
    Tobias->setPkmn(pokemones.at("Latios"), 50, {moves.at("Light Screen"), moves.at("Recover"), moves.at("Luster Purge"), moves.at("Giga Impact")});

    fill(Tobias);

    //Cynthia
    Cynthia->setPkmn(pokemones2.at("Spiritomb"),50,{moves.at("Dark Pulse"),moves.at("Will-O-Wisp"),moves.at("Psychic"),moves.at("Embargo")});
    Cynthia->setPkmn(pokemones2.at("Roserade"),50,{moves.at("Energy Ball"),moves.at("Sludge Bomb"),moves.at("Shadow Ball"),moves.at("Extrasensory")});
    Cynthia->setPkmn(pokemones2.at("Gastrodon"),50,{moves.at("Muddy Water"),moves.at("Earthquake"),moves.at("Stone Edge"),moves.at("Sludge Bomb")});
    Cynthia->setPkmn(pokemones2.at("Lucario"),50,{moves.at("Aura Sphere"),moves.at("Dragon Pulse"),moves.at("Psychic"),moves.at("Earthquake")});
    Cynthia->setPkmn(pokemones2.at("Milotic"),50,{moves.at("Surf"),moves.at("Ice Beam"),moves.at("Mirror Coat"),moves.at("Aqua Ring")});
    Cynthia->setPkmn(pokemones2.at("Garchomp"),50,{moves.at("Dragon Rush"),moves.at("Earthquake"),moves.at("Brick Break"),moves.at("Giga Impact")});

    fill(Cynthia);
}

Trainer* start(){
    updateTrainers();
    char teamBuilding;
    string name;

    Trainer *t;

    cout << "Do you want to create your own team? [Y/N]: " << endl; 
    cin >> teamBuilding;

    if(teamBuilding == 'Y'){
        cout << "Choose your name: " << endl; cin >> name;
        player->setName(name);
        chooseTeam(player);
        fill(player);
        return player;

    } else {
        int name;
        cout << "Choose your team: " << endl;
        cout << "[1] Flint" << endl;
        cout << "[2] Tobias" << endl;

        cin >> name;

        switch(name){
            case 1:
                return Flint;
            break;
            case 2:
                return Tobias;
            break;
        }
    }
    return Flint;
}