#include <stdio.h>
#include <stdlib.h>
#define TAILLEA 5
#define TAILLEB 4
#define TAILLEC 0
#define TAILLED 1

void affiche_vecteur_int(int a[], int taille);
void echange(int *a, int *b);
int inverse(int a[], int taille);

int main() {
	/* Cas de tests standard : distinguer nombre d'elements pair et impair */
	int a[TAILLEA] = {1, 2, 3, 4, 5};
	int b[TAILLEB] = {1, 2, 3, 4};
	/* Cas limites : vecteur vide, vecteur avec un seul element */
	int c[TAILLEC] = {};
	int d[TAILLED] = {1};

	int nb_appels_inverse = 0;
	
	/* La meme section se repete 4 fois. On aurait pu ecrire une fonction teste_inverse
	   plutot que de repeter le meme code. */
	printf("Vecteur a : ");
	affiche_vecteur_int(a, TAILLEA);
	printf("Vecteur a inverse : ");
	nb_appels_inverse = inverse(a, TAILLEA);
	affiche_vecteur_int(a, TAILLEA);
	printf("Nombre d'appels a inverse : %d\n", nb_appels_inverse);

	printf("Vecteur b : ");
	affiche_vecteur_int(b, TAILLEB);
	printf("Vecteur b inverse : ");
	nb_appels_inverse = inverse(b, TAILLEB);
	affiche_vecteur_int(b, TAILLEB);
	printf("Nombre d'appels a inverse : %d\n", nb_appels_inverse);

	printf("Vecteur c : ");
	affiche_vecteur_int(c, TAILLEC);
	printf("Vecteur c inverse : ");
	nb_appels_inverse = inverse(c, TAILLEC);
	affiche_vecteur_int(c, TAILLEC);
	printf("Nombre d'appels a inverse : %d\n", nb_appels_inverse);

	printf("Vecteur d : ");
	affiche_vecteur_int(d, TAILLED);
	printf("Vecteur d inverse : ");
	nb_appels_inverse = inverse(d, TAILLED);
	affiche_vecteur_int(d, TAILLED);
	printf("Nombre d'appels a inverse : %d\n", nb_appels_inverse);

	return 0;
}

void affiche_vecteur_int(int a[], int taille) {
	int i;

	for (i = 0; i<taille; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

void echange(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int inverse(int a[], int taille) {
	static int nb_appels = 0;
	int i;

	for (i = 0; i<taille/2; i++)
		echange(&a[i], &a[taille-i-1]);
	return(++nb_appels);
}
	
