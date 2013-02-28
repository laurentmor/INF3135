/* Exemple5.2.c : tableaux a deux dimensions */
#include <stdio.h>
#define MAX 100
void somme_par_ligne (const int matrice[][MAX], int resultat[], unsigned nblignes, unsigned nbcolonnes);

int main ()
{
	const int toto[2][MAX] = {{1,2,3},{4,5,6}};
	int resultat[2];
	somme_par_ligne(toto,resultat,2,3);
	printf("somme ligne1 = %d, somme ligne2 = %d\n", resultat[0], resultat[1]);
	return 0;
}

void somme_par_ligne (const int matrice[][MAX], int resultat[], unsigned nblignes, unsigned nbcolonnes)
{
	unsigned i, j;
	for (i=0; i < nblignes; i++) {
		resultat[i] = 0;
		for (j=0; j < nbcolonnes; j++) 
			resultat[i] += matrice[i][j];
		
	}
	return;
}
