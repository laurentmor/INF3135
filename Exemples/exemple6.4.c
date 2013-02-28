/* Exemple6.4.c : Listes generiques */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NB 10
#define TAILLEMAXELT 10

struct liste {
	void *tete;
	struct liste *queue;
};

typedef struct liste Liste;

Liste * insere_liste(Liste * l, void *s);
void affiche_liste(Liste * l, void (*affiche) (void *, char *));
Liste * retire_liste(Liste * l, void **s);

void affiche_int(int *, char *);
void affiche_char(char *, char *);
 
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

	/* Retrait des 5 premiers elements */
	for (i=0; i<5; i++) {
		liste1 = retire_liste(liste1, (void **) &elementc);
		liste2 = retire_liste(liste2, (void **) &elementi);
		printf ("Element %d retire de la liste d'entiers\n", *elementi);
		printf ("Element %s retire de la liste de chaines\n", elementc);
	}

	affiche_liste(liste1, (void (*) (void *, char *)) affiche_char);
	affiche_liste(liste2, (void (*) (void *, char *)) affiche_int);
	return 0;
}

Liste * insere_liste(Liste * l, void * element) {
	Liste * p_aux;
	p_aux = (Liste *) malloc(sizeof(Liste));
	if (p_aux) {
		p_aux -> tete = element;
		p_aux -> queue = l;
	}
	return p_aux;
}

void affiche_liste(Liste * l, void (*affiche)(void *, char *)) {
	char s[TAILLEMAXELT];
	for (; l != NULL; l = l->queue) {
		(*affiche)(l->tete, s);
		printf("%p %s   ", l, s);
	}
	printf("\n");
}

Liste * retire_liste(Liste * l, void **element) {
	Liste * reste;
	if (l != NULL) {
		*element = l->tete;
		reste = l->queue;
		free(l);
		return reste;
	}
	else 
		return NULL;
}

void affiche_int(int *i, char *s) {
	sprintf(s, "%d", *i);
}

void affiche_char(char *c, char *s) {
	strcpy(s,c);
}
