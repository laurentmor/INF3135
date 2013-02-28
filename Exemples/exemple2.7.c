/* Exemple2.7.c : Variables globales */
#include <stdio.h>

int k=5;
int bidon(int a);
int bidon1(int a);

int main ()
{
	int i=k;
	printf ("i=%d, k=%d, bidon(i)=%d, bidon1(i)=%d\n", i, k, bidon(i), bidon1(i));
	{
		int k = 10;
		printf ("i=%d, k=%d, bidon(i)=%d, bidon1(i)=%d\n", i, k, bidon(i), bidon1(i));
	}
	return 0;
}

int bidon(int a) {
	int k=100;
	return a+k;
}

int bidon1(int a) {
	return(a+k);
}
