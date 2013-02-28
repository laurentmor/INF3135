/* Exemple5.7.c Lecture sequentielle caractere par caractere */
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	FILE * fic;
	char nom_fichier[50];
	char car;

	if (argc != 2) {
		fprintf(stderr, "Usage : %s nom_fichier\n", argv[0]);
		return -1;
	}

	strcpy(nom_fichier,argv[1]);
	fic = fopen(nom_fichier, "r");
	while (fread(&car,sizeof(char),1,fic), !feof(fic))
		putchar(car);
	fclose(fic);
	return 0;
}

