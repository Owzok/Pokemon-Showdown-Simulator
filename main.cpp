#include "trainerDB.cpp"
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void clearScreen(){
    system("cls");
}

/*
____________________________________________________________

        Chimchar used Scratch and dealt 8 dmg.
____________________________________________________________
*/

void textBox(string text, bool clear){
    if(clear)
        clearScreen();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n ____________________________________________________________ \n\n";
    cout <<"\t"<<text;
    cout<<" ____________________________________________________________ "<<endl; getch();
}

/*
____________________________________________________________

        [1] Scratch     NORMAL  40      35/35
        [2] Leer        NORMAL  0       30/30
____________________________________________________________
*/

Move* movesMenu(Pokemon *userPokemon){
    int temp = 1;
    int chosenMove = 0;
    vector<Move*> *moves = userPokemon->getMoveset();

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
    } while(chosenMove < 1 || chosenMove > temp-1);

    return moves->at(chosenMove-1);
}

/*
____________________________________________________________

    What will Chimchar do?
    [1] Fight
    [2] Change    
____________________________________________________________
*/

int actionsMenu(Pokemon* userPokemon){
    int decision = 0;
    vector<Move*> *moves = userPokemon->getMoveset();

    cout<<"\n ____________________________________________________________ \n\n";
    cout<<"\tWhat will "<<userPokemon->getName()<<" do?\n\t[1] Fight \n\t"<<"[2] Change \n";
    cout<<" ____________________________________________________________ "<<endl;

    do{ cout<<"Opcion: ";cin>>decision; } while(decision < 1 || decision > 2);

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

int calculateDamage(Pokemon *userPkmn, Pokemon *enemyPokemon, Move* move){

    if(userPkmn->getStatus() == "PAR"){
        if(rand()%100+1 < 50){
            textBox(userPkmn->getName()+" is paralyzed!\tIt can't move!\n", true);
            return -1;
        }
    }

    string txt = move->getSideEffect();
    vector<string> campos = vector<string>();
    string delimeter = "|";
    size_t pos = 0;
    string token;
    while((pos = txt.find(delimeter)) != string::npos){
        token = txt.substr(0, pos);
        campos.push_back(token);
        txt.erase(0, pos+delimeter.length());
    }
    token = txt.substr(0, pos);
    campos.push_back(token);
    clearScreen();
    if (campos.at(0) == "s"){
        if(rand()%100+1 < stoi(campos.at(1))){
            switch(stoi(campos.at(2))){
                case 0:
                    enemyPokemon->setStatus(SLEEP);
                break;
                case 1:
                    enemyPokemon->setStatus(FROZEN);
                break;
                case 2:
                    if(enemyPokemon->getStatus() == "PAR"){
                        textBox(enemyPokemon->getName()+" is already "+enemyPokemon->getStatus()+"!\n",true);
                        return -1;
                    }
                    enemyPokemon->setStatus(PARALYZED);
                    textBox(enemyPokemon->getName()+" is paralyzed! It may be unable to move!\n", true);
                break;
                case 3:
                    enemyPokemon->setStatus(BURNED);
                break;
                case 4:
                    enemyPokemon->setStatus(POISONED);
                break;
                case 5:
                    enemyPokemon->setStatus(CONFUSED);
                break;
            }
        } else {
            textBox(userPkmn->getName()+" missed!\n",true);
        }
    }
    
    //Pokemon Dmg Formula
    if(move->getPower() != 0){
        if(rand()%100+1 <= move->getAccurracy()){
            return trunc(trunc(trunc(trunc(trunc(2*userPkmn->getLevel())/5)+2) * move->getPower() * userPkmn->getATK()/enemyPokemon->getDEF())/50)+2;
        } else {
            return 0;
        } 
    } else {
        return 0;
    }
}


Move* enemyAttack(Trainer *enemy, Pokemon *enemyPokemon){
    //Get moveset of the enemy and get a random move between them
    vector<Move*> *moves = enemyPokemon->getMoveset();
    int randomNum = rand() % moves->size();
    return moves->at(randomNum);
}

void ShowPokemonMenuHUD(Trainer *user, Trainer *foe, Pokemon *userPk, Pokemon *enemyPk, int userHp, int enemyHP){
    clearScreen();
    string userStatus = userPk->getStatus();
    string enemyStatus = enemyPk->getStatus();

    //cout << "\t\t" << foe->classtring(foe->getTC())<<" "<<foe->getName();
    cout<<"\n\t\t\t _____________________\n\t\t\t|\n";
    cout << "\t\t\t| " << enemyPk->getName() << "\tLv" << enemyPk->getLevel()<<endl;
    cout << "\t\t\t| " << enemyStatus << " HP:"<<enemyHP<<"/"<<enemyPk->getHP()<<endl;
    cout<<"\t\t\t|______________________"<<endl;

    cout << "\n";
    //cout << "===== "<<user->classtring(user->getTC())<<" "<<user->getName()<<" ===== \n";    
    cout<<"\n _____________________\n|\n";
    cout << "| " << userPk->getName() << "\tLv" << userPk->getLevel()<<endl;
    cout<<"| " << userStatus << " HP:"<<userHp<<"/"<<userPk->getHP()<<endl;  
    cout<<"|______________________"<<endl;
}

bool checkHps(int hp1, int hp2, Pokemon* pkmn1, Pokemon* pkmn2){
    if(hp1 <= 0){
        textBox(pkmn1->getName()+" fainted\n",true);
        return false;
    }

    clearScreen();
    
    if(hp2 <= 0){
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
        if(is_player){
            //Pokemon gained x exp points
            textBox(userPkmn->getName()+" gained "+to_string((int)(pow(3,enemyPkmn->getLevel())))+" exp. points!\n",true);  
        }
        return false;
    }
}

Pokemon* sendNextPokemon(Trainer *trainer, int &hp){
    trainer->updateTeam();
    Pokemon *pkmn = trainer->getLeadPkmn();
    hp = pkmn->getHP();
    clearScreen();
    textBox(trainer->classtring(trainer->getTC())+" "+trainer->getName()+" will sent out "+pkmn->getName()+"!\n",true);
    return pkmn;
}

void Battle(Trainer*user, Trainer*enemy){
    string partyballs(enemy->getPartySize(),'O');
    string emptyballs(6-enemy->getPartySize(),'*');
    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" would like to battle! \n\t"+partyballs+emptyballs+"\n", true);

    bool inBattle = true;
    Pokemon *userPkmn = user->getLeadPkmn();
    Pokemon *enemyPkmn = enemy->getLeadPkmn();
    Move *userMove;
    Move *enemyMove;
    int menuDecision = 0;
    int speedTurn;
    int enemyHp = enemyPkmn->getHP();
    int userHp = userPkmn->getHP();
    int calc_dmg = 0;

    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" sent out "+enemyPkmn->getName()+"!\n ",true);
    clearScreen();

    // ================ END VARS ======================
    while(inBattle == true){
        userPkmn->updateStats();
        enemyPkmn->updateStats();

        // Display menu
        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn, userHp, enemyHp);
        
        // User Action
        //Choose attack
        menuDecision = actionsMenu(userPkmn);
        clearScreen();

        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn, userHp, enemyHp);
        
        //Choose random enemy move
        enemyMove = enemyAttack(enemy, enemyPkmn);

        //checkSpeedTurn
        speedTurn = speedCheck(userPkmn,enemyPkmn);

        userMove = movesMenu(userPkmn);
        clearScreen();

        switch (speedTurn){
        case 1:     // ========================================= starts USER =========================================
            switch(menuDecision){
                case 1:     
                    //=-=-=-=-=-=-=-=-= User Turn =-=-=-=-=-=-=-=-=
                    calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                    // -1 = abort
                    if(calc_dmg != -1){
                        textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                        enemyHp = enemyHp - calc_dmg;
                        //Check if died
                        if(checkHps(userHp, enemyHp, userPkmn, enemyPkmn) == false){
                            if(lose(user,enemy,true) == true){
                                return;
                            } else {
                                enemyPkmn = sendNextPokemon(enemy, enemyHp);
                                break;
                            }
                        }
                    }
                    
                    // =-=-=-=-=-=-= Foe Turn =-=-=-=-=-=-=-=-=
                    calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                    // -1 = abort
                    if(calc_dmg != -1){
                        textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",true);
                        userHp = userHp - calc_dmg;
                        if(checkHps(userHp, enemyHp, userPkmn, enemyPkmn) == false){
                            if(lose(enemy,user,false) == true){
                                return;
                            } else {
                                userPkmn = sendNextPokemon(user, userHp);
                                break;
                            }
                        }
                    }

                break;
                case 2:     // Change pokemon
                    cout << "You decided to change" << endl;
                break;
            }
            break;
        case 2:     //  ========================================= ENEMY goes first =========================================
            switch(menuDecision){
                case 1:     
                    // =-=-=-=-=-=-= Foe Turn =-=-=-=-=-=-=-=-=
                    calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove);

                    // -1 = abort
                    if(calc_dmg != -1){
                        textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",true);
                        userHp = userHp - calc_dmg;
                        if(checkHps(userHp, enemyHp, userPkmn, enemyPkmn) == false){
                            if(lose(enemy,user,false) == true){
                                return;
                            } else {
                                userPkmn = sendNextPokemon(user, userHp);
                                break;
                            }
                        }
                    }
                    
                    
                    //=-=-=-=-=-=-=-=-= User Turn =-=-=-=-=-=-=-=-=
                    calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove);

                    // -1 = abort
                    if(calc_dmg != -1){
                        textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                        enemyHp = enemyHp - calc_dmg;
                        //Check if died
                        if(checkHps(userHp, enemyHp, userPkmn, enemyPkmn) == false){
                            if(lose(user,enemy,true) == true){
                                return;
                            } else {
                                enemyPkmn = sendNextPokemon(enemy, enemyHp);
                                break;
                            }
                        }
                    }
                    
                break;
                case 2:     //chose to change
                    cout << "You decided to change" << endl;

                break;
            }
        }      
    }
}

int main(){
    srand(time(NULL));
    //Lucas
    updateTrainers();

    //Lucas->mostrarEquipo();
    //Kaitlin->mostrarEquipo();

    Battle(Lucas,Kaitlin);

    delete Kaitlin;
    delete Lucas;
    return 0;
}