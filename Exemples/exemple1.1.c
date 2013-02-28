/* Exemple1.1.c */
#include <stdio.h>	/* Directives au préprocesseur */
#define DEBUT 02		/* Constantes comme symboles du préprocesseur*/
#define FIN 20	

unsigned fact(unsigned x);	/* Déclaration de la fonction fact */

int main () {			/* Fonction principale */
	int i;			/* Déclaration des variables locales à la fonction */

	for (i=DEBUT; i<=FIN; i++) {
		printf("%d a pour factorielle %d\n",i,fact(i));
	}
	return 0;
}

unsigned fact(unsigned x) {		/* Calcule la factorielle de x*/
	if (x==0) 
		return 1;		/* Tous les cas sont-ils testés ? */
	else 
		return x*fact(x-1);	/* Appel récursif de la fonction */
}
