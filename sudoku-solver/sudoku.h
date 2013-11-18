/* Sudoku.h
   Module gérant des grilles de sudoku sous la forme d'une classe d'objets
   implémentée de façon abstraite.

   Les fonctions sont implementees pour fonctionner avec des sudokus
   de n'importe quelle taille (mais sudokuAffiche ne donnerait pas des 
   resultats elegants avec des sudokus de taille 16 x 16 ou superieure).

   Emmanuel Chieze
*/

#ifndef SUDOKU_H
# define SUDOKU_H

/*************************/
/* Structures de données */
/*************************/
/* Par défaut on traite des grilles 9x9, mais on peut egalement traiter
   des grilles 4x4 ou autres. Le choix est fixe a la compilation. Seule la
   ligne ci-dessous est a modifier dans ce cas. */
#define TAILLE_ZONE 3

#define TAILLE ((TAILLE_ZONE) * (TAILLE_ZONE))

typedef enum { SUDOKU_OK, SUDOKU_CASE_DEJA_JOUEE, SUDOKU_COUP_IMPOSSIBLE_A_JOUER, SUDOKU_AUCUNE_CASE, SUDOKU_GRILLE_IMPOSSIBLE } Statut;
typedef enum { SUDOKU_UNE, SUDOKU_PLUSIEURS} NbValeurs;

typedef struct Grille * Sudoku;

/****************************************/
/* Fonctions de manipulation de sudokus */
/****************************************/

/* Fonctions permettant de generer ou de supprimer des sudokus */
/* sudokuCree : retourne un sudoku vide (chaque case est vide) 
		ou retourne NULL s'il n'y a pas suffisamment
		de memoire disponible */
Sudoku sudokuCree(void); 

/* sudokuCopie : retourne un sudoku identique a celui passe en argument 
		 ou retourne NULL s'il n'y a pas suffisamment
		 de memoire disponible
   Preconditions : le sudoku est correctement initialise */
Sudoku sudokuCopie(Sudoku sudoku);

/* sudokuDetruit : supprime le sudoku passe en argument 
   Preconditions : le sudoku est correctement initialise */
void sudokuDetruit(Sudoku sudoku);

/************************************************************/
/* Fonctions permettant d'analyser et de modifier un sudoku */
/************************************************************/
/* sudokuJouerCase : permet d'inscrire un nombre dans une case vide specifiee tout en maintenant a jour
                     les cases vides situees sur la meme ligne, la meme colonne ou la meme zone.
   Preconditions : le sudoku est correctement initialise
		   les coordonnees de la case sont comprises entre 1 et TAILLE
		   la valeur a jouer est comprise entre 1 et TAILLE 
   Resultat : SUDOKU_CASE_DEJA_JOUEE si la case indiquee n'est pas vide au moment de l'appel
              SUDOKU_COUP_IMPOSSIBLE_A_JOUER si la case est vide mais n'autorise pas la valeur specifiee en 
                3eme argument 
              SUDOKU_GRILLE_IMPOSSIBLE si le fait de jouer la case fait en sorte qu'une des cases vides 
                affectees par le coup (donc situee dans la meme ligne, la meme rangee ou la meme zone que la 
                case jouee) n'autorise plus aucune valeur 
              SUDOKU_OK : le coup est joue, sans probleme */
Statut sudokuJouerCase(Sudoku sudoku, int ligne, int colonne, int valeur);

/* sudokuRetirerValeurPossible : permet de limiter l'exploration de l'espace des solutions
   par le programme, en excluant une valeur de 1 a TAILLE des valeurs permises dans une case
   donnee.
   Preconditions : le sudoku est correctement initialise
		   les coordonnees de la case sont comprises entre 1 et TAILLE 
		   la valeur a exclure est comprise entre 1 et TAILLE 
   Resultat : SUDOKU_GRILLE_IMPOSSIBLE si le fait de jouer la case fait en sorte qu'une des cases vides 
                affectees par le coup (donc situee dans la meme ligne, la meme rangee ou la meme zone que la 
                case jouee) n'autorise plus aucune valeur 
              SUDOKU_OK : soit la case est vide, et on elimine la valeur possible de cette case, 
                          sans creer de probleme (donc la case vide autorise encore au moins une autre valeur)
                          soit la case est pleine, et il n'y a rien a faire */
Statut sudokuRetirerValeurPossible(Sudoku sudoku, int ligne, int colonne, int valeur);

/*****************************************************************/
/* Fonctions permettant d'obtenir des informations sur un sudoku */
/*****************************************************************/
/* sudokuNbCasesVides : retourne le nombre de cases vides du sudoku passe en argument
   Preconditions : le sudoku est correctement initialise */
int sudokuNbCasesVides(Sudoku sudoku);

/* sudokuChercheCoup : retourne un coup valise. Dans le cas ou plusieurs coups sont permis,
   la fonction en retourne un. Le choix du coup a jouer n'est pas specifie (et peut dependre
   de l'implementation choisie pour la fonction).
   Arguments : 	sudoku 			le sudoku sur lequel on joue
	       	nbValeursRecherchees	permet de specifier le type de case sur lequel on veut jouer; 
                  valeurs autorisees :  SUDOKU_UNE (si on cherche une case ne pouvant recevoir qu'une 
                                          seule valeur, compte tenu de l'etat actuel du sudoku et des 
                                          heuristiques implementees par le programme), 
                                        SUDOKU_PLUSIEURS (si on cherche une case pouvant recevoir 2 
                                          valeurs distinctes ou plus)
		ligne, colonne, valeur  parametres permettant de transmettre a la fonction appelante le coup 
                  a jouer. Lorsque plusieurs valeurs peuvent etre jouees dans la case (dans le cas ou 
                  nbValeursRecherchees vaut SUDOKU_PLUSIEURS), le choix de la valeur a jouer n'est pas 
                  specifie et depend de l'implementation. Les valeurs de ligne, colonne et valeur sont 
                  comprises entre 1 et TAILLE. 
   Preconditions : le sudoku est correctement initialise
		   nbValeursRecherchees a l'une des deux valeurs SUDOKU_UNE ou SUDOKU_PLUSIEURS 
   Resultat : SUDOKU_AUCUNE_CASE si aucune case du type recherche n'existe sur la grille
              SUDOKU_OK si une case du type recherche a ete trouvee */
Statut sudokuChercheCoup(Sudoku sudoku, NbValeurs nbValeursRecherchees, int * ligne, int * colonne, int * valeur);

/* sudokuAffiche : permet d'afficher un sudoku, sous la forme d'un tableau TAILLE * TAILLE. Les cases pleines 
     sont affichees telles quelles, les cases vides sont affichees en specifiant la liste des valeurs possibles
     dans cette case, entre [ et ]. Si le sudoku ne comporte aucune case vide, on utilise 1 caractére pour 
     representer chaque case. Sinon, on utilise 11 caracteres pour representer chaque case.
     Exemple d'affichage d'un sudoku resolu :
5 3 4 6 8 1 2 9 7
7 2 8 4 5 9 1 3 6
1 6 9 2 7 3 4 5 8
9 8 3 7 1 5 6 2 4
4 1 2 3 6 8 5 7 9
6 5 7 9 4 2 3 8 1
3 4 5 8 9 6 7 1 2
8 7 1 5 2 4 9 6 3
2 9 6 1 3 7 8 4 5

     Exemple d'affichage d'un sudoku en cours de resolution : 
          5           3 [   4     ]           6           8 [1  4     ] [ 2       ]           9           7
[      7  ]           2           8 [   4     ] [   45    ]           9           1           3 [     6   ]
          1 [     6  9] [        9] [ 2       ]           7           3           4 [ 2  5    ]           8
          9           8 [ 23   7  ] [      7  ]           1           5           6 [ 2       ]           4
          4           1 [ 2       ]           3           6           8           5           7 [        9]
          6           5 [      7  ]           9 [   4     ]           2           3           8           1
[  3      ]           4 [  3 5    ]           8           9           6           7           1           2
          8           7 [1        ]           5           2 [   4     ]           9           6           3
          2 [        9]           6           1           3 [      7  ] [       8 ]           4           5
     Dans ce cas, les espaces entre les crochets peuvent se situer n'importe ou, cela depend de 
     l'implementation. Par exemple, dans le cas de la case de la ligne 1 et de la colonne 3,
     l'affichage pourrait aussi bien etre [4        ] ou [        4] ou autre.

   Preconditions : le sudoku est correctement initialise */
void sudokuAffiche(Sudoku sudoku);

#endif /* SUDOKU_H */
