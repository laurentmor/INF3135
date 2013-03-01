#include <stdio.h>
#include <limits.h>

void affiche_vecteur_int(int a[], int taille);
void minmax(int a[], int taille);


int main(){
	int tab1[] = {4, 2, 87, 1, -5, 8, 67};
	int taille1 = 7;
	
	affiche_vecteur_int(tab1, taille1);
	minmax(tab1, taille1);	
	
	return 0;
}

void affiche_vecteur_int(int a[], int taille){
	int i = 0;
	printf("contenu du vecteur: ");
	
	for( ; i < taille ; i++){
		printf("%4d", a[i]);
	}
	
	printf("\n");
}

void minmax(int a[], int taille){
	int 	min, max, i;
	
	if (taille <= 0){
		printf("Erreur: tableau vide!\n");
	} else{
		min = a[0];
		max = a[0];
		
		for (i = 1 ; i < taille ; i++){
			if (a[i] < min){
				min = a[i];
			}
			if (a[i] > max){
				max = a[i];
			}
		}
		
		printf("Min: %d\tMax: %d\n", min, max);
	}
}
