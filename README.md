# Simulador de combates Pokemon en C++
## Incluye:
- Creacion de equipo pokemon:   
Puedes crear tu equipo de hasta 6 pokemones, escogiendo los ataques, pokemon y nivel que quieras.
- Equipos por defecto:  
Si prefieres jugar con un equipo ya creado, tambien existe esa opcion.
- Menu para atacar, cambiar de pokemon o mostrar datos tanto de ambos pokemones como de las variables del combate.
- Algoritmo Minimax que actua como IA y es contra el con quien uno se puede enfrentar.

## Caracteristicas:
- Los pokemones tienen: nivel, HP, ATK, DEF, SPA, SPD, SPE (tanto de estadistica base como de valor actual), modificadores para 
cada estadistica, sistema para crear IVS y EVS igualmente para cada estadistica, abilidades, tipos, moveset, movepool, estado (envenenado,
paralizado, dormido, congelado, etc.). 
- Se usan las mismas formulas del juego para calcular las estadisticas y el daño de cada ataque. Dentro de los ataques
estos se ven afectados por la ventaja y desventaja de la tabla de tipos, ataques STAB y climas.
- Hay bases de datos para la tabla de tipos, los movepools de cada pokemon, las estadisticas de cada pokemon, los datos de cada entrenador, etc.
Estos son almacenados en mapas con la llave siendo el nombre del valor y despues el objeto.

Se utilizaron mas de 2900 lineas de codigo para realizar todo esto.
