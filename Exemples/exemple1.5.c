/* Exemple1.5.c : nombres de Fibonacci, version iterative */
#include <stdio.h>
#define NOMBRE_DE_NOMBRES 40

int main()
{
	unsigned i;
	int fibo, fibo_1=1, fibo_2=1;
	printf( "%d\n%d\n", fibo_2, fibo_1);
	for (i=2;i<=NOMBRE_DE_NOMBRES;i++) {
		fibo=fibo_1+fibo_2;
		printf("%d\n",fibo);
		fibo_2 = fibo_1;
		fibo_1 = fibo;
	}
	return 0;
}
