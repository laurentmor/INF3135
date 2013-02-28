/* Exemple2.14.c : intercalage d'une ligne vide entre chaque ligne lue
sur l'entree standard

Peut etre utilise dans un pipeline
Peut etre utilise avec les redirections pour convertir un fichier */

#include <stdio.h>
#include <stdlib.h>
#define TAILLE_LIGNE 30
char *getline(char *ligne, int taille);

int main() 
{	
	char ligne[TAILLE_LIGNE];

	while (getline(ligne, TAILLE_LIGNE) != NULL) 
		printf("%s\n",ligne);
	return 0;
}

char *getline(char *ligne, int taille)
{
	int c;
	/* taille correspond au nombre de caracteres max qu'il reste a ecrire */
	while ((c = getchar()) != EOF) {
		taille--;
		if (! taille) {
			if (c != '\n') 
				ungetc(c, stdin) ;
			*ligne = '\0';
			return ligne;
		}
		if (c == '\n') {
			*ligne = '\0';
			return (ligne);
		}
		*(ligne++) = c;
	}
	*(ligne)='\0';
	return(NULL);
}
