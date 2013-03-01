#include <stdio.h>
#include <limits.h>
#include "include/demo2.h"

calcule(int operande1, int operande2, char operateur) {
    switch (operateur) {
        case '+': return operande1 + operande2;
        case '-': return operande1 - operande2;
        case '*': return operande1*operande2;
        case '/': return operande1 / operande2;
        default: fprintf(stderr, "eeror");
    }
    return 0;
}

void minMax(int entiers[]) {
    int i;
    int min = 0;
    int max = 0;

    


}
void inverse(int a[], int taille){
    int i=0;
    for(;i<(taille/2);i++){
        echange(a+i,a+(taille-1-i));
    }
}
void echange(int* i, int* j){
    int temp= *i;
    *i=*j;
    *j=temp;
            
    
}
void affiche_vecteur_int(int a[], int taille){
	int i = 0;
	printf("contenu du vecteur: ");
	
	for( ; i < taille ; i++){
		printf("%4d", a[i]);
	}
	
	printf("\n");
}