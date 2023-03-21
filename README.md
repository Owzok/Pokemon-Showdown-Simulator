# Pokemon Showdown Simulator

🦉 Introduction
-----

About the game  
>[Pokemon Showdown](https://play.pokemonshowdown.com/) is a game where 2 players fight each other in a pokemon battle. The player can create a team of up to 6 pokemons. Attacks, stats, types and levels can be customized in all ways. There is also the option to play with a team already created by default. The player has a menu that revives the experience of the classic Gameboy pokemon, where he has options to attack, change pokemon if he has one available, or show data on the pokemon in battle as well as combat variables. The objective of the game is obviously to defeat your opponent in a pokemon battle. However, this is not all, since the game also aims to customize the values of your created pokemon in order to simulate the experience.

<p align="center"><img src="https://imgur.com/Ub8b3sF.png " width=400></p>  

About the program  
> The program first has the option for the player to decide if he wants to create his team or play with one of the already existing teams, after this the option to choose appears to decide if you want to play against the machine or have a machine become face against another. Once the combat has started, the machine's decision is made using our MinMax algorithm and waits for the user's response, which can decide between attacking (in the event of an attack, it has different attacks to choose from), changing the pokemon or observing data from both it and his rival as the battlefield. The game continues until one trainer runs out of pokemon and that's where the other one turns out to be the winner.  
<p align="center"><img src="https://imgur.com/LEGAjqJ.png" width=400></p>  


### Project features
##### Team-building:  
>You can create your team of up to 6 pokemons, choosing the attacks, pokemon and level you want.
##### Default Teams:  
>If you prefer to play with an already created team, there is also that option.
##### Plays and moves
>Menu to attack, change pokemon or show data for both pokemons and combat variables.
Minimax algorithm that acts as an AI and is against whom one can face.

##### Pokemon Characteristics
>Pokemon have: 
level, _HP_, _ATK_, _DEF_, _SPA_, _SPD_, _SPE_ (both base stat and current value), modifiers for each stat, system to create _IVS_ and _EVS_ equally for each stat, abilities, types, _moveset_, _movepool_, state (poisoned, paralyzed, asleep, frozen, etc.).

<p align="center"><img src="https://imgur.com/UfMCKy9.png " width=400></p>  


> The same formulas from the game are used to calculate the stats and damage of each attack. Within the attacks these are affected by the advantage and disadvantage of the type table, STAB attacks and weather.

<p align="center"><img src="https://imgur.com/D66yJcf.png " width=400></p>  

> There are databases for the type table, the movepools of each pokemon, the stats of each pokemon, the data of each trainer, etc. These are stored in maps with the key being the name of the value and then the object.
<p align="center"><img src="https://imgur.com/jCXy78E.png " width=400></p>  


More than 3000 lines of code were used to do all of this.


### File Structure
```
root/
|__ battleFunctions.cpp
|__ main.cpp
|__ main.exe
|__ move.cpp
|__ move.h	
|__ moveDatabase.cpp
|__ movepoolDB.cpp
|__ pokemon.cpp
|__ pokemon.h
|__ pokemonDataBase.cpp
|__ trainer.cpp
|__ trainer.h
|__ trainerDB.cpp	
|__ img/
    |__ pokemonshowdown.png				
```

### Class Diagram
<p aling="center">
<img src="https://github.com/CS1103/proyecto-final-grupo8_pokemon/blob/main/img/UML%20class.png">
</p>

⢀.  
⢻⣿⡗⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄  
⠀⢻⣇⠀⠈⠙⠳⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠋⣹⣿⡿  
⠀⠀⠹⣆⠀⠀⠀⠀⠙⢷⣄⣀⣀⣀⣤⣤⣤⣄⣀⣴⠞⠋⠉⠀⠀⠀⢀⣿⡟  
⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋  
⠀⠀⠀⠀⠈⠻⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⡾⠋  
⠀⠀⠀⠀⠀⣼⠃⠀⢠⠒⣆⠀⠀⠀⠀⠀⠀⢠⢲⣄⠀⠀⠀⢻⣆  
⠀⠀⠀⠀⢰⡏⠀⠀⠈⠛⠋⠀⢀⣀⡀⠀⠀⠘⠛⠃⠀⠀⠀⠈⣿⡀  
⠀⠀⠀⠀⣾⡟⠛⢳⠀⠀⠀⠀⠀⣉⣀⠀⠀⠀⠀⣰⢛⠙⣶⠀⢹⣇  
⠀⠀⠀⠀⢿⡗⠛⠋⠀⠀⠀⠀⣾⠋⠀⢱⠀⠀⠀⠘⠲⠗⠋⠀⠈⣿  
⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠈⠓⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇  
⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧  
⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁  

