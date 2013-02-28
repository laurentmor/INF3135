/* Exemple2.11.c : calcul iteratif de la factorielle
d'un nombre passe en argument du programme */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{	long i=1, n, f=1;
	char * finNombre;

	if (argc != 2) {
		fprintf(stderr,"Usage: %s entier-positif\n", argv[0]); 	
		exit(-1);
	}
	n = strtol(argv[1], &finNombre, 10);
	if (n < 0 || *finNombre != '\0'){
		fprintf(stderr,"Usage: %s entier-positif\n", argv[0]); 	
		exit(-2);
	}
	for (i = 1; i <= n; i++)
		f *= i;
	printf("La factorielle de %ld est %ld\n", n, f);
	return 0;
}


