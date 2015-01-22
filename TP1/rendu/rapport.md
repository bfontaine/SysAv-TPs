# Baptiste Fontaine -- TP 1

## Charge CPU

Le programme ne marche qu’avec Linux puisqu’il parse `/proc/stat`. Il
fonctionne avec un compteur de boucle. Il récupère les temps CPU, fais le
nombre de boucles correspondant, puis récupère les nouveaux temps et calcule la
charge CPU en fonction de la différence. Il ajuste le compteur de boucle en
fonction du résultat (si la charge est trop faible il augmente le compteur,
si elle est trop forte il le diminue), puis recommence.

## RAM

Pas (encore) fait.

## Temps

Estimé : 10h
Passé : 4h
