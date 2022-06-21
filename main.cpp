#include "trainerDB.cpp"
#include <stdlib.h>
#include <time.h>

/* TextBox (text, clear) : Given a text, pops up a text box with it. The clear bool is to do or not a cls before the text box is shown .
____________________________________________________________

        Chimchar used Scratch and dealt 8 dmg.
____________________________________________________________*/
void textBox(string text, bool clear){
    if(clear)
        clearScreen();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n ____________________________________________________________ \n\n";
    cout <<"\t"<<text;
    cout<<" ____________________________________________________________ "<<endl; getch();
}

/*                       _____________________
                        |
                        | Budew Lv4
                        |  HP:16/16
                        |______________________


 _____________________
|
| Chimchar      Lv7
| PAR HP:21/22
|______________________*/
void ShowPokemonMenuHUD(Trainer *user, Trainer *foe, Pokemon *userPk, Pokemon *enemyPk){
    clearScreen();
    string userStatus = userPk->getStatusString();
    string enemyStatus = enemyPk->getStatusString();

    //cout << "\t\t" << foe->classtring(foe->getTC())<<" "<<foe->getName();
    cout<<"\n\t\t\t _____________________\n\t\t\t|\n";
    cout << "\t\t\t| " << enemyPk->getName() << "\tLv." << enemyPk->getLevel() << endl;
    cout << "\t\t\t| " << enemyStatus << " HP:" << enemyPk->getHP() << "/" << enemyPk->getMaxHP() << endl;
    cout << "\t\t\t|______________________" << endl;

    cout << "\n";
    //cout << "===== "<<user->classtring(user->getTC())<<" "<<user->getName()<<" ===== \n";    
    cout<<"\n _____________________\n|\n";
    cout << "| " << userPk->getName() << "\tLv" << userPk->getLevel() << endl;
    cout << "| " << userStatus << " HP:" << userPk->getHP() << "/" << userPk->getMaxHP() << endl;  
    cout << "|______________________" << endl;
}

/* movesMenu(userPokemon) : Displays movements and its stats.
____________________________________________________________

        [1] Scratch     NORMAL  40      35/35
        [2] Leer        NORMAL  0       30/30
        [3] < Go Back >
____________________________________________________________*/
Move* movesMenu(Pokemon *userPokemon){
    int temp = 1;
    int chosenMove = 0;
    vector<Move*> moves = userPokemon->getMoveset();

    cout<<"\n ____________________________________________________________ \n\n";
    for(auto mv: moves){
        cout<< "\t[" << temp << "] ";
        mv->printMove();
        temp++;
    }
    cout<<"\t\t[" << temp << "] < Go Back >\n";
    cout<<" ____________________________________________________________ "<<endl;
    do{
        cout << "\nWhat move do you want to do?: "; 
        cin >> chosenMove;
        if(chosenMove == temp){
            return nullptr;
        }    
        Move* move = moves.at(chosenMove-1);
        if(move->getCurrentPP() == 0){
            cout << "There's no PP left for this move!\n" << endl;
            chosenMove = 10000;
        }
            
    } while(chosenMove < 1 || chosenMove > temp);

    return moves.at(chosenMove-1);
}

/* actionsMenu(userPokemon) : Displays which actions the player can do.
____________________________________________________________

    What will Chimchar do?
    [1] Fight
    [2] Change    
    [3] Stats
____________________________________________________________*/
int actionsMenu(Pokemon* userPokemon){
    int decision = 0;
    vector<Move*> moves = userPokemon->getMoveset();

    cout<<"\n ____________________________________________________________ \n\n";
    cout<<"\tWhat will "<<userPokemon->getName()<<" do?\n\t[1] Fight \n\t"<<"[2] Change \n\t[3] Stats\n";
    cout<<" ____________________________________________________________ "<<endl;

    do{ cout<<"Opcion: ";cin>>decision; } while(decision < 1 || decision > 3);

    return decision;
}

// 1 => User is faster
// 2 => Enemy is faster
// Speedtie, chooses randomly between 1 and 2
int speedCheck(Pokemon* uPkmn, Pokemon* ePkmn){
    if (uPkmn->getSPE() > ePkmn->getSPE()){
        return 1; //user faster
    } else if (uPkmn->getSPE() < ePkmn->getSPE()) {
        return 2; //enemy faster
    } else {
        int random = rand() % 2+1;
        return random; //speedtie random between 1 and 2
    }
}

// 80 % True (confused) || 20 % False (snap out)
bool statusCFD(Pokemon* pkmn){
    textBox(pkmn->getName()+"is confused!\n",true);
    if(rand()%100+1 < 80){
        if(rand()%100+1 < 50){
            textBox("it hurt itself in its confusion!\n", true);
            return true;
        }
        return true;
    }
    textBox(pkmn->getName()+" snapped out of its confusion!\n", true);
    pkmn->setStatus(HEALTHY);
    return false;
}

// 80 % True (sleep) || 20 % False (wake up)
bool statusSLP(Pokemon* pkmn){
    if(rand()%100+1 < 80){
        textBox(pkmn->getName()+" is fast asleep!\n", true);
        return true;
    }
    textBox(pkmn->getName()+" woke up!\n", true);
    pkmn->setStatus(HEALTHY);
    return false;
}

// 80 % True (frozen) || 20 % False (thawed out)
bool statusFRZ(Pokemon* pkmn){
    if(rand()%100+1 < 80){
        textBox(pkmn->getName()+" is frozen solid!\n", true);
        return true;
    }
    textBox(pkmn->getName()+" thawed out!\n", true);
    pkmn->setStatus(HEALTHY);
    return false;
}

// 50% True (is paralyzed) || 50% False (attacks)
bool statusPAR(Pokemon* pkmn){
    if(rand()%100+1 < 50){
        textBox(pkmn->getName()+" is paralyzed!\tIt can't move!\n", true);
        return true;
    }
    return false;
}

// 50% True (is in love) || 50% False (attacks)
bool statusATT(Pokemon* pkmn){
    if(rand()%100+1 < 50){
        textBox(pkmn->getName()+" is in love with the Foe!\n", true);
        return true;
    }
    return false;
}

// Checks probabilities and decides to continue or not depending on a pokemon condition
bool checkStatus(Pokemon *userPkmn){
    PkmnStatus status = userPkmn->getStatus();
    switch(status){
        case PkmnStatus::FROZEN:
        // 0 : Is frozen slid
        // 1 : thawed out
            if(statusFRZ(userPkmn)){
                return false;
            }
            return true;
        break;
        case PkmnStatus::PARALYZED:
        // 0 : Is paralyzed it can't move !
        // 1 : Attacks 
            if(statusPAR(userPkmn))
            {
                return false;
            }
            return true;
        break;
        case PkmnStatus::SLEEP:
        // 0 : Is fast asleep 
        // 1 : Woke up 
            if(statusSLP(userPkmn))
            {
                return false;
            }
            return true;      
        break;
        case PkmnStatus::CONFUSED:
            if(statusCFD(userPkmn)){
                return false;
            }
            return true;
        break;
        case PkmnStatus::ATTRACTED:
        // 0 : Is in love
        // 1 : Is no longer in love
            if(statusATT(userPkmn)){
                return false;
            }
            return true;
        break;  
    }
    return true;
}

//Turns move description into a vector of data
vector<string> getSideEffectsFromMove(Move *move){
    string txt = move->getSideEffect();
    vector<string> campos = vector<string>();
    string delimeter = "|";
    size_t pos = 0;
    string token;
    while((pos = txt.find(delimeter)) != string::npos){
        token = txt.substr(0,pos);
        campos.push_back(token);
        txt.erase(0,pos+delimeter.length());
    }
    token = txt.substr(0,pos);
    campos.push_back(token);
    return campos;
}


/* Move("Stun Spore",30,STATUS,0,75,"s|100|2",GRASS);
// < s , 100 , 2 >
// [0] = s or ""    =>  Status move effect or not
// [1] = [0-100]    =>  Probabilty of applying status effect
// [2] = [0-6]      =>  Status Condition
                            0: Sleep
                            1: Frozen
                            2: Paralyzed
                            3: Burned
                            4: Poisoned
                            5: Confused
                            6: Attracted
*/

// Checks probabilities of a move to apply a condition on the enemy 
void movementStatusEffect(Pokemon *user, Pokemon *enemy, Move* move, string status, int chance){
    int status_num;
    if(status == "SLP"){
        status_num = 0;
    }
    if(status == "FRZ"){
        status_num = 1;
    }
    if(status == "PAR"){
        status_num = 2;
    }
    if(status == "BRN"){
        status_num = 3;
    }
    if(status == "PSN"){
        status_num = 4;
    }
    if(status == "CFD"){
        status_num = 5;
    }
    if(status == "ATT"){
        status_num = 6;
    }

    if(rand()%100+1 < chance){
        switch(status_num){
            case 0:
                if(enemy->getStatusString() == "SLP"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(SLEEP);

                        textBox(enemy->getName()+" is now asleep! \n", true);
                    }
            break;
            case 1:
                if(enemy->getStatusString() == "FRZ"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(FROZEN);

                        textBox(enemy->getName()+" is now frozen! \n", true);
                    }
            break;
            case 2:
                if(enemy->getStatusString() == "PAR"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(PARALYZED);
                    
                        textBox(enemy->getName()+" is now paralyzed! It may be unable to move!\n", true);
                    }
            break;
            case 3:
                if(enemy->getStatusString() == "BRN"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(BURNED);

                        textBox(enemy->getName()+" is now burned!\n", true);
                    }
            break;
               case 4:
                if(enemy->getStatusString() == "PSN"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(POISONED);

                        textBox(enemy->getName()+" is now poisoned!\n", true);
                    }
            break;
            case 5:
                if(enemy->getStatusString() == "CFD"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(CONFUSED);

                        textBox(enemy->getName()+" is now confused!\n", true);
                    }
            break;
            case 6:
                if(enemy->getStatusString() == "PAR"){
                        textBox(enemy->getName()+" is already "+enemy->getStatusString()+"!\n",true);
                } else {
                        enemy->setStatus(ATTRACTED);

                        textBox(enemy->getName()+" fell in love with the Foe "+user->getName()+"!\n", true);
                    }
            break;
        }
    }
}

// Given a chance, objective, stat and amount it raises or lowers the stat of a pokemon
void movementStatEffect(Pokemon *user, Pokemon *enemy, int chance, string who, string stat, int amount){
    // if yes
    if(rand()%100+1 < chance)
    {
        if(who == "+user"){
            if(stat == "ATK"){
                user->boost(1,amount);
                switch (amount)
                {
                case 1:
                    textBox(enemy->getName()+" Attack rose!\n", true);
                    break;
                case 2:
                    textBox(enemy->getName()+" Attack sharply rose!\n", true);
                    break;
                }
            }
            if(stat == "DEF"){
                user->boost(2,amount);
                switch (amount)
                {
                case 1:
                    textBox(enemy->getName()+" Defense rose!\n", true);
                    break;
                case 2:
                    textBox(enemy->getName()+" Defense sharply rose!\n", true);
                    break;
                }
            }
            if(stat == "SPE"){
                user->boost(3,amount);
                switch (amount)
                {
                case 1:
                    textBox(enemy->getName()+" Speed rose!\n", true);
                    break;
                case 2:
                    textBox(enemy->getName()+" Speed sharply rose!\n", true);
                    break;
                }
            }
            if(user->getATKchange() > 6)
                user->setATKChange(6);
            if(user->getATKchange() < -6)
                user->setATKChange(-6);
            if(user->getDEFchange() > 6)
                user->setDEFChange(6);
            if(user->getDEFchange() < -6)
                user->setDEFChange(-6);
            if(user->getSPEchange() > 6)
                user->setSPEChange(6);
            if(user->getSPEchange() < -6)
                user->setSPEChange(-6);
        }
        if(who == "-enemy")
        {
            if(stat == "ATK"){
                enemy->boost(1, -1*amount);
                switch (amount)
                {
                case 1:
                    textBox(enemy->getName()+" Attack fell!\n", true);
                    break;
                case 2:
                    textBox(enemy->getName()+" Attack harshly fell!\n", true);
                    break;
                case 3:
                    textBox(enemy->getName()+" Attack severely fell!\n", true);
                    break;
                }
            }
            if(stat == "DEF"){
                enemy->boost(2,-1*amount);
                switch (amount)
                {
                case 1:
                    textBox(enemy->getName()+" Defense fell!\n", true);
                    break;
                case 2:
                    textBox(enemy->getName()+" Defense harshly fell!\n", true);
                    break;
                case 3:
                    textBox(enemy->getName()+" Defense severely fell!\n", true);
                    break;
                }
            }
            if(stat == "SPE")
            {
                enemy->boost(3,-1*amount);
                switch (amount){
                case 1:
                    textBox(enemy->getName()+" Speed fell!\n", true);
                    break;
                case 2:
                    textBox(enemy->getName()+" Speed harshly fell!\n", true);
                    break;
                case 3:
                    textBox(enemy->getName()+" Speed severely fell!\n", true);
                    break;
                }
            }
            if(enemy->getATKchange() > 6)
                enemy->setATKChange(6);
            if(enemy->getATKchange() < -6)
                enemy->setATKChange(-6);
            if(enemy->getDEFchange() > 6)
                enemy->setDEFChange(6);
            if(enemy->getDEFchange() < -6)
                enemy->setDEFChange(-6);
            if(enemy->getSPEchange() > 6)
                enemy->setSPEChange(6);
            if(enemy->getSPEchange() < -6)
                enemy->setSPEChange(-6);
        }
    }
}

// Given a percentage, the pokemon regains health
void movementRecover(Pokemon *user, double amount){
    int total_hp = user->getMaxHP();

    int hp_to_recover = total_hp * (amount/100);
    user->setCurrentHP(user->getHP()+hp_to_recover);
    textBox(user->getName()+" regained health!\n",true);
}

// Checks the effect of the given movement
bool movementEffect(Pokemon *user, Pokemon *enemy, Move* move){
    vector<string> campos = getSideEffectsFromMove(move);

    // CHECKS IF THE MOVEMENT EFFECT IS A STATUS ONE
    // movementStatusEffect(user, enemy, move, status, chance);
    if (campos.at(0) == "status"){
        int chance = stoi(campos.at(1));
        string status = campos.at(2);

        movementStatusEffect(user, enemy, move, status, chance);
    }
    
    // CHECKS IF THE MOVEMENT EFFECT IS A STAT ONE
    // stat | 10 | -enemy | D | 1
    //   0     1      2     3   4
    // movementStatEffect(user, enemy, chance, who, stat, amount);
    if (campos.at(0) == "stat"){
        int chance = stoi(campos.at(1));
        string who = campos.at(2);
        string stat = campos.at(3);
        int amount = stoi(campos.at(4));
        
        movementStatEffect(user, enemy, chance, who, stat, amount);
    }

    // CHECKS IF THE MOVEMENT EFFECT IS A RECOVERY ONE
    // movementRecover(user, percentage);
    if (campos.at(0) == "recover"){
        movementRecover(user, stoi(campos.at(1)));
    }

    if(move->getName() == "Dream Eater"){
        if(enemy->getStatusString() == "SLP"){
            movementRecover(user, 30);
        }
        else {
            textBox("But it failed!\n", true);
            return false;
        }
    }
    
    
    return true;
}

void effectivenessMessage(double x){
    if(x == 0){
        textBox("It doesn't affect.+"+to_string(x)+"\n",true);
    } else if(x < 1){
        textBox("Its not very effective! +"+to_string(x)+"\n",true);
    } else if(x > 1){
        textBox("Its super effective!+"+to_string(x)+"\n",true);
    }
}

bool STAB(Pokemon *user, Move* move){
    if(move->getMoveType() == user->getType1() || move->getMoveType() == user->getType2()){
        return true;
    }
    return false;
}

double calcEffectiveness(PkmnTypes pkmnType1, PkmnTypes pkmnType2, PkmnTypes moveType, bool test){

    map<PkmnTypes, double> effectiveMap = Effectiveness.at(moveType);
    double effectiveness1 = effectiveMap.at(pkmnType1);

    if(pkmnType2 != NONE){
        double effectiveness2 = effectiveMap.at(pkmnType2);
        //textBox("Effectiveness: "+to_string(effectiveness1*effectiveness2)+"\n",true);
        if(!test)
            effectivenessMessage(effectiveness1*effectiveness2);
        return effectiveness1 * effectiveness2;
    } else {
        //textBox("Effectiveness: "+to_string(effectiveness1)+"\n",true);
        if(!test)
            effectivenessMessage(effectiveness1);
        return effectiveness1;
    }
}

int dmgFormula(Pokemon *userPkmn, Pokemon *enemyPokemon, Move* move, bool test){
    if(move->getPower() != 0){
        int atk_stat,def_stat;
        
        if(move->getCategory() == Category::PHYSICAL)
        {
            atk_stat = userPkmn->getATK();
        }
        if(move->getCategory() == Category::SPECIAL){
            atk_stat = userPkmn->getSPA();
        }

        if(move->getCategory() == Category::PHYSICAL){
            def_stat = userPkmn->getDEF();
        }
        if(move->getCategory() == Category::SPECIAL){
            def_stat = userPkmn->getSPD();
        }

        double effectiveness = calcEffectiveness(enemyPokemon->getType1(), enemyPokemon->getType2(), move->getMoveType(), test);
        if(effectiveness == 0)
            return 0;

        double stab = 1;
        if(STAB(userPkmn, move)){ 
            stab = 1.5; 
        }

        return trunc(trunc(trunc(trunc(trunc(trunc(2*userPkmn->getLevel())/5)+2) * move->getPower() * atk_stat/def_stat)/50)+2)*effectiveness * stab;
    }
    return 0;
}

// returns the pokemon to change
Pokemon* IAChangeOption(vector<Pokemon*> team, Pokemon* user, Pokemon* enemy){
    vector<Pokemon*> options {};

    for(const auto pokemon : team){
        // if its not the active pokemon
        if(pokemon != team[0]){
            vector<Move*> moves = pokemon->getMoveset();
            bool supereffective = false;

            // if has a supereff move agains the enemy
            for(const auto &m: moves){
                if(calcEffectiveness(user->getType1(), user->getType2(), m->getMoveType(), true) > 1){
                    //textBox("Weakness Move from "+pokemon->getName()+": "+m->getName()+"\n",true);
                    supereffective = true;
                }
            }
            if(supereffective){
                bool hasWeakness = false;
                if(calcEffectiveness(pokemon->getType1(),PkmnTypes::NONE, user->getType1(), true) > 1){
                    hasWeakness = true;
                }
                if(pokemon->getType2() != PkmnTypes::NONE){
                    if(calcEffectiveness(pokemon->getType2(),PkmnTypes::NONE, user->getType1(), true) > 1){
                        hasWeakness = true;
                    }
                }
                if(user->getType2() != PkmnTypes::NONE){
                    if(calcEffectiveness(pokemon->getType1(),PkmnTypes::NONE, user->getType2(), true) > 1){
                        hasWeakness = true;
                    }
                    if(pokemon->getType2() != PkmnTypes::NONE){
                        if(calcEffectiveness(pokemon->getType2(),PkmnTypes::NONE, user->getType2(), true) > 1){
                            hasWeakness = true;
                        }
                    }
                }
                //textBox(pokemon->getName()+" has no weakness\n",true);
                options.push_back(pokemon);
            }
        }
    }

    if(options.size() == 0){
        return nullptr;
    }
    // choose randomly between options

    int election = rand()%(options.size());
    Pokemon* pkmn = options[election];


    return pkmn;
}

// checks options and returns one of them
Pokemon* IAChange(Pokemon *user, Pokemon *enemy, vector<Pokemon*> team){
    vector<Move*> moves = enemy->getMoveset();
    bool supereffective = false;

    Pokemon* change = nullptr;
    for(const auto &m : moves){
        if(calcEffectiveness(user->getType1(), user->getType2(), m->getMoveType(), true) > 1){
            supereffective = true;
        }
    }
    
    if(!supereffective){
        change = IAChangeOption(team, user, enemy);
    }

    return change;
}

// Use most powerful move or maybe a status one
Move* enemyAttack(Pokemon *user, Pokemon *enemy){

    //Get moveset of the enemy and get a random move between them
    vector<Move*> moves = enemy->getMoveset();
    vector<int> values;
    int greater_dmg;
    int status = 404;
    Pokemon* change = nullptr;

    // if enemy is healthy find status move
    if(user->getStatus() == PkmnStatus::HEALTHY){
        int temp = 0;
        for(const auto &m : moves){
            if(m->getCategory() == Category::STATUS){
                vector<string> campos = getSideEffectsFromMove(m);
                if(campos.at(0) == "status"){
                    status = temp;
                }
            }
            temp++;
        }
    }

    // add move dmg to values vector to find the strongest one
    for(const auto &m : moves){
        //test damage from enemy to user
        values.push_back(dmgFormula(enemy, user, m, true));
    }
    // find the index of the strongest move
    int max = *max_element(values.begin(), values.end());
    auto it = find(values.begin(), values.end(), max);
    if(it != values.end()){ greater_dmg = it - values.begin();}

    // if enemy is healthy choose random between max dmg or status condition
    if(status != 404){
        int decision = rand()%2+1;
        if(decision == 1){
            return moves[greater_dmg];
        } 
        else {
            return moves[status];
        }
    } 
    else {
        return moves[greater_dmg];
    }

    return moves[0];
}

// checks if want to change to return 1 for change or 2 to attack
int IAdecision(Pokemon *user, Pokemon *enemy, vector<Pokemon*> team){
    Pokemon* change_pkmn = IAChange(user, enemy, team);
    bool wantToChange = false;
    //if there is a pokemon to change
    if(change_pkmn != nullptr){
        wantToChange = true;
    }

    //return 2 to attack    
    if(wantToChange){
       // textBox("Enemy wants to change\n",true);
        if(rand()%100+1 < 30){
            //textBox("Enemy is going to change\n",true);
            return 1;
        } else {
            return 2;
        }
    } else {
        return 2;
    }
}

// Damage formula calculator
int calculateDamage(Pokemon *userPkmn, Pokemon *enemyPokemon, Move* move){
    move->lessPP();
    // if check status returns False, program stops and returns status error
    if(!checkStatus(userPkmn))
        return -1;

    // checks if move has any status effect, in case it has, it apllies it
    if(!movementEffect(userPkmn, enemyPokemon, move)){
        return 0;
    }

    // if hits, calc dmg and return it
    if(rand()%100+1 <= move->getAccurracy()){
        return dmgFormula(userPkmn, enemyPokemon, move, false);
    } else {
        textBox(userPkmn->getName()+"'s Attack missed!\n",true);
        return 0;
    }
}

/* displayData() : Displays pokemon data
____________________________________________________________

        [1] Chimchar     lvl.7
        [2] Budew        lvl.4 
        [3] < Go Back >
____________________________________________________________*/
void displayData(Pokemon* user, Pokemon* enemy){
    int decision;
    cout<<"\n ____________________________________________________________ \n\n";
    cout<<"\t\t[1] " << user->getName() << "\tlvl." << user->getLevel() << endl;
    cout<<"\t\t[2] " << enemy->getName() << "\tlvl." << enemy->getLevel() << endl;
    cout<<"\t\t[3] < Go Back >" << endl;
    cout<<" ____________________________________________________________ "<<endl;
    do{
        cout << "\nWho do you want to look? : "; 
        cin >> decision;
    } while(decision < 1 || decision > 3);

    switch(decision){
        case 1:
            textBox(user->printData(),true); 
        break;

        case 2:
            textBox(enemy->printData(),true);
        break;
    }
}

// Checks if pokemon are dead
bool checkHps(Pokemon* pkmn1, Pokemon* pkmn2){
    if(pkmn1->getHP() <= 0){
        textBox(pkmn1->getName()+" fainted\n",true);
        return false;
    }

    clearScreen();
    
    if(pkmn2->getHP() <= 0){
        textBox(pkmn2->getName()+" fainted\n",true);
        return false;
    }
    return true;
}

//lose(defender, attacker)
bool lose(Trainer* user, Trainer* enemy, bool is_player){
    Pokemon* enemyPkmn = enemy->getLeadPkmn();
    Pokemon* userPkmn = user->getLeadPkmn();
    //Enemy lost
    if(enemy->getPartySize() <= 1){
        if(is_player){
            //Defeated Trainer
            textBox("Player defeated "+enemy->classtring(enemy->getTC())+" "+enemy->getName()+"!\n ",true);
            //Got x money for winning
            textBox(user->classtring(user->getTC())+" "+user->getName()+" got $864 for winning!\n",true);
        }else{
            textBox("You lost\n",true);
        }
        return true;
    } else {
    //Time to send another pokemon
        return false;
    }
}

// If a pokemon dies it sends the next one in the party
Pokemon* sendNextPokemon(Trainer *trainer){
    trainer->updateTeam();
    Pokemon *pkmn = trainer->getLeadPkmn();
    clearScreen();
    textBox(trainer->classtring(trainer->getTC())+" "+trainer->getName()+" will sent out "+pkmn->getName()+"!\n",true);
    return pkmn;
}

/* changePokemon(trainer, hp) : Displays movements and its stats.
 ____________________________________________________________

        [1] Chimchar    lvl.7   Hp: 25/25
        [2] Starly      lvl.4   Hp: 18/18
        [3] < Cancel >
____________________________________________________________*/

void changePkmnUI(Trainer *trainer){
    int temp = 1;
    vector<Pokemon*> party = trainer->getParty();
    cout<<"\n ____________________________________________________________ \n\n";
    for(auto p: party){
        cout<< "\t[" << temp << "] " << p->getName() << "\tlvl." << p->getLevel() << "\tHp: " << p->getHP() << "/" << p->getMaxHP() << "\n";
        temp++;
    }
    cout << "\t["<<temp<<"] < Go Back >\n";
    cout<<"____________________________________________________________ "<<endl;
}

Pokemon* changePokemon(Trainer *&trainer){
    int chosenPokemon = 0;
    int variablerandom;
    vector<Pokemon*> party = trainer->getParty();

    Pokemon* change_pkmn;
    Pokemon *temp_pkmn;

    do{
        cout << "\nChoose a pokemon. ";
        cin >> chosenPokemon;
        if(chosenPokemon == party.size()+1){
            return nullptr;
        }
        change_pkmn = party.at(chosenPokemon-1);
        temp_pkmn = trainer->getLeadPkmn();

        party[0] = change_pkmn;
        
        party[chosenPokemon-1] = temp_pkmn;

        cout<<"____________________________________________________________ "<<endl;

        if(change_pkmn->getName() == trainer->getLeadPkmn()->getName()){
            cout << "This pokemon is already in battle\n" << endl;
            chosenPokemon = 10000;
        }
    } while(chosenPokemon < 1 || chosenPokemon > party.size()+1);

    trainer->setParty(party);
    return change_pkmn;
}

Pokemon* IAchangePokemon(Trainer *&trainer, Pokemon* change_pkmn){
    vector<Pokemon*> party = trainer->getParty();
    Pokemon *temp_pkmn;
    temp_pkmn = trainer->getLeadPkmn();

    int index = trainer->getPartyPokemonIndex(change_pkmn);

    party[0] = change_pkmn;
    party[index] = temp_pkmn;

    trainer->setParty(party);

    textBox(trainer->classtring(trainer->getTC())+" "+trainer->getName()+" withdrew "+temp_pkmn->getName()+"!\n",true);
    textBox(trainer->classtring(trainer->getTC())+" "+trainer->getName()+" sent out "+change_pkmn->getName()+"!\n",true);
    return change_pkmn;
}

// Main Function
void Battle(Trainer*user, Trainer*enemy){
    string partyballs(enemy->getPartySize(),'O');
    string emptyballs(6-enemy->getPartySize(),'X');
    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" would like to battle! \n\t"+partyballs+emptyballs+"\n", true);

    bool inBattle = true;
    Pokemon *userPkmn = user->getLeadPkmn();
    Pokemon *enemyPkmn = enemy->getLeadPkmn();
    Move *userMove;
    Move *enemyMove;
    int menuDecision = 0;
    int speedTurn;
    int calc_dmg = 0;

    int ia = 0;

    Pokemon* entryPkmn;

    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" sent out "+enemyPkmn->getName()+"!\n ",true);
    clearScreen();

/*
    cout << userPkmn->printData() << endl;
    cout << enemyPkmn->printData() << endl;
    cin >> calc_dmg;
*/

    // ================ END VARS ======================
    while(inBattle == true){
        userPkmn->updateStats();
        enemyPkmn->updateStats();

        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn);
        
        // User Action + Choose attack
        menuDecision = actionsMenu(userPkmn);

        ia = IAdecision(userPkmn, enemyPkmn, enemy->getParty());

        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn);

        switch(menuDecision){
            case 1:
                userMove = movesMenu(userPkmn);
                if(userMove == nullptr)
                    break;
                speedTurn = speedCheck(userPkmn,enemyPkmn);
                clearScreen();
                switch (ia)
                {
                    case 1:
                        enemyPkmn = IAchangePokemon(enemy, IAChange(userPkmn, enemyPkmn, enemy->getParty())); // change to the new pkmn
                        switch(speedTurn)
                        {
                            case 1: // ========================================= starts USER =========================================
                                textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                                calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                                // -1 = abort, else calculate damage
                                if(calc_dmg != -1){
                                    enemyPkmn->setCurrentHP(enemyPkmn->getHP() - calc_dmg);
                                    //Check if died
                                    if(checkHps(userPkmn, enemyPkmn) == false){
                                        if(lose(user,enemy,true) == true){
                                            return;
                                        } else {
                                            enemyPkmn = sendNextPokemon(enemy);
                                            break;
                                        }
                                    }
                                }
                                break;
                            case 2: //  ========================================= ENEMY goes first =========================================
                                //=-=-=-=-=-=-=-=-= User Turn =-=-=-=-=-=-=-=-=
                                textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                                calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                                // -1 = abort, else calculate damage
                                if(calc_dmg != -1){
                                    enemyPkmn->setCurrentHP(enemyPkmn->getHP() - calc_dmg);
                                    //Check if died
                                    if(checkHps(userPkmn, enemyPkmn) == false){
                                        if(lose(user,enemy,true) == true){
                                            return;
                                        } else {
                                            enemyPkmn = sendNextPokemon(enemy);
                                            break;
                                        }
                                    }
                                }
                            
                            break;
                        }
                        break;
                    case 2:
                        // atk
                        enemyMove = enemyAttack(userPkmn, enemyPkmn);
                        switch(speedTurn){
                        case 1: // ========================================= starts USER =========================================
                            textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                            calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                            // -1 = abort, else calculate damage
                            if(calc_dmg != -1){
                                enemyPkmn->setCurrentHP(enemyPkmn->getHP() - calc_dmg);
                                //Check if died
                                if(checkHps(userPkmn, enemyPkmn) == false){
                                    if(lose(user,enemy,true) == true){
                                        return;
                                    } else {
                                        enemyPkmn = sendNextPokemon(enemy);
                                        break;
                                    }
                                }
                            }
                            
                            // =-=-=-=-=-=-= Foe Turn =-=-=-=-=-=-=-=-=
                            textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",true);
                            calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                            // -1 = abort, else calculate damage
                            if(calc_dmg != -1){
                                userPkmn->setCurrentHP(userPkmn->getHP() - calc_dmg);
                                if(checkHps(userPkmn, enemyPkmn) == false){
                                    if(lose(enemy,user,false) == true){
                                        return;
                                    } else {
                                        userPkmn = sendNextPokemon(user);
                                        break;
                                    }
                                }
                            }
                            
                            break;
                        case 2: //  ========================================= ENEMY goes first =========================================
                            textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",true);
                            calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                            // -1 = abort, else calculate damage
                            if(calc_dmg != -1){
                                userPkmn->setCurrentHP(userPkmn->getHP() - calc_dmg);
                                if(checkHps(userPkmn, enemyPkmn) == false){
                                    if(lose(enemy,user,false) == true){
                                        return;
                                    } else {
                                        userPkmn = sendNextPokemon(user);
                                        break;
                                    }
                                }
                            }
                            
                            //=-=-=-=-=-=-=-=-= User Turn =-=-=-=-=-=-=-=-=
                            textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                            calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                            // -1 = abort, else calculate damage
                            if(calc_dmg != -1){
                                enemyPkmn->setCurrentHP(enemyPkmn->getHP() - calc_dmg);
                                //Check if died
                                if(checkHps(userPkmn, enemyPkmn) == false){
                                    if(lose(user,enemy,true) == true){
                                        return;
                                    } else {
                                        enemyPkmn = sendNextPokemon(enemy);
                                        break;
                                    }
                                }
                            }
                        break;
                    } 
                        break;
                }
            break;
            case 2:
                switch(ia)
                {
                    case 1:
                        enemyPkmn = IAchangePokemon(enemy, IAChange(userPkmn, enemyPkmn, enemy->getParty())); // change to the new pkmn
                        changePkmnUI(user);
                        entryPkmn = changePokemon(user);

                        if(entryPkmn  == nullptr)
                            break;

                        userPkmn = entryPkmn;

                        break;
                    case 2:
                        enemyMove = enemyAttack(userPkmn, enemyPkmn);
                        changePkmnUI(user);
                        entryPkmn = changePokemon(user);

                        if(entryPkmn  == nullptr)
                            break;

                        userPkmn = entryPkmn;
                        textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",true);
                        calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);
                        if(calc_dmg != -1){
                            userPkmn->setCurrentHP(userPkmn->getHP() - calc_dmg);
                            if(checkHps(userPkmn, enemyPkmn) == false){
                                if(lose(enemy,user,false) == true){
                                    return;
                                } else {
                                    userPkmn = sendNextPokemon(user);
                                    break;
                                }
                            }
                        }  
                        break;
                }
            break;
            case 3:
                displayData(userPkmn, enemyPkmn);
            break;
        }
    }
}

int main(){
    srand(time(NULL));
    //Lucas
    Trainer* player = start();

    //Lucas->mostrarEquipo();
    //Kaitlin->mostrarEquipo();

    Battle(player, Cynthia);
    return 0;
}