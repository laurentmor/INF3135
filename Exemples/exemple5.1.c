/* Exemple5.1.c : acces a la ligne de commande */
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
	while (**argv != '\0')
		printf("%s\n", (*argv)++);
	
	while (*(++argv) != NULL)
		printf("%s\n", *argv);
	return 0;
}
