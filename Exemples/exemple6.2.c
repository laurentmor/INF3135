/* Exemple6.2.c : Listes d'entiers */
#include <stdio.h>
#include <stdlib.h>
#define NB 10

struct liste {
	int tete;
	struct liste * queue;
};

typedef struct liste Liste;

Liste * insere_liste(Liste * l, int element);
void affiche_liste(Liste * l);
Liste * retire_liste(Liste * l, int *element);
 
int main ()
{
	int i, element;
	Liste * liste1 = NULL; /* liste 1 est vide */

	/* Creation d'une liste */
	for (i=NB; i>0; i--){
		liste1 = insere_liste(liste1, i);
	}

	affiche_liste(liste1);

	/* Retrait des 5 premiers elements */
	for (i=0; i<5; i++) {
		liste1 = retire_liste(liste1, &element);
		printf("Element %d retire\n", element);
	}

	affiche_liste(liste1);
	return 0;
}

Liste * insere_liste(Liste * l, int element) {
	Liste * p_aux;
	p_aux = (Liste *) malloc(sizeof(Liste));
	if (p_aux) {
		p_aux -> tete = element;
		p_aux -> queue = l;
	}
	return p_aux;
}

void affiche_liste(Liste * l) {
	for (; l != NULL; l = l->queue) {
		printf("%p %d   ", l, l->tete);
	}
	printf("\n");
}

Liste * retire_liste(Liste * l, int *element) {
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
