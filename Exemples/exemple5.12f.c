/* Exemple5.12f.c : somme de deux matrices de memes dimensions

Cas f : argument : float *a[]
	parametre : float *a[]
*/
#define NBCOLMAX 100
#define NBCOL 3
#define NBLIG 2
#include <stdio.h>

void additionne_matrices(float *a[], float b[][NBCOLMAX], float c[][NBCOLMAX], int nblig, int nbcol);

int main(){
	float *a[NBLIG], b[][NBCOLMAX] = {{1,1,1}, {1,1,1}};
	float c[NBLIG][NBCOLMAX];
	float alig1[] = {1,2,3};
	float alig2[] = {4,5,6};
	int i, j;

	a[0] = alig1;
	a[1] = alig2;

	additionne_matrices(a,b,c,NBLIG,NBCOL);

	for (i = 0; i < NBLIG; i++){
		for (j = 0; j < NBCOL; j++)
			printf("%10f ", c[i][j]);
		printf("\n");
	}
	return 0;
}

void additionne_matrices(float *a[], float b[][NBCOLMAX], float c[][NBCOLMAX], int nblig, int nbcol){
	int i, j;
	for (i = 0; i < nblig; i++)
		for (j = 0; j < nbcol; j++)
			c[i][j] = a[i][j] + b[i][j];
}
