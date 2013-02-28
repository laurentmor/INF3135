/* Exemple6.listesABS.c : Module de listes generiques - type abstrait */
#include <stdio.h>
#include <stdlib.h>
#include "exemple6.listesABS.h"

struct liste {
	void *tete;
	struct liste *queue;
};
typedef struct liste s_liste;

Liste cree_liste(void){
	return NULL;
}

Liste insere_liste(Liste l, void * element) {
	Liste p_aux;
	p_aux = (Liste) malloc(sizeof(s_liste));
	if (p_aux) {
		p_aux -> tete = element;
		p_aux -> queue = l;
	}
	return p_aux;
}

void affiche_liste(Liste l, void (*affiche)(void *, char *)) {
	char s[TAILLEMAXELT];
	for (; l != NULL; l = l->queue) {
		(*affiche)(l->tete, s);
		printf("%p %s   ", l, s);
	}
	printf("\n");
}

Liste retire_liste(Liste l, void **element) {
	Liste reste;
	if (l != NULL) {
		*element = l->tete;
		reste = l->queue;
		free(l);
		return reste;
	}
	else 
		return NULL;
}

