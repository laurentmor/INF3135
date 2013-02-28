/* Exemple5.9.c Acces direct */
#include <stdio.h>
void affiche (FILE * fic, int pos, int nbelem, int a[]);

int main() {
	FILE * fic;
	char nom_fichier[] = "./test";
	int a[2], b[10];

	fic = fopen(nom_fichier, "r+");
	affiche(fic, 1, 10, b);	

	affiche(fic, 5, 2, a);	

	fseek(fic, sizeof(int) * 2, SEEK_SET); 
	fwrite(a, sizeof(int), 2, fic);

	affiche(fic, 1, 10, b);	
	fclose(fic);
	return 0;
}

void affiche (FILE * fic, int pos, int nbelem, int a[]) {
	int i;
	fseek(fic, sizeof(int) * (pos - 1), SEEK_SET);
	fread(a, sizeof(int), nbelem, fic);
	printf ("Les %d elements a partir du rang %d sont\n", nbelem, pos);
	for (i = 0; i< nbelem; i++) {
		printf ("%d\n", a[i]);
	}
}
