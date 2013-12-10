//NOM et Prénom : Morissette, Laurent
//Code permanent : MORL05058301
//antoine boutros
//BOUA06099209

#include "mod_fichier.h"
#include "mod_erreur.h"
#include <stdlib.h>
#include <stdio.h>
int compteur_Lignes(char ** vecteur, int nbL);
/**
 Retourne le nombre de lignes à ne pas inclure dans le vecteur
 */
int compteur_Lignes(char ** vecteur, int nbL) {
    int nb = 0;
    int i = 0;
    for (; i < nbL; i++) {
        if (vecteur[i] != 0) {
            nb++;
        }
    }
    return nb;
}
int nombreDeLignes(FILE* fp){
int nombreLigne = 0;
    int caract;
    while ((caract = fgetc(fp)) != EOF) {
        if (caract == '\n') {
            nombreLigne++;
        }
    }
    if (nombreLigne == 0) {
        signaler(FICHIER_SANS_DONNEE_ERREUR);
    }
    rewind(fp);
    return nombreLigne;
}
char ** charger(FILE *fp, char **vecteur, int nbLignes, int nbColonnes){
	int nbL2 = 0;
	nbL2 = compteur_Lignes(vecteur, nbLignes);
	char **ptr_vecteur = malloc(3*nbL2 * sizeof (char *));
	char *(*lignePtr)[nbColonnes] = malloc(3*nbColonnes * sizeof (char *));
	lignePtr = (char(**)[nbColonnes]) ptr_vecteur;

	
	
	
	int x = 0;
	rewind(fp);
	int tab = 0;
	int i = 0;
	int j = 0;
	for (; i < nbLignes; i++) {
	    if (vecteur[i] == 0) {
	        continue;
	    }
	    for (; j < vecteur[i]; j++) {
	        fscanf(fp, "%d", &x);
	        lignePtr[tab][j] = x;
	    }
	    tab++;
	}
	return ptr_vecteur;
}