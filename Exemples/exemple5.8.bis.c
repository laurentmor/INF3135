/* Exemple5.7.c Lecture sequentielle entier par entier */
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
	FILE * fic;
	char nom_fichier[50];
	int entier;

	if (argc != 2) {
		fprintf(stderr, "Usage : %s nom_fichier\n", argv[0]);
		return -1;
	}

	strcpy(nom_fichier,argv[1]);
	fic = fopen(nom_fichier, "r");
	while (fread(&entier,sizeof(int),1,fic), !feof(fic))
		printf("%d ",entier);
	fclose(fic);
	return 0;
}

