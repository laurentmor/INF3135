/* Exemple2.9.c
Affichage des arguments de la ligne de commande */

#include <stdio.h>

int main(int argc, char *argv[]) 
{	int i;
	printf("Valeur de argc : %d\n", argc);
	for (i = 0 ; i<argc ; i++)
		printf("Argument %d : %s\n",i, argv[i]);
	return 0;
}


