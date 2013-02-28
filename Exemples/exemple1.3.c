/* Exemple1.3.c : fonction puissance */
#include <stdio.h>
int puissance (int x, unsigned char n);

int main()
{
	int i; 
	unsigned char p;
	for (i=2;i<=12;i+=2) {
		printf("%d\t",i);
		for (p=2;p<=5;p++) 
			printf ("%d\t",puissance(i,p));
		printf("\n");
	}
	return 0;
}
			
int puissance(int x, unsigned char n) {
	int p=1; // Pas le même p que dans main()
	while (n-- > 0) 
		p*=x;
	return p;
}
