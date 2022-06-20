#include "movepoolDB.cpp"

vector<Move*> moveset = {};
int level = 1;

map<string, Pokemon*> pokemones = {
    {"Turtwig", new Pokemon("Turtwig",387,level,55,68,64,45,55,31,"Overgrow",GRASS,NONE, moveset, TurtwigMP, HEALTHY),},
    {"Chimchar", new Pokemon("Chimchar",390,level,44,58,44,58,44,61,"Blaze",FIRE,NONE, moveset, ChimcharMP, HEALTHY),},
    {"Piplup",new Pokemon("Piplup",393,level,53,51,53,61,56,40,"Torrent",WATER,NONE, moveset, PiplupMP, HEALTHY),},
    {"Starly",new Pokemon("Starly",396,level,40,55,30,30,30,60,"Keen Eye",NORMAL,FLYING, moveset, StarlyMP, HEALTHY),},
    {"Bidoof", new Pokemon("Bidoof",399,level,59,45,40,35,40,31,"Simple",NORMAL,NONE, moveset, BidoofMP, HEALTHY),},
    {"Kricketot",new Pokemon("Kricketot ",401,level,37,25,41,25,41,25,"Shed Skin",BUG,NONE, moveset, KricketotMP, HEALTHY),},
    {"Shinx",new Pokemon("Shinx ",403,level,45,65,34,40,34,45,"Intimidate",ELECRTRIC,NONE, moveset, ShinxMP, HEALTHY),},
    {"Abra", new Pokemon("Abra",63,level,25,20,15,105,55,90,"Synchronize",PSYCHIC,NONE, moveset, AbraMP, HEALTHY),},
    {"Magikarp", new Pokemon("Magikarp",129,level,20,10,55,15,20,80,"Swift Swim",WATER,NONE, moveset, MagikarpMP, HEALTHY),},
    {"Budew",new Pokemon("Budew",406,level,40,30,35,50,70,55,"Natural Cure",GRASS,NONE, moveset, BudewMP, HEALTHY),},
    {"Zubat", new Pokemon("Zubat",41,level,40,45,35,30,40,55,"Inner Focus",POISON,FLYING, moveset, ZubatMP, HEALTHY),},
    {"Geodude", new Pokemon("Geodude",74,level,40,80,100,30,30,20,"Sturdy",ROCK,GROUND, moveset, GeodudeMP, HEALTHY),},
    {"Machop", new Pokemon("Machop",66,level,70,80,50,35,35,35,"No Guard",FIGHTING,NONE, moveset, MachopMP, HEALTHY),},
    {"Spiritomb", new Pokemon("Spiritomb",442,level,50,92,108,92,108,35,"Pressure",GHOST,DARK, moveset, SpiritombMP, HEALTHY),},
    {"Roserade", new Pokemon("Roserade",407,level,60,70,65,125,105,90,"Poison Point",GRASS,POISON, moveset, RoseradeMP, HEALTHY),},
    {"Gastrodon", new Pokemon("Gastrodon",423,level,111,83,68,92,82,39,"Storm Drain",WATER,GROUND, moveset, GastrodonMP, HEALTHY),},
    {"Lucario", new Pokemon("Lucario",448,level,70,110,70,115,70,90,"Inner Focus",FIGHTING,STEEL, moveset, LucarioMP, HEALTHY),},
    {"Milotic", new Pokemon("Milotic",350,level,95,60,79,100,125,81,"Competitive",WATER,NONE, moveset, MiloticMP, HEALTHY),},
    {"Garchomp", new Pokemon("Garchomp",445,level,108,130,95,80,85,102,"Sand Veil",DRAGON,GROUND, moveset, GarchompMP, HEALTHY),},
    {"Darkrai", new Pokemon("Darkrai",491,level,70,90,90,135,90,125,"Bad Dreams",DARK,NONE, moveset, DarkraiMP, HEALTHY),},
    {"Latios", new Pokemon("Latios", 381, level, 80,90,80,130,110,110,"Levitate", DRAGON,PSYCHIC, moveset, LatiosMP, HEALTHY),}
    };