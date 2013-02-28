/* Exemple 2.4.c */
# include <stdio.h>
int calcule_somme(int a[], unsigned n);

int main ()
{
	int a[] = {1, 2, 3}, s = calcule_somme(a, 3);
	printf("a[0]=%d, a[1]=%d, a[2]=%d, somme = %d\n", a[0], a[1], a[2], s);
	return 0;
}

int calcule_somme (int a[], unsigned n) {
	int s = 0;
	while (n--) {
		s += a[n];
		a[n] = 0;
	}
	return s;
}
