/* exemple7.2.c : utilisation d'assertions : contrat entre inverse et main 
 approche tolerante pour les pre-conditions */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define TAILLE 5
#ifndef PRECISION
#  define PRECISION 0.000001
#endif /* PRECISION */
#define MESSAGE_ERR_1 "inverse : l'argument doit etre different de 0"

double inverse (double x);

int main(int argc, char *argv[]){
	double arg, res;
	int i;
	for (i = 1; i < argc; i++) {
		arg = atof(argv[i]);
		res = inverse(arg);
		/* abs est definie dans stdlib.h */
		assert( abs(arg * res - 1) < PRECISION ); /* La post-condition doit etre satisfaite */
		printf("L'inverse de %f est %f\n", arg, res);
	}
	return 0;
}

double inverse (double x) {
	/* Gestion d'une pre-condition non satisfaite */
	if (x == 0){
		fprintf(stderr, "%s\n", MESSAGE_ERR_1);
		exit(1);
	}
	else
		return 1/x;
}
