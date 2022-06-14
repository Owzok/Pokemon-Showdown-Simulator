#include "trainer.cpp"

//0 = SlEEP ; 1 = FROZEN ; 2 = PARALYZED ; 3 = BURNED ; 4 = POISONED ; 5 = CONFUSED

//  Name   PP  Category    Power   Accurracy   SideEff     Type

//Normal

Move *Scratch = new Move("Scratch",35,PHYSICAL,40,100,"",NORMAL);
Move *Tackle = new Move("Tackle",35,PHYSICAL,40,100,"",NORMAL);
Move *Pound = new Move("Pound",35,PHYSICAL,40,100,"",NORMAL);
Move *QuickAttack = new Move("Quick Attack",30,PHYSICAL,40,100,"*+1",NORMAL);
Move *FurySwipes = new Move("Fury Swipes",30,PHYSICAL,18,80,"2-35%;3-35%;4-15%;5-15%",NORMAL);
Move *GigaImpact = new Move("Giga Impact",5,PHYSICAL,150,90,"recharge",NORMAL);

Move *Leer = new Move("Leer",30,STATUS,0,100,"e-1/Def",NORMAL);
Move *Growl = new Move("Growl",40,STATUS,0,100,"e-1/Atk",NORMAL);
Move *TailWhip = new Move("Tail Whip",30,STATUS,0,100,"e-1/Def",NORMAL);
Move *DefenseCurl = new Move("Defense Curl",40,STATUS,0,100,"u+1/Def && *2 Dmg Rollout",NORMAL);
Move *Growth = new Move("Growth",20,STATUS,0,100,"U+1/Atk/Spa",NORMAL);
Move *DoubleTeam = new Move("Double Team",15,STATUS,0,100,"u+1/Eva",NORMAL);
Move *FocusEnergy = new Move("Focus Energy",30,STATUS,0,100,"Next move is crit",NORMAL);
Move *Supersonic = new Move("Supersonic",30,STATUS,0,55,"s|100|5",NORMAL);
Move *MeanLook = new Move("Mean Look",5,STATUS,0,100,"e/Can't escape",NORMAL);

Move *Splash = new Move("Splash",40,STATUS,0,100,"",NORMAL);

//Grass
Move *Leafage = new Move("Leafage",40,PHYSICAL,40,100,"",GRASS);
Move *Absorb = new Move("Absorb",25,SPECIAL,20,100,"Restores 50*/. of dealt damage",GRASS);
Move *EnergyBall = new Move("EnergyBall",10,SPECIAL,90,100,"e/10*/. -spd",GRASS);

Move *StunSpore = new Move("Stun Spore",30,STATUS,0,75,"s|100|2",GRASS);
Move *WorrySeed = new Move("Worry Seed",10,STATUS,0,100,"e/Changes Ab to Insomnia",GRASS);

//Water
Move *WaterGun = new Move("Water Gun",25,SPECIAL,40,100,"u+1/Def",WATER);
Move *MuddyWater = new Move("Muddy Water",10,SPECIAL,90,85,"e/30*/.-acc",WATER);
Move *Surf = new Move("Surf",15,SPECIAL,90,85,"",WATER);

Move *Withdraw = new Move("Withdraw",40,STATUS,0,100,"",WATER);
Move *AquaRing = new Move("Aqua Ring",20,STATUS,0,0,"+1/16hp every turn",WATER);

//Fairy
Move *Charm = new Move("Withdraw",20,STATUS,0,100,"e-2/Atk",FAIRY);

//Fire
Move *Ember = new Move("Ember",25,SPECIAL,40,100,"s|+10|3",FIRE);

//Bug
Move *SilverWind = new Move("Silver Wind",60,SPECIAL,60,100,"10*/. + all stat",BUG);
Move *StruggleBug = new Move("Struggle Bug",20,SPECIAL,50,100,"e-1/Spa",BUG);

//Fighting
Move *Revenge = new Move("Revenge",10,PHYSICAL,60,100,"if got dmg, pwr = 120",FIGHTING);
Move *PowerUpPunch = new Move("Power-Up-Punch",20,PHYSICAL,40,100,"u+1/Atk",FIGHTING);
Move *LowKick = new Move("Low Kick",20,PHYSICAL,0,100,"DmgPerWeight",FIGHTING);
Move *AuraSphere = new Move("Aura Sphere",20,PHYSICAL,80,100,"",FIGHTING);
Move *BrickBreak = new Move("Brick Break",15,PHYSICAL,75,100,"Breaks Reflect & Light Screen",FIGHTING);

//Electric
Move *ThunderShock = new Move("ThunderShock",30,SPECIAL,40,100,"s|10|2",ELECRTRIC);

Move *Charge = new Move("Charge",20,SPECIAL,0,100,"Next e-move *2Power && u+1/spd",ELECRTRIC);

//Flying
Move *WingAttack = new Move("Wing Attack",35,PHYSICAL,60,100,"",FLYING);

//Rock
Move *Rollout = new Move("Rollout",20,PHYSICAL,30,90,"Power*2->everyTurn",ROCK);
Move *StoneEdge = new Move("Stone Edge",5,PHYSICAL,100,80,"x2*/.crit",ROCK);

//Dark
Move *DarkPulse = new Move("Dark Pulse",15, SPECIAL,80,100,"20*/. flinch",DARK);\
Move *Embargo = new Move("Embargo",15, STATUS,0,100,"Enemy cannot use items",DARK);

Move *Taunt = new Move("Taunt",20,STATUS,0,100,"e/NO_ATTACKS",DARK);

//Ghost
Move *Astonish = new Move("Astonish",25,PHYSICAL,50,100,"s|10|5",PSYCHIC);
Move *ShadowBall = new Move("Shadow Ball",15,SPECIAL,80,100,"e/20*/. -spd",PSYCHIC);

//Psychic
Move *Psychic = new Move("Psychic",10,SPECIAL,90,100,"e/10*/. -spd",PSYCHIC);
Move *Confusion = new Move("Confusion",15,PHYSICAL,30,100,"30*/.Flinch",PSYCHIC);
Move *Extrasensory = new Move("Extrasensory",20,PHYSICAL,80,100,"10*/.Flinch",PSYCHIC);

Move *Teleport = new Move("Teleport",20,STATUS,0,100,"Runs from battle",PSYCHIC);
Move *MirrorCoat = new Move("Mirror Coat",20,STATUS,0,100,"Special attack counter",PSYCHIC);

//Poison
Move *SludgeBomb = new Move("Sludge Bomb",10,SPECIAL,90,100,"s|30|4",POISON);

//Ground
Move *Earthquake = new Move("Earthquake",10,PHYSICAL,100,100,"",GROUND);

//Dragon
Move *DragonPulse = new Move("Dragon Pulse",10,SPECIAL,90,100,"",DRAGON);
Move *DragonRush = new Move("Dragon Rush",10,PHYSICAL,100,75,"e/20*/. flinch",DRAGON);

//Ice
Move *IceBeam = new Move("Ice Beam",10,SPECIAL,90,100,"s|10|1",ICE);
