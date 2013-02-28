/* Exemple6.6.c : Listes generiques : utilisation d'un module de listes ; type abstrait */
#include <stdio.h>
#include "liblistes.h"
#define NB 10

void affiche_int(int *i, char *s);
 
main (int argc, char *argv[])
{
	int i;
	int vecteur[] = {1,2,3,4,5,6,7,8,9,10};
	int *elementi;
	p_liste liste1 = NULL, liste2 = NULL; 

	/* Creation des listes */
	for (i=NB; i>0; i--)
		liste1 = insere_liste(liste1, &vecteur[i-1]);

	for (i=0; i<NB; i++)
		liste2 = insere_liste(liste2, &vecteur[i]);

	affiche_liste(liste1, (void (*) (void *, char *)) affiche_int);
	affiche_liste(liste2, (void (*) (void *, char *)) affiche_int);

	/* Retrait des 5 premiers nombres */
	for (i=0; i<5; i++) {
		liste1 = retire_liste(liste1, elementi);
		liste2 = retire_liste(liste2, elementi);
	}

	affiche_liste(liste1, (void (*) (void *, char *)) affiche_int);
	affiche_liste(liste2, (void (*) (void *, char *)) affiche_int);
}

void affiche_int(int *i, char *s) {
	sprintf(s, "%d", *i);
}
