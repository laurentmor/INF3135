/* Exemple5.8.c Ecriture sequentielle */
#include <stdio.h>
int main() {
	FILE * fic;
	char nom_fichier[] = "test";
	int a[] = {100, 102, 103, 104, 105, 106, 107, 108, 109, 110};

	fic = fopen(nom_fichier, "w");
	fwrite(a,sizeof(int),sizeof a/sizeof(int),fic);
	fclose(fic);
	return 0;
}
