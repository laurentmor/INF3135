/* Exemple2.1.c : produit scalaire de deux vecteurs de float */
#include <stdio.h>
float produit_scalaire (float a[], const float b[], unsigned taille);

int main()
{
	float toto[]={1.0,2.0,-0.5};
	float titi[]={3.0,0.5,1.0};
	printf("Produit : %f\n",produit_scalaire(toto,titi,3));
//	printf("toto[0] : %f\n",toto[0]);
	return 0;
}
			
float produit_scalaire (float a[], const float b[], unsigned taille){
	float produit = 0.0;
//	a[0]=0.0;
	while(taille--)
		produit += a[taille] * b[taille];
	return produit ;
}
