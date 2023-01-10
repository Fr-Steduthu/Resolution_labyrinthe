# Read me

<hr/>

## Développement du projet

                            Par Erwann SAINT GERMAIN

    Le projet a été développé et testé sur Visual Studio 2022.

## L'architecture du projet

Le projet Resolution_Labyrinthe est composé en deux parties : 

- App

- Labyrinth_solver

#### App

Le programme App prends un chemin d'accès en seul argument.

> Dans le cas où trop ou pas assez d'arguments seraient fournis, le programme se terminera et renveira le code d'erreur `-2`

Le chemin d'accès doit pointer sur un labyrinthe formaté de la façon suivante :

> Un rectangle de X par Y caractères, les fins de lignes étant marquées par le caractère `'\n'` ; le caractère `' '` indique un espace libre sur lequel le joueur peux se trouver,
> tout autre caractère sera considéré comme un mur infranchissable, pour plus d'informations, se référer au sujet.

> Dans le cas ou le fichier ne serait pas correctement formaté, l'application se terminera en ouvrant une fenêtre d'erreur.

> Dans le cas où le fichier serait d'une autre nature, aucun comportement n'est prévu.

On notera que cela ne corresponds pas aux fichiers fournis sur UPdago pour tester le projet, dont la longeur des lignes n'est pas uniforme !
Ce problème est connu, mais n'a, à ce jour, pas encoré été réglé.

#### Labyrinth_solver

> Le type `coordinate`, alias des `unsigned long long int`, représente l'enssemble des valeurs acceptables des coordonées d'une _grid_
> 
> Le type `coords` est une structure couplant deux `coordinate` sous les noms `x`et `y`

La bibliothèque Labyrinth_solver est composée de :

- Le namespace `labyrinth_solver`
  
  - _tracer_
    
    - Représente l'historique des déplacements du joueur via une liste de `direction`
  
  - _player_
    
    - Représente le joueur, contiens ses coordonées (accessibles via`const coords& player::coordinates() const`, `coordinate player::x() const` et `coordinate player::y() const`)
      et un objet _tracer_ (`std::vector<direction> player::path_taken() const`).
  
  - _grid_
    
    - Représente le plateau de jeu, connais l'emplacement des murs et des cases libres (accessible via `bool grid::walkable(const coordinate&, const coordinate&) const` (true si libre, false sinon))
      ainsi que de sa case de fin (`coords grid::exit() const`).
  
  - _labyrinth_
    
    - Fais le lien entre _player_ et _grid_ ; déplace le joueur selon le mouvement demandé si possible.
      S'occupe de l'orientation du joueur (`direction`).
  
  > `direction` représente les quatres points cardinaux, une orientation absolue en d'autres termes ; on y trouve donc les valeurs `North` `West` `South` et `East` 
  > 
  > `facing`, par opposition, représente une orientation relative et est représentée par les valeurs `Front`, `Left`, `Back` et `Right`.
  > 
  > Les deux types énumérés peuvent êtres utilisés comme argument de la fonction `labyrinth::move`, mais ne déplacerons pas dans la même _direction_ selon l'orientation du joueur.

- Le namespace `labyrinth_solver::solvers`
  
  Contiens la classe `solver`, une classe ayant pour seul but d'être spécifiée à travers la méthode virtuelle pure `state move()`
  
  > En théorie, seuls les `state` `running` et `defeat` devraient êtres utilisés lors de l'implémentation de cette méthode, l'état `victory` étant géré par la classe `solver`

        On utilisera les méthodes `state step()` et `void solve()` pour faire avancer la résolution du labyrinthe.

>  Des `solver` sont fournis avec la bibliothèque ; pour y avoir accès, il faudra cependant ajouter la ligne `#define INCLUDE_SOLVERS` avant la ligne d'importation de la bibliothèque.

<hr/>

## Les problèmes

1. Les tests
   
   * Par manque de temps et de connaissances sur la bibliothèque utilsée pour les tests, seul un test existe et n'a pas pû être lancé.

2. Le format des fichiers
   
   * Comme précisé plus tôt, les fichiers fournis pour effectuer les tests, à l'instar de ceux pouvant être générés à l'[url](https://www.dcode.fr/generateur-labyrinthe) fournie, ne correspondent pas à ce que la bibliothque (et donc l'application) sont en mesure de lire ;
     Il faut rajouter un espace sur la dernière et l'avant dernière ligne du labyrinthe pour qu'il soit lu correctement.
