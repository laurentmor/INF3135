/* Exemple2.3.c : fonction echangeant 2 valeurs */
#include <stdio.h>

void echange_valeurs(int *a, int *b);

int main ()
{
	int a=5,b=6;
	echange_valeurs(&a,&b);
	printf("a=%d b=%d\n", a, b);
	return 0;
}

void echange_valeurs(int *a, int *b)  {
	int z = *a;
	*a=*b;
	*b=z;
}


