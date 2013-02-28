/* exemple7.1.c : utilisation d'assertions : contrat entre inverse et main 
approche exigeante pour les pre-conditions */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
  #define TAILLE 5
  #ifndef PRECISION
  #  define PRECISION 0.00000001
  #endif /* PRECISION */

double inverse (double x);

int main(void){
	double a[TAILLE]= { 1.0, 4.0,  -3.0, 0.0, 2.5}, res;
	int i;
	
	for (i = 0; i < TAILLE; i++) {
		res = inverse(a[i]);
		/* abs est definie dans stdlib.h */
		assert( abs(a[i] * res - 1) < PRECISION && "Post-condition non respectee"); /* La post-condition doit etre satisfaite */
		printf("L'inverse de %f est %f\n", a[i], res);
	}
	return 0;
}

double inverse (double x) {
	assert (x != 0 && "Pre-condition non OK"); /* La pre-condition doit etre satisfaite */
	return 1/x;
}
