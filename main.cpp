#include "trainerDB.cpp"
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void clearScreen(){
    system("cls");
}

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

 /*                      _____________________
                        |
                        | Budew Lv4
                        |  HP:16/16
                        |______________________


 _____________________
|
| Chimchar      Lv7
| PAR HP:21/22
|______________________*/

void ShowPokemonMenuHUD(Pokemon userPk, Pokemon enemyPk){
    clearScreen();
    string userStatus = userPk.getStatusString();
    string enemyStatus = enemyPk.getStatusString();

    //cout << "\t\t" << foe->classtring(foe->getTC())<<" "<<foe->getName();
    cout<<"\n\t\t\t _____________________\n\t\t\t|\n";
    cout << "\t\t\t| " << enemyPk.getName() << "\tLv." << enemyPk.getLevel() << endl;
    cout << "\t\t\t| " << enemyStatus << " HP:" << enemyPk.getHP() << "/" << enemyPk.getMaxHP() << endl;
    cout << "\t\t\t|______________________" << endl;

    cout << "\n";
    //cout << "===== "<<user->classtring(user->getTC())<<" "<<user->getName()<<" ===== \n";    
    cout<<"\n _____________________\n|\n";
    cout << "| " << userPk.getName() << "\tLv" << userPk.getLevel() << endl;
    cout << "| " << userStatus << " HP:" << userPk.getHP() << "/" << userPk.getMaxHP() << endl;  
    cout << "|______________________" << endl;
}

/* movesMenu(userPokemon) : Displays movements and its stats.
____________________________________________________________

        [1] Scratch     NORMAL  40      35/35
        [2] Leer        NORMAL  0       30/30
____________________________________________________________*/


Move* movesMenu(Pokemon userPokemon){
    int temp = 1;
    int chosenMove = 0;
    vector<Move*> *moves = userPokemon.getMoveset();

    cout<<"\n ____________________________________________________________ \n\n";
    for(auto mv: *moves){
        cout<< "\t[" << temp << "] ";
        mv->printMove();
        temp++;
    }
    cout<<" ____________________________________________________________ "<<endl;
    do{
        cout << "\nWhat move do you want to do?: "; 
        cin >> chosenMove;
        Move* move = moves->at(chosenMove-1);
        if(move->getCurrentPP() == 0){
            cout << "There's no PP left for this move!\n" << endl;
            chosenMove = 10000;
        }
            
    } while(chosenMove < 1 || chosenMove > temp-1);

    return moves->at(chosenMove-1);
}

/* actionsMenu(userPokemon) : Displays which actions the player can do.
____________________________________________________________

    What will Chimchar do?
    [1] Fight
    [2] Change    
    [3] Stats
____________________________________________________________*/

int actionsMenu(Pokemon userPokemon){
    int decision = 0;
    vector<Move*> *moves = userPokemon.getMoveset();

    cout<<"\n ____________________________________________________________ \n\n";
    cout<<"\tWhat will "<<userPokemon.getName()<<" do?\n\t[1] Fight \n\t"<<"[2] Change \n\t[3] Stats\n";
    cout<<" ____________________________________________________________ "<<endl;

    do{ cout<<"Opcion: ";cin>>decision; } while(decision < 1 || decision > 3);

    return decision;
}

// 1 => User is faster
// 2 => Enemy is faster
// Speedtie, chooses randomly between 1 and 2

int speedCheck(Pokemon uPkmn, Pokemon ePkmn){
    if (uPkmn.getSPE() > ePkmn.getSPE()){
        return 1; //user faster
    } else if (uPkmn.getSPE() < ePkmn.getSPE()) {
        return 2; //enemy faster
    } else {
        int random = rand() % 2+1;
        return random; //speedtie random between 1 and 2
    }
}
// 80 % True (sleep) || 20 % False (wake up)
bool statusCFD(Pokemon pkmn){
    textBox(pkmn.getName()+"is confused!\n",true);
    if(rand()%100+1 < 80){
        if(rand()%100+1 < 50){
            textBox("it hurt itself in its confusion!\n", true);
            return true;
        }
        return true;
    }
    textBox(pkmn.getName()+" snapped out of its confusion!\n", true);
    pkmn.setStatus(HEALTHY);
    return false;
}

// 80 % True (sleep) || 20 % False (wake up)
bool statusSLP(Pokemon pkmn){
    if(rand()%100+1 < 80){
        textBox(pkmn.getName()+" is fast asleep!\n", true);
        return true;
    }
    textBox(pkmn.getName()+" woke up!\n", true);
    pkmn.setStatus(HEALTHY);
    return false;
}

// 80 % True (frozen) || 20 % False (thawed out)
bool statusFRZ(Pokemon pkmn){
    if(rand()%100+1 < 80){
        textBox(pkmn.getName()+" is frozen solid!\n", true);
        return true;
    }
    textBox(pkmn.getName()+" thawed out!\n", true);
    pkmn.setStatus(HEALTHY);
    return false;
}

// 50% True (is paralyzed) || 50% False (attacks)
bool statusPAR(Pokemon pkmn){
    if(rand()%100+1 < 50){
        textBox(pkmn.getName()+" is paralyzed!\tIt can't move!\n", true);
        return true;
    }
    return false;
}

// 50% True (is in love) || 50% False (attacks)
bool statusATT(Pokemon pkmn){
    if(rand()%100+1 < 50){
        textBox(pkmn.getName()+" is in love with the Foe!\n", true);
        return true;
    }
    return false;
}

// True = Continue, False = STOP
bool checkStatus(Pokemon userPkmn){
    PkmnStatus status = userPkmn.getStatus();
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

//turns move description into a vector of data
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
/*
// Move("Stun Spore",30,STATUS,0,75,"s|100|2",GRASS);
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
void movementStatusEffect(Pokemon user, Pokemon enemy, Move* move){
    vector<string> campos = getSideEffectsFromMove(move);
    clearScreen();
    if(campos.at(0) == "s"){
        if(rand()%100+1 < stoi(campos.at(1))){
            switch(stoi(campos.at(2))){
                case 0:
                    if(enemy.getStatusString() == "SLP"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(SLEEP);

                        textBox(enemy.getName()+" is now asleep! \n", true);
                    }

                break;
                case 1:
                    if(enemy.getStatusString() == "FRZ"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(FROZEN);

                        textBox(enemy.getName()+" is now frozen! \n", true);
                    }

                break;
                case 2:
                    if(enemy.getStatusString() == "PAR"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(PARALYZED);
                    
                        textBox(enemy.getName()+" is now paralyzed! It may be unable to move!\n", true);
                    }

                break;
                case 3:
                    if(enemy.getStatusString() == "BRN"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(BURNED);

                        textBox(enemy.getName()+" is now burned!\n", true);
                    }

                break;
                case 4:
                    if(enemy.getStatusString() == "PSN"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(POISONED);

                        textBox(enemy.getName()+" is now poisoned!\n", true);
                    }


                break;
                case 5:
                    if(enemy.getStatusString() == "CFD"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(CONFUSED);

                        textBox(enemy.getName()+" is now confused!\n", true);
                    }


                break;
                case 6:
                    if(enemy.getStatusString() == "PAR"){
                        textBox(enemy.getName()+" is already "+enemy.getStatusString()+"!\n",true);
                    } else {
                        enemy.setStatus(ATTRACTED);

                        textBox(enemy.getName()+" fell in love with the Foe "+user.getName()+"!\n", true);
                    }


                break;

            }
        }
    }

}

// Damage formula calculator
int calculateDamage(Pokemon userPkmn, Pokemon enemyPokemon, Move* move){
    move->lessPP();
    //if check status returns False, program stops and returns status error
    if(!checkStatus(userPkmn))
        return -1;

    //checks if move has any status effect, in case it has, it apllies it
    movementStatusEffect(userPkmn, enemyPokemon, move);
    
    //Pokemon Dmg Formula
    if(move->getPower() != 0){

        int atk_stat = userPkmn.getATK();
        if(userPkmn.getStatusString() == "BRN")
            atk_stat /= 2;

        if(rand()%100+1 <= move->getAccurracy()){
            return trunc(trunc(trunc(trunc(trunc(2*userPkmn.getLevel())/5)+2) * move->getPower() * userPkmn.getATK()/enemyPokemon.getDEF())/50)+2;
        } else {
            return 0;
        } 
    } else {
        return 0;
    }
}

// Enemy chooses randomly between [1-4] <= movement vector size 
Move* enemyAttack(Pokemon enemyPokemon){
    //Get moveset of the enemy and get a random move between them
    vector<Move*> *moves = enemyPokemon.getMoveset();
    int randomNum = rand() % moves->size();
    return moves->at(randomNum);
}

/* displayData() : Displays pokemon data
____________________________________________________________

        [1] Chimchar     lvl.7
        [2] Budew        lvl.4 
        [3] < Go Back >
____________________________________________________________*/

void displayData(Pokemon user, Pokemon enemy){
    int decision;
    cout<<"\n ____________________________________________________________ \n\n";
    cout<<"\t\t[1] " << user.getName() << "\tlvl." << user.getLevel() << endl;
    cout<<"\t\t[2] " << enemy.getName() << "\tlvl." << enemy.getLevel() << endl;
    cout<<"\t\t[3] < Go Back >" << endl;
    cout<<" ____________________________________________________________ "<<endl;
    do{
        cout << "\nWho do you want to look? : "; 
        cin >> decision;
    } while(decision < 1 || decision > 3);

    switch(decision){
        case 1:
            textBox(user.printData(),true); 
        break;

        case 2:
            textBox(enemy.printData(),true);
        break;
    }
}

bool checkHps(Pokemon pkmn1, Pokemon pkmn2){
    if(pkmn1.getHP() <= 0){
        textBox(pkmn1.getName()+" fainted\n",true);
        return false;
    }

    clearScreen();
    
    if(pkmn2.getHP() <= 0){
        textBox(pkmn2.getName()+" fainted\n",true);
        return false;
    }
    return true;
}

//lose(defender, attacker)
bool lose(Trainer user, Trainer enemy, bool is_player){
    Pokemon enemyPkmn = enemy.getLeadPkmn();
    Pokemon userPkmn = user.getLeadPkmn();
    //Enemy lost
    if(enemy.getPartySize() <= 1){
        if(is_player){
            //Defeated Trainer
            textBox("Player defeated "+enemy.classtring(enemy.getTC())+" "+enemy.getName()+"!\n ",true);
            //Got x money for winning
            textBox(user.classtring(user.getTC())+" "+user.getName()+" got $864 for winning!\n",true);
        }else{
            textBox("You lost\n",true);
        }
        return true;
    } else {
    //Time to send another pokemon
        if(is_player){
            //Pokemon gained x exp points
            textBox(userPkmn.getName()+" gained "+to_string((int)(pow(3,enemyPkmn.getLevel())))+" exp. points!\n",true);  
        }
        return false;
    }
}

Pokemon sendNextPokemon(Trainer trainer){
    trainer.updateTeam();
    Pokemon pkmn = trainer.getLeadPkmn();
    clearScreen();
    textBox(trainer.classtring(trainer.getTC())+" "+trainer.getName()+" will sent out "+pkmn.getName()+"!\n",true);
    return pkmn;
}

/* changePokemon(trainer, hp) : Displays movements and its stats.
 ____________________________________________________________

        [1] Chimchar    lvl.7   Hp: 25/25
        [2] Starly      lvl.4   Hp: 18/18
____________________________________________________________*/

Pokemon changePokemon(Trainer &trainer){
    int temp = 1;
    int chosenPokemon = 0;
    int variablerandom;
    vector<Pokemon> party = trainer.getParty();

    cout<<"\n ____________________________________________________________ \n\n";
    for(auto p: party){
        cout<< "\t[" << temp << "] " << p.getName() << "\tlvl." << p.getLevel() << "\tHp: " << p.getHP() << "/" << p.getHP() << "\n";
        temp++;
    }
    cout<<"____________________________________________________________ "<<endl;

    Pokemon change_pkmn;
    Pokemon temp_pkmn;

    do{
        cout << "\nChoose a pokemon. ";
        cin >> chosenPokemon;
        change_pkmn = party.at(chosenPokemon-1);
        temp_pkmn = trainer.getLeadPkmn();

        party[0] = change_pkmn;
        
        party[chosenPokemon-1] = temp_pkmn;

        cout<<"____________________________________________________________ "<<endl;

        if(change_pkmn.getName() == trainer.getLeadPkmn().getName()){
            cout << "This pokemon is already in battle\n" << endl;
            chosenPokemon = 10000;
        }

    } while(chosenPokemon < 1 || chosenPokemon > temp-1);

    trainer.setParty(party);
    return change_pkmn;
}

void Battle(Trainer user, Trainer enemy){
    string partyballs(enemy.getPartySize(),'O');
    string emptyballs(6-enemy.getPartySize(),'X');
    textBox(enemy.classtring(enemy.getTC())+" "+enemy.getName()+" would like to battle! \n\t"+partyballs+emptyballs+"\n", true);

    bool inBattle = true;
    Pokemon userPkmn = user.getLeadPkmn();
    Pokemon enemyPkmn = enemy.getLeadPkmn();

    Move *userMove;
    Move *enemyMove;
    int menuDecision = 0;
    int speedTurn;
    int calc_dmg = 0;

    textBox(enemy.classtring(enemy.getTC())+" "+enemy.getName()+" sent out "+enemyPkmn.getName()+"!\n ",true);
    clearScreen();

    // ================ END VARS ======================
    while(inBattle == true){
        userPkmn.updateStats();
        enemyPkmn.updateStats();

        // Display menu
        ShowPokemonMenuHUD(userPkmn, enemyPkmn);
        
        // User Action
        //Choose attack
        menuDecision = actionsMenu(userPkmn);
        clearScreen();

        ShowPokemonMenuHUD(userPkmn, enemyPkmn);

        switch(menuDecision){
            case 1:
                userMove = movesMenu(userPkmn);
                enemyMove = enemyAttack(enemyPkmn);
                speedTurn = speedCheck(userPkmn,enemyPkmn);
                clearScreen();
                
                switch(speedTurn){
                    case 1: // ========================================= starts USER =========================================
                        textBox((userPkmn.getName()+" used "+userMove->getName()+"\n"),true);
                        calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                        // -1 = abort, else calculate damage
                        if(calc_dmg != -1){
                            enemyPkmn.setCurrentHP(enemyPkmn.getHP() - calc_dmg);
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
                        textBox(enemyPkmn.getName()+" used "+enemyMove->getName()+"\n",true);
                        calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                        // -1 = abort, else calculate damage
                        if(calc_dmg != -1){
                            userPkmn.setCurrentHP(userPkmn.getHP() - calc_dmg);
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
                        textBox(enemyPkmn.getName()+" used "+enemyMove->getName()+"\n",true);
                        calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                        // -1 = abort, else calculate damage
                        if(calc_dmg != -1){
                            userPkmn.setCurrentHP(userPkmn.getHP() - calc_dmg);
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
                        textBox((userPkmn.getName()+" used "+userMove->getName()+"\n"),true);
                        calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                        // -1 = abort, else calculate damage
                        if(calc_dmg != -1){
                            enemyPkmn.setCurrentHP(enemyPkmn.getHP() - calc_dmg);
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
                userPkmn = changePokemon(user);
                enemyMove = enemyAttack(enemyPkmn);
                textBox(enemyPkmn.getName()+" used "+enemyMove->getName()+"\n",true);
                calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                // -1 = abort, else calculate damage
                if(calc_dmg != -1){
                    userPkmn.setCurrentHP(userPkmn.getHP() - calc_dmg);
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

    Lucas.mostrarEquipo();
    Kaitlin.mostrarEquipo();

    int x;
    cin >> x;
    Battle(Lucas,Kaitlin);

    return 0;
}