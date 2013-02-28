/* Exemple5.13.c : calcul iteratif de la factorielle
d'un nombre passe en argument du programme 
Utilisation de float ** comme pointeur vers un pointeur (et non comme matrice) */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{	int i=1, n, f=1;
	char * reste;

	if (argc != 2) {
		printf ("Usage : fact n\n");	
		exit(-1);
	}

	/* Le pointeur est passe par adresse, car sa valeur va etre modifiee
	   par strtol */
	n = (int) strtol(argv[1], &reste, 10);
	if (*reste != '\0' || n < 0) {
		printf ("L'argument doit etre un entier positif\n");	
		printf ("Reste de la chaine : %s\n", reste);	
		exit(-2);
	}
	for (i = 1; i <= n; i++)
		f *= i;
	printf("La factorielle de %d est %d\n", n, f);
	return 0;
}


