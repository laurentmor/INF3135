/* exemple6.7.c : utilisation de la fonction compteur */
#include <stdio.h>
#include "exemple6.compteur.h"
#define VAL_DEPART_NUM 0
#define VAL_MAX_NUM 9
#define VAL_DEPART_LETTRE 'A'
#define VAL_MAX_LETTRE 'Z'

int main(void) {
	Compteur c1, c2, c3;
	int i=VAL_DEPART_NUM, j=VAL_DEPART_LETTRE, k=VAL_DEPART_LETTRE;

	c1 = compteur_creer(i, 1);
	c2 = compteur_creer(j, 1);
	c3 = compteur_creer(k, 1);

	while(k <='B') {
		do {
			do {
				printf("%c%c%d ",k, j, i);
				i = compteur_prochaine_valeur(c1);
			} while (i <= VAL_MAX_NUM);
			i = compteur_reinitialiser(c1);
			j = compteur_prochaine_valeur(c2);
		} while (j <= VAL_MAX_LETTRE);
		j = compteur_reinitialiser(c2);
		k = compteur_prochaine_valeur(c3);
	}

	compteur_supprimer(c1);
	compteur_supprimer(c2);
	compteur_supprimer(c3);
	return 0;
}
