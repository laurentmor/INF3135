#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	int minimum = INT_MAX, maximum = INT_MIN, entier_courant, i;
	if (argc == 1) {
		printf ("Liste vide : pas de maximum ni de minimum\n");
		return 1;
	}
	for (i = 2; i <= argc; i++) {
		entier_courant = atoi(argv[i-1]);
		minimum = (entier_courant < minimum ? entier_courant : minimum);
		maximum = (entier_courant > maximum ? entier_courant : maximum);
	}
	printf("Le minimum de la liste est %d, son maximum est %d\n", minimum, maximum);
	return 0;
}
