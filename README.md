# Pokemon Showdown Simulator

<p aling="center">
<img src="https://github.com/CS1103/proyecto-final-grupo8_pokemon/blob/main/img/pokemonshowdown.png">
</p>

Introducción
-----

> Resumen del juego
- Pokemon Showdown es un juego donde 2 jugadores luchan entre sí en una batalla pokemon. El jugador puede crear un equipo de hasta 6 pokemones. Se pueden personalizar los ataques, estadísticas, tipos y niveles de todas las formas. Además existe la opción de jugar con un equipo ya creado por defecto. El jugador dispone de un menú que revive la experiencia del pokemon clásico de Gameboy, donde dispone de opciones para atacar, cambiar de pokemon si tiene alguno disponible, o mostrar datos de los pokemones en lucha como de las variales de combate. El objetivo del juego es, evidentemente, derrotar a tu adversario en una batalla pokemon. Sin embargo esto no es todo, puesto que el juego también tiene como finalidad customizar los valores de tus pokemones creados en fin de simular la experiencia.

> Resumen del programa
- El programa cuenta primero con la opcion de que el jugador decida si quiere crear su equipo o jugar con uno de los equipos ya existentes, despues de esto aparece la opcion a escoger para decidir si quieres jugar tu contra la maquina o hacer que una maquina se enfrente contra otra. Una vez iniciado el combate se toma la decision de la maquina usando nuestro algoritmo MiniMax y espera a la respuesta del usuario el cual puede decidir entre atacar (en caso ataque tiene igual distintos ataques para escoger) cambiar de pokemon u observar datos de tanto el como su rival como el campo de batalla. El juego se desarrolla hasta que ya un entrenador se quede sin pokemones y ahi es donde el otro resulta ser el ganador.

### Características del proyecto
> Incluye:
##### Creacion de equipo pokemon:
Puedes crear tu equipo de hasta 6 pokemones, escogiendo los ataques, pokemon y nivel que quieras.
Equipos por defecto:
Si prefieres jugar con un equipo ya creado, tambien existe esa opcion.
##### Jugadas y movimientos
Menu para atacar, cambiar de pokemon o mostrar datos tanto de ambos pokemones como de las variables del combate.
Algoritmo Minimax que actua como IA y es contra el con quien uno se puede enfrentar.
##### Caracteristicas de los Pokemones
Los pokemones tienen: nivel, _HP_, _ATK_, _DEF_, _SPA_, _SPD_, _SPE_ (tanto de estadistica base como de valor actual), modificadores para cada estadistica, sistema para crear _IVS_ y _EVS_ igualmente para cada estadistica, habilidades, tipos, _moveset_, _movepool_, estado (envenenado, paralizado, dormido, congelado, etc.).
Se usan las mismas formulas del juego para calcular las estadisticas y el daño de cada ataque. Dentro de los ataques estos se ven afectados por la ventaja y desventaja de la tabla de tipos, ataques STAB y climas.
Hay bases de datos para la tabla de tipos, los movepools de cada pokemon, las estadisticas de cada pokemon, los datos de cada entrenador, etc. Estos son almacenados en mapas con la llave siendo el nombre del valor y despues el objeto.
Se utilizaron mas de ___ lineas de codigo para realizar todo esto.
### Video instructivo
- En el siguiente video se explica el proyecto y se mencionan datos interesantes de la programación del mismo.
- [Video de explicación del proyecto](link del video)

### Estructura de Archivos

La estructura de archivos se muestra a continuación y dependerá del uso de cada archivo

```
proyecto-final-grupo8_pokemon/
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
## Arquitectura del código

### Diagrama de Clases
<p aling="center">
<img src="https://github.com/CS1103/proyecto-final-grupo8_pokemon/blob/main/img/UML%20class.png">
</p>
### Patrones de diseño

## Problemas encontrados en la elaboración del proyecto

Al principio buscamos consumir la API de Pokemon. Sin embargo, fue difícil de hacer asi que hicimos las bases de datos manualmente usando mapas.
Al comienzo se nos hizo complicado el crear el algoritmo de la IA.
Se nos complico implementar la libreria grafica porque algunos de nuestros compañeros usan linux y ahi no funcionaba.

## Bibliografía


##### Contribuyentes

| Martin P.   | Marcelo Z.  | Kevin H.   | Paolo V.   | Gabriel E. |
| :---:       |    :----:   |   :---:    |  :---:     |   :---:    |
| <img src= "https://avatars.githubusercontent.com/u/87045535?v=4">   | <img src="https://avatars.githubusercontent.com/u/85197213?v=4">   | <img src="https://avatars.githubusercontent.com/u/85197193?v=4">  | <img src="https://avatars.githubusercontent.com/u/83627663?v=4">  | <img src="https://avatars.githubusercontent.com/u/85197211?v=4">  |
| [Martín Perez Bonany](https://github.com/Owzok/)    | [Marcelo Zuloeta](https://github.com/marceloZS)    | [Kevin Huaman](https://github.com/khuaman)   | [Paolo Vásquez](https://github.com/paoloovasquezg)   |  [Gabriel Espinoza](https://github.com/Gabrieleeh32159) |
