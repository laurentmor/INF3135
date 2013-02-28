/* Exemple5.3.c : Structures */
#include <stdio.h>
#include <string.h>

struct adresse {
	char numero[7];
	char rue[30];
	int appt;
	char ville[30];
	char cp[8];
};

void affiche(struct adresse adr, char *s);
void change_ville(struct adresse adr);
void change_ville1(struct adresse *adr);

int main ()
{
	struct adresse adr1={"4400A", "St-Laurent", 3, "Montreal", "H0H 0H0"};
	struct adresse adr3;
	char adresse1[100], adresse3[100];

	adr3 = adr1;
	affiche(adr1, adresse1);
	affiche(adr3, adresse3);
	printf("Adresse1\n%sAdresse2\n%s", adresse1, adresse3);

	change_ville(adr3);
	affiche(adr3, adresse3);
	printf("Adresse1\n%sAdresse2\n%s", adresse1, adresse3);

	change_ville1(&adr3);
	affiche(adr1, adresse1);
	affiche(adr3, adresse3);
	printf("Adresse1\n%sAdresse2\n%s", adresse1, adresse3);
	return 0;
}

void affiche(struct adresse adr, char *s) {
	sprintf(s, "%s-%d %s\n%s %s\n", adr.numero, adr.appt, adr.rue, adr.ville, adr.cp);
}
void change_ville(struct adresse adr) {
	char temp[100];
	strcpy(adr.ville , "Quebec");
	affiche(adr, temp);
	printf("change_ville	%s",temp);
}
void change_ville1(struct adresse *adr) {
	strcpy(adr->ville , "Quebec");
}
