# Spécifications sur la machine

> Système d'exploitation : Windows 11 Famille 64bits 22621.819
> 
> Processeur : AMD Ryzen 7 5800H with Radeon Graphics            3.20 GHz

# Tests sur le fichier `lab2_10x10.txt`

<img src="/meusures_lb2_10x10.png?msec=1673371958054" title="null" alt="null" data-align="left">

# Tests sur le fichier `lab2_25x25.txt`

<img title="null" src="/meusures_lb1p_25x25.png" alt="null">

# Tests sur le fichier `lab4_50x50.txt`

<img title="null" src="/50x50_perf.png" alt="null">

# Comparaison

On observe que :

* Le temps de résolution via `solver_random` a décuplé lors du passage de 10x10 à 25x25, est trop lent pour 50x50 et est le plus lent

* Les temps de résolution de `solver_left` et `solver_left_alt` sont semblables sur les trois labyrinthes mais que le plus court est toujours `solver_left_alt`

* Le temps de résolution de `solver_right` est proche de deux fois plus rapide que `solver_left` et `solver_left_alt`

* `solver_straightline` se bloque extrèmement vite et ne finis pas les labyrinthes

* Les temps de résolution de `solver_right`, `solver_left` et `solver_left_alt` augmentent de façon exponentielle avec le nombre de cases

# Conclusion

Le temps de résolution augmente de façon exponentielle, hormis pour `solver_straightline`, qui sera très vite bloqué.
