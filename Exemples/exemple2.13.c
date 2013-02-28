/* Exemple2.13.c : decompte du nombre de lignes sur l'entree standard

Peut etre utilise dans un pipeline
Peut etre utilise avec les redirections pour convertir un fichier */

#include <stdio.h>
#include <stdlib.h>

int main() 
{	int nblignes=0;
	char ligne[128];

	while (gets(ligne) != NULL)  /* OU while (gets(ligne)) */
		nblignes++;
	printf("%d lignes lues\n",nblignes);
	return 0;
}


