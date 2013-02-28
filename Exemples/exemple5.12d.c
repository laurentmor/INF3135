/* Exemple5.12d.c : somme de deux matrices de memes dimensions

Cas d : argument : float **a
	parametre : float a[][NBCOLMAX]
*/
#define NBCOLMAX 100
#define NBCOL 3
#define NBLIG 2
#include <stdio.h>
#include <stdlib.h>

void additionne_matrices(float a[][NBCOLMAX], float b[][NBCOLMAX], float c[][NBCOLMAX], int nblig, int nbcol);

int main(){
	float **a, b[][NBCOLMAX] = {{1,1,1}, {1,1,1}};
	float c[NBLIG][NBCOLMAX];
	float alig0[] = {1,2,3};
	float alig1[] = {4,5,6};

	int i, j;

	a = (float **) malloc (NBLIG * sizeof(float *));
	a[0] = alig0;
	a[1] = alig1;

	additionne_matrices(a,b,c,NBLIG,NBCOL);

	for (i = 0; i < NBLIG; i++){
		for (j = 0; j < NBCOL; j++)
			printf("%10f ", c[i][j]);
		printf("\n");
	}
	return 0;
}

void additionne_matrices(float a[][NBCOLMAX], float b[][NBCOLMAX], float c[][NBCOLMAX], int nblig, int nbcol){
	int i, j;
	for (i = 0; i < nblig; i++)
		for (j = 0; j < nbcol; j++)
			c[i][j] = a[i][j] + b[i][j];
}
