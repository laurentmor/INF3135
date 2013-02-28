/* Exemple5.5.c : Structures et typedef*/
#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 255

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

typedef char AffichageAdresse [TAILLE_MAX] ;

void afficheadr(Individu * p, char *s);
int colocataires(Individu * p1, Individu * p2);

int main ()
{
	Individu personne1 ={"Tremblay", "Jean",  {"4400A", "St-Laurent", 3, "Montreal", "H0H 0H0"}};
	Individu personne2; 
	AffichageAdresse adresse1, adresse2;

	strcpy(personne2.nom, "Gagnon");
	strcpy(personne2.prenom, "Jacques");
	personne2.adr = personne1.adr;

	afficheadr(&personne1, adresse1);
	afficheadr(&personne2, adresse2);
	printf("Adresse1\n%sAdresse2\n%s", adresse1, adresse2);
	if (colocataires(&personne1, &personne2)) {
		printf("%s %s et %s %s sont colocataires\n", personne1.prenom, personne1.nom, personne2.prenom, personne2.nom);
	}
	return 0;

}

void afficheadr(Individu * p, char *s) {
	sprintf(s, "%s %s\n%s-%d %s\n%s %s\n", p->prenom, p->nom, p->adr.numero, p->adr.appt, p->adr.rue, p->adr.ville, p->adr.cp);
}
int colocataires(Individu * p1, Individu * p2) {
	return (p1->adr.appt==p2->adr.appt && 
		!(strcmp(p1->adr.numero,p2->adr.numero) ||
		  strcmp(p1->adr.rue, p2->adr.rue)|| 
		  strcmp(p1->adr.ville, p2->adr.ville)||
		  strcmp(p1->adr.cp, p2->adr.cp)));
}

