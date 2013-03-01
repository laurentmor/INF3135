#include<stdio.h>


typedef struct {
char nom[30];
char prenom[30];
int code;
int numero;

} Personne ;


// retourne le nombre de chiffre dans un entier
int verif(int i)	{
	int nb = 0;
 	do	{
		nb++;
	} while((i /= 10) > 0);
	return nb;
}

Personne saisie( Personne P)
{

printf("donner votre nom \n");
scanf("%s",& P.nom);
printf("donner votre prenom \n");
scanf("%s",& P.prenom);
do {
printf("donner votre code regional suivit de votre numero \n");
scanf("%d",& P.code);
scanf("%d",& P.numero);
} while (verif(P.code)!=3 || verif(P.numero)!=7);

return P;
}

void ecrire_fichier(Personne P)
{

FILE *fp;
fp=fopen("fichier.txt","a+");
fprintf(fp,"%s %s %d %d",P.nom,P.prenom,P.code,P.numero);
fclose(fp);

}

int main()
{

Personne P;

P=saisie(P);
ecrire_fichier(P);
return 0;
}