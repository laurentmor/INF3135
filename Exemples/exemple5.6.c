/* Exemple5.6.c : union*/
#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 255

typedef struct {
	char numero[7];
	char rue[30];
	int appt;
	char ville[30];
	union {
		char cpCA[8];
		int cpIntl;
	} cp;
	char pays[20];
} Adresse;

typedef struct {
	char nom[30];
	char prenom[30];
	Adresse adr;
} Individu;

typedef char AffichageAdresse [TAILLE_MAX] ;

void afficheadr(const Individu * p, char *s);

int main() {
	Individu personne1 ={"Tremblay", "Jean", {"4400A", "St-Laurent", 3, "Montreal", {"H0H 0H0"}, "canada"}};
	/* Initialisation d'une union avec des donnees du premier type seulement 
	L'exemple ci-dessous ne fonctionne pas
	Individu personne2 ={"Clinton", "Bill", {"1", "Pennsylvania Av.", 0, "Washington",23943, "etats-unis"}}; 
	*/
	/* Approche paresseuse : on initialise avec une valeur bidon puis on reinitialise apres */
	Individu personne2 ={"Clinton", "Bill",  {"1", "Pennsylvania Av.", 0, "Washington", {""}, "etats-unis"}}; 
	AffichageAdresse adresse1, adresse2;

	personne2.adr.cp.cpIntl = 34214;
	afficheadr(&personne1, adresse1);
	afficheadr(&personne2, adresse2);
	printf("Adresse1\n%sAdresse2\n%s", adresse1, adresse2);
	return 0;
}

void afficheadr(const Individu * p, char *s) {
	if (!strcmp(p->adr.pays,"canada"))
		sprintf(s, "%s %s\n%s-%d %s\n%s %s\n%s\n", p->prenom, p->nom, 
			p->adr.numero, p->adr.appt, p->adr.rue, p->adr.ville, p->adr.cp.cpCA,
			p->adr.pays);
	else 
		sprintf(s, "%s %s\n%s-%d %s\n%d %s\n%s\n", p->prenom, p->nom, p
			->adr.numero, p->adr.appt, p->adr.rue, p->adr.cp.cpIntl, p->adr.ville,
			p->adr.pays);
}
