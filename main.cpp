#include "battleFunctions.cpp"

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
    int turn = 0;
    Weather weather = CLEAR;
    int weatherTurn = 0;

    int user_LightScreen = 0;
    int user_Reflect = 0;

    int enemy_LightScreen = 0;
    int enemy_Reflect = 0;

    int menuDecision = 0;
    int speedTurn;
    int calc_dmg = 0;

    int ia = 0;
    int other_ia = 0;

    Pokemon* entryPkmn;

    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" sent out "+enemyPkmn->getName()+"!\n ",true);
    clearScreen();

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
                                calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove, weather);

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
                                calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove, weather);

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
                        enemyMove = enemyAttack(userPkmn, enemyPkmn, weather);
                        switch(speedTurn){
                        case 1:
                            //========================================= starts USER =========================================
                            textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),true);
                            calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove, weather);

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
                            calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

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
                            calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

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
                            calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove, weather);

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
                        enemyMove = enemyAttack(userPkmn, enemyPkmn, weather);
                        changePkmnUI(user);
                        entryPkmn = changePokemon(user);

                        if(entryPkmn  == nullptr)
                            break;

                        userPkmn = entryPkmn;
                        textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",true);
                        calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);
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
                displayData(userPkmn, enemyPkmn, turn, weather, weatherTurn, user_LightScreen, enemy_LightScreen, user_Reflect, enemy_Reflect);
            break;
        }
    }
    turn++;
    if(weatherTurn == 0){
        weather = Weather::CLEAR;
    }

    if(weatherTurn != 0)
        weatherTurn--;

    if(user_LightScreen != 0)
        user_LightScreen--;

    if(enemy_LightScreen != 0)
        enemy_LightScreen--;

    if(user_Reflect != 0)
        user_Reflect--;
    
    if(enemy_Reflect !=0)
        enemy_Reflect--;
}

void BattleIA(Trainer*user, Trainer*enemy){
    string partyballs(enemy->getPartySize(),'O');
    string emptyballs(6-enemy->getPartySize(),'X');
    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" would like to battle! \n\t"+partyballs+emptyballs+"\n", true);

    bool inBattle = true;

    Pokemon *userPkmn = user->getLeadPkmn();
    Pokemon *enemyPkmn = enemy->getLeadPkmn();
    Move *userMove;
    Move *enemyMove;
    int turn = 0;
    Weather weather = CLEAR;
    int weatherTurn;

    int user_LightScreen = 0;
    int user_Reflect = 0;

    int enemy_LightScreen = 0;
    int enemy_Reflect = 0;

    int menuDecision = 0;
    int speedTurn;
    int calc_dmg = 0;

    int ia = 0;
    int other_ia = 0;

    Pokemon* entryPkmn;

    textBox(enemy->classtring(enemy->getTC())+" "+enemy->getName()+" sent out "+enemyPkmn->getName()+"!\n ",true);
    clearScreen();

    // ================ END VARS ======================
    while(inBattle == true){
        userPkmn->updateStats();
        enemyPkmn->updateStats();
        
        ia = IAdecision(userPkmn, enemyPkmn, enemy->getParty());

        ShowPokemonMenuHUD(user,enemy,userPkmn, enemyPkmn);

        other_ia = IAdecision(enemyPkmn, userPkmn, user->getParty());
        
        // 1 ia cambiar
            // 2 cambiar
            // 2 atacar
                // 3 1 mas rapido
                // 3 2 mas rapido
        // 1 quiera atacar
            // 2 cambiar
            // 2 atacar
                // 3 1 mas rapido
                // 3 2 mas rapido


        switch(ia){
            //enemy changes
            case 1:
                switch(other_ia){
                    // enemy change
                    // user decides to change
                    case 1:
                        enemyPkmn = IAchangePokemon(enemy, IAChange(userPkmn, enemyPkmn, enemy->getParty())); 
                        entryPkmn = changePokemon(user);

                        if(entryPkmn  == nullptr)
                            break;

                        userPkmn = entryPkmn;
                    break;
                    // user attacks
                    case 2:
                        enemyPkmn = IAchangePokemon(enemy, IAChange(userPkmn, enemyPkmn, enemy->getParty())); 
                        // select user move
                        userMove = enemyAttack(enemyPkmn, userPkmn, weather);
                        calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

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
                }
            break;
            // enemy attacks
            case 2:
                switch(other_ia)
                {
                    // user changes
                    case 1:
                        entryPkmn = changePokemon(user);
                        if(entryPkmn  == nullptr)
                            break;
                        userPkmn = entryPkmn;

                        //  ========================================= ENEMY goes first =========================================
                        
                        enemyMove = enemyAttack(userPkmn, enemyPkmn, weather);
                        
                        textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",false);
                        calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

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
                    // user attacks
                    case 2:
                        // check faster pkmn
                        speedTurn = speedCheck(userPkmn, enemyPkmn);
                        
                        switch(speedTurn)
                        {
                            case 1:
                                //========================================= starts USER =========================================
                                userMove = enemyAttack(enemyPkmn, userPkmn, weather);

                                textBox((userPkmn->getName()+" used "+userMove->getName()+"\n"),false);
                                calc_dmg = calculateDamage(userPkmn, enemyPkmn, userMove, weather);

                                // -1 = abort, else calculate damage
                                if(calc_dmg != -1)
                                {
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
                                enemyMove = enemyAttack(userPkmn, enemyPkmn, weather);

                                textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",false);
                                calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

                                // -1 = abort, else calculate damage
                                if(calc_dmg != -1)
                                {
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
                            case 2:
                                //  ========================================= ENEMY goes first =========================================
                                enemyMove = enemyAttack(userPkmn, enemyPkmn, weather);
                                
                                textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",false);
                                calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

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

                                //  ========================================= ENEMY goes first =========================================
                                userMove = enemyAttack(enemyPkmn, userPkmn, weather);
                                
                                textBox(enemyPkmn->getName()+" used "+enemyMove->getName()+"\n",false);
                                calc_dmg = calculateDamage(enemyPkmn, userPkmn, enemyMove, weather);

                                // -1 = abort, else calculate damage
                                if(calc_dmg != -1)
                                {
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
                }
            break;
        }
    }
    turn++;
    if(weatherTurn == 0){
        weather = Weather::CLEAR;
    }

    if(weatherTurn != 0)
        weatherTurn--;

    if(user_LightScreen != 0)
        user_LightScreen--;

    if(enemy_LightScreen != 0)
        enemy_LightScreen--;

    if(user_Reflect != 0)
        user_Reflect--;
    
    if(enemy_Reflect !=0)
        enemy_Reflect--;
}

int main(){
    srand(time(NULL));

    Trainer* player = start();

    char fight;

    cout << "IA vs IA? [Y/N]: " << endl; 
    cin >> fight;

    if(fight == 'Y'){
        BattleIA(player, Cynthia);
    }
    if(fight == 'N'){
        Battle(player, Cynthia);
    }

    return 0;
}