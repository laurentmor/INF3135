/* Exemple6.5.c : Listes generiques : utilisation d'un module de listes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exemple6.listes.h"
#define NB 10

void affiche_int(int *i, char *s);
void affiche_char(char *c, char *s);
 
int main ()
{
	int i;
	char *chaines[] = {"chaine1", "chaine2", "chaine3", "chaine4", "chaine5", "chaine6", "chaine7", "chaine8", "chaine9", "chaine10"}, *elementc;
	int vecteur[] = {1,2,3,4,5,6,7,8,9,10}, *elementi;
	Liste * liste1 = NULL; /* liste 1 est vide */
	Liste * liste2 = NULL; /* liste 2 est vide */

	/* Creation des listes */
	for (i=NB; i>0; i--){
		liste1 = insere_liste(liste1, chaines[i-1]);
		liste2 = insere_liste(liste2, &vecteur[i-1]);
	}

	affiche_liste(liste1, (void (*) (void *, char *)) affiche_char);
	affiche_liste(liste2, (void (*) (void *, char *)) affiche_int);

	/* Retrait des 5 premiers nombres */
	for (i=0; i<5; i++) {
		liste1 = retire_liste(liste1, (void *) &elementc);
		liste2 = retire_liste(liste2, (void *) &elementi);
		printf("Element %d retire de la liste d'entiers\n", *elementi);
		printf("Element %s retire de la liste de chaines\n", elementc);
	}

	affiche_liste(liste1, (void (*) (void *, char *)) affiche_char);
	affiche_liste(liste2, (void (*) (void *, char *)) affiche_int);

	return 0;
}

void affiche_int(int *i, char *s) {
	sprintf(s, "%d", *i);
}

void affiche_char(char *c, char *s) {
	strcpy(s,c);
}
