/* Exemple2.10.c : calcul iteratif de la factorielle
d'un nombre passe en argument du programme */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{	int i=1, n, f=1;

	printf("%s\n",argv[0]);
	if (argc != 2) {
		fprintf(stderr, "Usage: %s entier-positif\n",argv[0]); 	
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0) {
		fprintf(stderr, "Usage: %s entier-positif\n",argv[0]); 	
		exit(2);
	}
	for (i = 1; i <= n; i++)
		f *= i;
	printf("La factorielle de %d est %d\n", n, f);
	/* la ligne precedente equivaut a
	fprintf(stdout,"La factorielle de %d est %d\n", n, f);
	*/
	return 0;
}


