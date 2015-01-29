# Baptiste Fontaine et Julien Sagot -- TP 1

## Charge CPU

Le programme utilise une boucle avec un compteur qui est ajusté de façon
répétée en fonction de la charge, récupérée avec `times`.

## RAM

Le programme appelle `mmap` sur la taille d’une page jusqu’à ne plus pouvoir.
Il essaye aussi de verrouiller la mémoire.

## Documentation

Chaque exécutable (`load_cpu` et `load_ram`) est fourni avec une manpage
(respectivement `load_cpu.1` et `load_ram.1`).

## Temps

Estimé : 10h
Passé : 5h
