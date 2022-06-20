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
        textBox("It doesn't affect.\n",true);
    } else if(x < 1){
        textBox("Its not very effective!\n",true);
    } else if(x > 1){
        textBox("Its super effective!\n",true);
    }
}

bool STAB(Pokemon *user, Move* move){
    if(move->getMoveType() == user->getType1() || move->getMoveType() == user->getType2()){
        return true;
    }
    return false;
}

int calcEffectiveness(Pokemon *enemy, Move *move){
    //Pkmn(pokemones.at("Spiritomb"),61,{moves.at("Dark Pulse"),moves.at("Shadow Ball"),moves.at("Psychic"),moves.at("Embargo")});
    PkmnTypes moveType = move->getMoveType();
    PkmnTypes pkmnType1 = enemy->getType1();
    PkmnTypes pkmnType2 = enemy->getType2();

    //textBox("Move type: " +enemy->typeString(moveType)+"\nPkmn types: "+enemy->typeString(pkmnType1)+"|"+enemy->typeString(pkmnType2)+"\n\n",true);\
    
    map<PkmnTypes, double> effectiveMap = Effectiveness.at(moveType);
    double effectiveness1 = effectiveMap.at(pkmnType1);

    if(pkmnType2 != NONE){
        double effectiveness2 = effectiveMap.at(pkmnType2);
        //textBox("Effectiveness: "+to_string(effectiveness1*effectiveness2)+"\n",true);
        effectivenessMessage(effectiveness1*effectiveness2);
        return effectiveness1 * effectiveness2;
    } else {
        //textBox("Effectiveness: "+to_string(effectiveness1)+"\n",true);
        effectivenessMessage(effectiveness1);
        return effectiveness1;
    }
}

// Damage formula calculator
int calculateDamage(Pokemon *userPkmn, Pokemon *enemyPokemon, Move* move){
    move->lessPP();
    //if check status returns False, program stops and returns status error
    if(!checkStatus(userPkmn))
        return -1;

    //checks if move has any status effect, in case it has, it apllies it
    if(!movementEffect(userPkmn, enemyPokemon, move)){
        return 0;
    }
    
    //Pokemon Dmg Formula
    if(move->getPower() != 0){

        int atk_stat = userPkmn->getATK();
        if(userPkmn->getStatusString() == "BRN")
            atk_stat /= 2;

        int effectiveness = calcEffectiveness(enemyPokemon, move);

        double stab = 1;
        if(STAB(userPkmn, move))
            stab = 1.5;

        if(rand()%100+1 <= move->getAccurracy()){
            return trunc(trunc(trunc(trunc(trunc(trunc(2*userPkmn->getLevel())/5)+2) * move->getPower() * userPkmn->getATK()/enemyPokemon->getDEF())/50)+2)*effectiveness * stab;
        } else {
            textBox(userPkmn->getName()+"'s Attack missed!\n",true);
            return 0;
        } 
    } else {
        return 0;
    }
}

// Enemy chooses randomly between [1-4] <= movement vector size 
Move* enemyAttack(Trainer *enemy, Pokemon *enemyPokemon){
    //Get moveset of the enemy and get a random move between them
    vector<Move*> moves = enemyPokemon->getMoveset();
    int randomNum = rand() % moves.size();
    return moves.at(randomNum);
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
Pokemon* changePokemon(Trainer *&trainer){
    int temp = 1;
    int chosenPokemon = 0;
    int variablerandom;
    vector<Pokemon*> party = trainer->getParty();

    cout<<"\n ____________________________________________________________ \n\n";
    for(auto p: party){
        cout<< "\t[" << temp << "] " << p->getName() << "\tlvl." << p->getLevel() << "\tHp: " << p->getHP() << "/" << p->getMaxHP() << "\n";
        temp++;
    }
    cout << "\t["<<temp<<"] < Go Back >\n";
    cout<<"____________________________________________________________ "<<endl;

    Pokemon* change_pkmn;
    Pokemon *temp_pkmn;

    do{
        cout << "\nChoose a pokemon. ";
        cin >> chosenPokemon;
        if(chosenPokemon == temp){
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

    } while(chosenPokemon < 1 || chosenPokemon > temp);

    trainer->setParty(party);
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

        // Display menu
        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn);
        
        // User Action
        //Choose attack
        menuDecision = actionsMenu(userPkmn);
        clearScreen();

        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn);

        switch(menuDecision){
            case 1:
                userMove = movesMenu(userPkmn);
                if(userMove == nullptr)
                    break;
                enemyMove = enemyAttack(enemy, enemyPkmn);
                speedTurn = speedCheck(userPkmn,enemyPkmn);
                clearScreen();
                
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
            case 2:
                //textBox("Who do you want to change?\n", true);
                
                entryPkmn = changePokemon(user);
                if(entryPkmn  == nullptr){
                    break;
                }
                userPkmn = entryPkmn;
                enemyMove = enemyAttack(enemy, enemyPkmn);
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
            case 3:
                displayData(userPkmn, enemyPkmn);
            break;
        }
    }
}

int main(){
    srand(time(NULL));
    //Lucas
    
    updateTrainers();

    //Lucas->mostrarEquipo();
    //Kaitlin->mostrarEquipo();

    Battle(player, Cynthia);
    return 0;
}