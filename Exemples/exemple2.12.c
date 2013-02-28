/* Exemple2.12.c : conversion des minuscules 
envoyees a l'entree standard en majuscules 

Peut etre utilise dans un pipeline
Peut etre utilise avec les redirections pour convertir un fichier */

#include <stdio.h>
#include <ctype.h>

int main() 
{	int c;

	while ((c = getchar()) != EOF)
		putchar(toupper(c));
	return 0;
}


