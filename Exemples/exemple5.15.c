/* Exemple5.15.c : somme de deux vecteurs : comparer avec exemple2.6.c */

#include <stdio.h>
#include <stdlib.h>
float* somme_vecteurs (const float a[], const float b[], unsigned taille);

int main()
{
	float toto[]={1.0,2.0,-0.5}, titi[]={3.0,0.5,1.0};
	float * res;
	res = somme_vecteurs(toto,titi,3);
	printf("Somme : %f %f %f\n",res[0],res[1],res[2]);
	free(res);
	return 0;
}
			
float* somme_vecteurs (const float a[], const float b[], unsigned taille){
	float *res = (float *) malloc(taille * sizeof(float));
	while(taille--)
		res[taille] = a[taille] + b[taille];
	return res;
}
