/* Exemple6.1.c : Tableau dynamique de structures*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX_ADRESSE 255
#define TAILLE_INIT_TABLEAU 1
#define TAILLE_INCR_TABLEAU 10
#define NBMAX 50

typedef struct {
	char numero[7];
	char rue[30];
	int appt;
	char ville[30];
	char cp[8];
} Adresse;
typedef struct {
	char nom[30];
	char prenom[30];
	Adresse adr;
} Individu;
typedef char AffichageAdresse [TAILLE_MAX_ADRESSE] ;

void afficheadr(Individu * p, char *s);
Individu * insere_individus(Individu * p, Individu i);

static int nb_individus = 0;
static int taille = TAILLE_INIT_TABLEAU;
static Individu * individus; /* Declaration du "tableau" */

int main ()
{
	Individu personne1 ={"Tremblay", "Jean", {"4400A", "St-Laurent", 3, "Montreal", "H0H 0H0"}};
	AffichageAdresse adresse;
	int i;

	/* Allocation initiale */
	/* Il faudrait tester qu'elle reussit */
	individus= (Individu *) calloc(TAILLE_INIT_TABLEAU, sizeof(Individu));
	for (i=0; i<NBMAX; i++){
		individus = insere_individus(individus, personne1); /* individus peut changer de valeur suite a une reallocation */
		individus[i].adr.appt = i; /* Notation OK avec vecteurs ; NOK avec matrices (utiliser individus+nbcol*i+j->...) */
	}

	for (i=0; i<NBMAX; i++) {
		afficheadr(individus+i, adresse);
		printf("Adresse %d :\n%s", i, adresse);
	}

	return 0;
}

void afficheadr(Individu * p, char *s) {
	sprintf(s, "%s %s\n%s-%d %s\n%s %s\n", p->prenom, p->nom, p->adr.numero, p->adr.appt, p->adr.rue, p->adr.ville, p->adr.cp);
}

Individu * insere_individus(Individu * p, Individu individu) {
	if (nb_individus == taille){ /* Il ne reste plus de place */
		/* On multiplie la taille par 2 : heuristique courante qui a fait ses preuves
		   Converge rapidement vers la taille necessaire sans trop gaspiller d'espace (Braquelaire, 1998) */
		taille+=TAILLE_INCR_TABLEAU;
		printf("%d %p	", nb_individus, p);
		/* Reallocation : il faudrait tester qu'elle reussit */
		p = (Individu *) realloc(p, taille*sizeof(Individu));
		printf("%p\n",p);
	}
	*(p+nb_individus++) = individu;
	return p;
}

