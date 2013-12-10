//NOM et Prénom : Morissette, Laurent
//Code permanent : MORL05058301
//antoine boutros
//BOUA06099209

#ifndef MOD_DOMAINE_H
#define MOD_DOMAINE_H 
#include <stdlib.h>
#include <stdio.h>
//verifie si un domnaine est syntaxiquement correcte
// retourne 1 si correcte et 0 sinon
int check(char *domaine) ;

//argv représente le tableau des paramères du programme
//cette fonction retourne la taille de la liste de domaine à partir argv[pos]
//la fin la liste est localisée soit par la fin du tableau d'argument soit par une option connue
int get_nbre_domaines(char  *const argv[], int pos);

//retourne 1 si la syntaxe  de domaine est correcte et place le début et la fin du domaine dans debut et fin
//retourne 0 si la syntaxe  de domaine est incorrecte

int get_debut(char * domaine, int *debut);
int get_fin(char * domaine, int *fin,int max);

#endif