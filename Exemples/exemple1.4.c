/* Exemple1.4.c : nombres de Fibonacci, version recursive */
#include <stdio.h>
#define NOMBRE_DE_NOMBRES 40
unsigned fibonacci (unsigned n);

int main()
{
	unsigned i;
	for (i=0;i<=NOMBRE_DE_NOMBRES;i++) 
		printf("%d\n",fibonacci(i));
	return 0;
}
			
unsigned fibonacci(unsigned n) {
	switch(n) {
		case 0 :
		case 1 : return 1 ;
			 break;       /* Inutile ici a cause du return */
		default : return(fibonacci(n-1)+fibonacci(n-2));
	}
}
