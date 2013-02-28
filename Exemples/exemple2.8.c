/* Exemple2.8.c : produit scalaire de deux vecteurs de float */
/*                exemple avec variable statique (INCORRECT) */

#include <stdio.h>
float produit_scalaire (float a[], float b[], unsigned taille);

int main()
{
	float toto[]={1.0,2.0,-0.5}, titi[]={3.0,0.5,1.0};
	printf("Produit : %f\n",produit_scalaire(toto,titi,3));
	printf("Produit : %f\n",produit_scalaire(toto,titi,3));
	printf("Produit : %f\n",produit_scalaire(toto,titi,3));
	return 0;
}
			
float produit_scalaire (float a[], float b[], unsigned taille){
	static float produit = 1 ;
	printf("%f\n",produit);
	while(taille--)
		produit += a[taille] * b[taille];
	return produit;
}
