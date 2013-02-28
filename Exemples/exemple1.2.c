/* Exemple1.2.c : portee des variables locales */
#include <stdio.h>

int main ()
{
	int i=0, j=100;
	printf ("i vaut %d, j vaut %d\n", i, j);
	if (i<j) {
		int i = 5;
		printf ("i vaut %d, j vaut %d\n", i, j);
	}
	{
		int j = 10;
		printf ("i vaut %d, j vaut %d\n", i, j);
	}
	printf ("i vaut %d, j vaut %d\n", i, j);
	return 0;
}
