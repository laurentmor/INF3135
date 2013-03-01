#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define true 1
#define false 0


int main() {
	bool MOT=false;
        bool NON_MOT=true;
	int c_courant, recherche=0, nbmots = 0;

	while ((c_courant = getchar())!=EOF) {
		if (recherche == MOT && isalnum(c_courant)) {
			recherche = NON_MOT;
			nbmots++;
		}
		else if (recherche == NON_MOT && !isalnum(c_courant))
			recherche = MOT;
	}
	printf("%d mots ont ete lus \n", nbmots);
	return 0;
}

