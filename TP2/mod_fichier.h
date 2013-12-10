//NOM et Prénom : Morissette, Laurent
//Code permanent : MORL05058301
//antoine boutros
//BOUA06099209

#ifndef MOD_FICHIER_H
#define MOD_FICHIER_H
#include <stdlib.h>
#include <stdio.h> 
int nombreDeLignes(FILE* fp);
char ** charger(FILE *fp, char **vecteur, int nbLignes, int nbColonnes);
#endif