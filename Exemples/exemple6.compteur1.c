/* exemple6.compteur1.c : 1ere implementation des compteurs */
#include <stdio.h>
#include <stdlib.h>

#include "exemple6.compteur.h"
#define COMPTEUR_MESSAGE_ERR_PAS "Le pas doit etre different de 0. Le compteur n'est pas cree"
#define COMPTEUR_MESSAGE_ERR_MALLOC "Erreur d'allocation de memoire. Le compteur n'est pas cree"

void message_erreur_pas(void);
void message_erreur_malloc(void);

struct compteur{
	int valeur;
	int valeur_initiale;
	int pas;
};

Compteur compteur_creer(int valeur_initiale, int pas) {
	Compteur p = (Compteur) malloc(sizeof(struct compteur));
	if (p == NULL) {
		message_erreur_malloc();
	}
	else if (!pas) {
		p = NULL;
		message_erreur_pas();
	}
	else {
		p->valeur_initiale = p-> valeur = valeur_initiale;
		p->pas = pas;
	}
	return p;
}

int compteur_reinitialiser(Compteur p) {
	p->valeur = p->valeur_initiale;
	return p->valeur;
}

int compteur_prochaine_valeur(Compteur p) {
	p->valeur += p->pas;
	return p->valeur;
}

void compteur_supprimer(Compteur p) {
	free(p);
};

void message_erreur_pas(void) {
	fprintf(stderr,COMPTEUR_MESSAGE_ERR_PAS);
}

void message_erreur_malloc(void) {
	fprintf(stderr,COMPTEUR_MESSAGE_ERR_MALLOC);
}
