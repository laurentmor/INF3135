/* Exemple5.11.c : Fonction en parametre et typage generique */
#include <stdio.h>
#include <ctype.h>

int nbElemCond(int (* f)(void *), void *p, int nbElem, int taille);
int isEven(int *a);
int isLettre(char *a);

int main ()
{
	int a[] = {56721, 22, 122, 1145, 988};
	char chaine[] = "Bonjour ! Comment ca va ???"; 
	int res1, res2;

	res1=nbElemCond( (int (*) (void *)) isEven, (void *) a, sizeof(a)/sizeof(int), sizeof(int)); 
	printf("Il y a %d nombres pairs dans le tableau\n", res1);
	res2=nbElemCond( (int (*) (void *)) isLettre, (void *) chaine, sizeof(chaine)/sizeof(char), sizeof(char)); 
	printf("Il y a %d lettres dans %s\n", res2, chaine);
	return 0;
}

int nbElemCond(int (* f)(void *), void *p, int nbElem, int taille){
	int i, j=0;
	for (i=0; i<nbElem; i++) 
		if ((*f)(p+i*taille)) 
			j++;
	return j;
}
			
int isEven(int *a){
	return (*a % 2 == 0);
}

int isLettre(char *a){
	return (isalpha((int) *a));
}
