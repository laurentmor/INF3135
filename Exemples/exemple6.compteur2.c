/* exemple6.compteur2.c : 2eme implementation des compteurs */
#include <stdlib.h>
#include <stdio.h>

#include "exemple6.compteur.h"
#define COMPTEUR_MESSAGE_ERR_PAS "Le pas doit etre different de 0. Le compteur n'est pas cree"
#define COMPTEUR_MESSAGE_ERR_MALLOC "Erreur d'allocation de memoire. Le compteur n'est pas cree"

void message_erreur_tutu(void);
void message_erreur_malloc(void);

struct compteur{
	int toto;
	int titi;
	int tutu;
};

Compteur compteur_creer(int titi, int tutu) {
	Compteur p = (Compteur) malloc(sizeof(struct compteur));
	if (p == NULL) {
		message_erreur_malloc();
	}
	else if (!tutu) {
		p = NULL;
		message_erreur_tutu();
	}
	else {
		p->titi = p-> toto = titi;
		p->tutu = tutu;
	}
	return p;
}

int compteur_reinitialiser(Compteur p) {
	p->toto = p->titi;
	return p->toto;
}

int compteur_prochaine_valeur(Compteur p) {
	p->toto += p->tutu;
	return p->toto;
}

void compteur_supprimer(Compteur p) {
	free(p);
};

void message_erreur_tutu(void) {
	fprintf(stderr,COMPTEUR_MESSAGE_ERR_PAS);
}

void message_erreur_malloc(void) {
	fprintf(stderr,COMPTEUR_MESSAGE_ERR_MALLOC);
}
