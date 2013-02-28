/* Exemple5.14.c : acces aux variables d'environnement */
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[], char *env[])
{
	while (*env != NULL)
		printf("%s\n", *(env++));
	return 0;
}
