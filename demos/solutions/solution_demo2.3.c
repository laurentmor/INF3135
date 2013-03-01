#include <stdio.h>

void affiche_vecteur_int(int a[], int taille);
void inverse(int a[], int taille);
void echange(int *a, int *b);

int main(){
	int tab1[5] = {1,2,3,4,5};
	int taille1 = 5;

	int tab2[5] = {2,3,4,5};
	int taille2 = 4;
	
	int tab3[5] = {};
	int taille3 = 0;
	
	affiche_vecteur_int(tab1, taille1);
	inverse(tab1, taille1);
	affiche_vecteur_int(tab1, taille1);
	
	printf("\n");

	affiche_vecteur_int(tab2, taille2);
	inverse(tab2, taille2);
	affiche_vecteur_int(tab2, taille2);
	
	printf("\n");
	
	affiche_vecteur_int(tab3, taille3);
	inverse(tab3, taille3);
	affiche_vecteur_int(tab3, taille3);
	
	return 0;
}

void inverse(int a[], int taille){
	int i = 0;
	
	for( ; (i < taille / 2) ; i++){
		echange(a+i, a+(taille-1-i) );
	}
}

void echange(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;	
}

void affiche_vecteur_int(int a[], int taille){
	int i = 0;
	printf("contenu du vecteur: ");
	
	for( ; i < taille ; i++){
		printf("%4d", a[i]);
	}
	
	printf("\n");
}
