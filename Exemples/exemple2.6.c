/* Exemple2.6.c : somme de deux vecteurs : le resultat est passe en argument */

#include <stdio.h>
void somme_vecteurs (const float a[], const float b[], float res[], unsigned taille);

int main()
{
	float toto[]={1.0,2.0,-0.5}, titi[]={3.0,0.5,1.0}, res[3];
	somme_vecteurs(toto,titi,res,3);
	printf("Somme : %f %f %f\n",res[0],res[1],res[2]);
	return 0;
}
			
void somme_vecteurs (const float a[], const float b[], float res[], unsigned taille){
	while(taille--)
		res[taille] = a[taille] + b[taille];

	return;
}
