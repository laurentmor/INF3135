/* Exemple5.12b.c : somme de deux matrices de memes dimensions

Cas b : argument : float a[][5]
	parametre : float a[][NBCOLMAX]
*/
#define NBCOLMAX 100
#define NBCOL 3
#define NBLIG 2
#include <stdio.h>

void additionne_matrices(float a[][NBCOLMAX], float b[][NBCOLMAX], float c[][NBCOLMAX], int nblig, int nbcol);

int main(){
	float a[][5] = {{1,2,3},{4,5,6}}, b[][NBCOLMAX] = {{1,1,1}, {1,1,1}};
	float c[NBLIG][NBCOLMAX];
	int i, j;

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
