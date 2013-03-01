#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int main (int argc, char *argv[], char *env[])
{
	char chaine[50], valeur[500];
	if (argc==1)
		return -1;
	strcpy(chaine, argv[1]);
	strcat(chaine,"=%s");
	while (*env != NULL) {
		
 		if (sscanf(*(env++), chaine, valeur)) {
			printf("La variable %s vaut %s\n", argv[1], valeur);
			return 0;
		}
		
	}
	fprintf (stderr, "La variable %s n'est pas definie\n", argv[1]);
	return 1;
}
