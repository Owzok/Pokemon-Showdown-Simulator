#include "movepoolDB.cpp"

vector<Move*> moveset = {};
int level = 1;

// Pokemon(Name, id, level, HP, ATK, DEF, SPA, SPD, SPE, Ability, Type1, Type2, moveset, movepool)
map<string, Pokemon*> pokemones = {
    {"Turtwig", new Pokemon("Turtwig",387,level,55,68,64,45,55,31,"Overgrow",GRASS,NONE, moveset, TurtwigMP),},
    {"Chimchar", new Pokemon("Chimchar",390,level,44,58,44,58,44,61,"Blaze",FIRE,NONE, moveset, ChimcharMP),},
    {"Piplup",new Pokemon("Piplup",393,level,53,51,53,61,56,40,"Torrent",WATER,NONE, moveset, PiplupMP),},
    {"Starly",new Pokemon("Starly",396,level,40,55,30,30,30,60,"Keen Eye",NORMAL,FLYING, moveset, StarlyMP),},
    {"Bidoof", new Pokemon("Bidoof",399,level,59,45,40,35,40,31,"Simple",NORMAL,NONE, moveset, BidoofMP),},
    {"Kricketot",new Pokemon("Kricketot ",401,level,37,25,41,25,41,25,"Shed Skin",BUG,NONE, moveset, KricketotMP),},
    {"Shinx",new Pokemon("Shinx ",403,level,45,65,34,40,34,45,"Intimidate",ELECTRIC,NONE, moveset, ShinxMP),},
    {"Abra", new Pokemon("Abra",63,level,25,20,15,105,55,90,"Synchronize",PSYCHIC,NONE, moveset, AbraMP),},
    {"Magikarp", new Pokemon("Magikarp",129,level,20,10,55,15,20,80,"Swift Swim",WATER,NONE, moveset, MagikarpMP),},
    {"Budew",new Pokemon("Budew",406,level,40,30,35,50,70,55,"Natural Cure",GRASS,NONE, moveset, BudewMP),},
    {"Zubat", new Pokemon("Zubat",41,level,40,45,35,30,40,55,"Inner Focus",POISON,FLYING, moveset, ZubatMP),},
    {"Geodude", new Pokemon("Geodude",74,level,40,80,100,30,30,20,"Sturdy",ROCK,GROUND, moveset, GeodudeMP),},
    {"Machop", new Pokemon("Machop",66,level,70,80,50,35,35,35,"No Guard",FIGHTING,NONE, moveset, MachopMP),},
    {"Spiritomb", new Pokemon("Spiritomb",442,level,50,92,108,92,108,35,"Pressure",GHOST,DARK, moveset, SpiritombMP),},
    {"Roserade", new Pokemon("Roserade",407,level,60,70,65,125,105,90,"Poison Point",GRASS,POISON, moveset, RoseradeMP),},
    {"Gastrodon", new Pokemon("Gastrodon",423,level,111,83,68,92,82,39,"Storm Drain",WATER,GROUND, moveset, GastrodonMP),},
    {"Lucario", new Pokemon("Lucario",448,level,70,110,70,115,70,90,"Inner Focus",FIGHTING,STEEL, moveset, LucarioMP),},
    {"Milotic", new Pokemon("Milotic",350,level,95,60,79,100,125,81,"Competitive",WATER,NONE, moveset, MiloticMP),},
    {"Garchomp", new Pokemon("Garchomp",445,level,108,130,95,80,85,102,"Sand Veil",DRAGON,GROUND, moveset, GarchompMP),},
    {"Darkrai", new Pokemon("Darkrai",491,level,70,90,90,135,90,125,"Bad Dreams",DARK,NONE, moveset, DarkraiMP),},
    {"Latios", new Pokemon("Latios", 381, level, 80,90,80,130,110,110,"Levitate", DRAGON,PSYCHIC, moveset, LatiosMP),},
    {"Houndoom", new Pokemon("Houndoom", 229, level, 75,90,50,110,80,95,"Flash Fire", DARK,FIRE,moveset,HoundoomMP),},
    {"Flareon",new Pokemon("Flareon",136,level,65,130,60,95,110,65,"Flash Fire",FIRE,NONE,moveset,FlareonMP),},
    {"Rapidash",new Pokemon("Rapidash",78,level,65,100,70,80,80,105,"Flame Body",FIRE,NONE,moveset,RapidashMP),},    
    {"Magmortar",new Pokemon("Magmortar",467,level,75,95,67,125,95,83,"Vital Spirit",FIRE,NONE,moveset,MagmortarMP),},    
    {"Infernape",new Pokemon("Infernape",392,level,76,104,71,104,71,108,"Iron Fist",FIRE,NONE,moveset,InfernapeMP),}
};

map<string, Pokemon*> pokemones2 = {
    {"Turtwig", new Pokemon("Turtwig",387,level,55,68,64,45,55,31,"Overgrow",GRASS,NONE, moveset, TurtwigMP),},
    {"Chimchar", new Pokemon("Chimchar",390,level,44,58,44,58,44,61,"Blaze",FIRE,NONE, moveset, ChimcharMP),},
    {"Piplup",new Pokemon("Piplup",393,level,53,51,53,61,56,40,"Torrent",WATER,NONE, moveset, PiplupMP),},
    {"Starly",new Pokemon("Starly",396,level,40,55,30,30,30,60,"Keen Eye",NORMAL,FLYING, moveset, StarlyMP),},
    {"Bidoof", new Pokemon("Bidoof",399,level,59,45,40,35,40,31,"Simple",NORMAL,NONE, moveset, BidoofMP),},
    {"Kricketot",new Pokemon("Kricketot ",401,level,37,25,41,25,41,25,"Shed Skin",BUG,NONE, moveset, KricketotMP),},
    {"Shinx",new Pokemon("Shinx ",403,level,45,65,34,40,34,45,"Intimidate",ELECTRIC,NONE, moveset, ShinxMP),},
    {"Abra", new Pokemon("Abra",63,level,25,20,15,105,55,90,"Synchronize",PSYCHIC,NONE, moveset, AbraMP),},
    {"Magikarp", new Pokemon("Magikarp",129,level,20,10,55,15,20,80,"Swift Swim",WATER,NONE, moveset, MagikarpMP),},
    {"Budew",new Pokemon("Budew",406,level,40,30,35,50,70,55,"Natural Cure",GRASS,NONE, moveset, BudewMP),},
    {"Zubat", new Pokemon("Zubat",41,level,40,45,35,30,40,55,"Inner Focus",POISON,FLYING, moveset, ZubatMP),},
    {"Geodude", new Pokemon("Geodude",74,level,40,80,100,30,30,20,"Sturdy",ROCK,GROUND, moveset, GeodudeMP),},
    {"Machop", new Pokemon("Machop",66,level,70,80,50,35,35,35,"No Guard",FIGHTING,NONE, moveset, MachopMP),},
    {"Spiritomb", new Pokemon("Spiritomb",442,level,50,92,108,92,108,35,"Pressure",GHOST,DARK, moveset, SpiritombMP),},
    {"Roserade", new Pokemon("Roserade",407,level,60,70,65,125,105,90,"Poison Point",GRASS,POISON, moveset, RoseradeMP),},
    {"Gastrodon", new Pokemon("Gastrodon",423,level,111,83,68,92,82,39,"Storm Drain",WATER,GROUND, moveset, GastrodonMP),},
    {"Lucario", new Pokemon("Lucario",448,level,70,110,70,115,70,90,"Inner Focus",FIGHTING,STEEL, moveset, LucarioMP),},
    {"Milotic", new Pokemon("Milotic",350,level,95,60,79,100,125,81,"Competitive",WATER,NONE, moveset, MiloticMP),},
    {"Garchomp", new Pokemon("Garchomp",445,level,108,130,95,80,85,102,"Sand Veil",DRAGON,GROUND, moveset, GarchompMP),},
    {"Darkrai", new Pokemon("Darkrai",491,level,70,90,90,135,90,125,"Bad Dreams",DARK,NONE, moveset, DarkraiMP),},
    {"Latios", new Pokemon("Latios", 381, level, 80,90,80,130,110,110,"Levitate", DRAGON,PSYCHIC, moveset, LatiosMP),},
    {"Houndoom", new Pokemon("Houndoom", 229, level, 75,90,50,110,80,95,"Flash Fire", DARK,FIRE,moveset,HoundoomMP),},
    {"Flareon",new Pokemon("Flareon",136,level,65,130,60,95,110,65,"Flash Fire",FIRE,NONE,moveset,FlareonMP),},
    {"Rapidash",new Pokemon("Rapidash",78,level,65,100,70,80,80,105,"Flame Body",FIRE,NONE,moveset,RapidashMP),},    
    {"Magmortar",new Pokemon("Magmortar",467,level,75,95,67,125,95,83,"Vital Spirit",FIRE,NONE,moveset,MagmortarMP),},    
    {"Infernape",new Pokemon("Infernape",392,level,76,104,71,104,71,108,"Iron Fist",FIRE,NONE,moveset,InfernapeMP),}
};