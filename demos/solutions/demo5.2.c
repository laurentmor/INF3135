#include<stdio.h>
#include<string.h>



typedef struct {
char nom[30];
char prenom[30];
char numero[30];

} Personne ;

void lire_fichier(Personne P)
{
  FILE *fp;
  int ligne=1;
 
  fp=fopen("fichier.txt","r");
   while (fscanf(fp,"%s %s %s",P.nom,P.prenom,P.numero)!=EOF)
  {
   
	if (P.numero[0]== '(' && P.numero[4]== ')' && P.numero[8]== '-' )
	
	  printf("%s %s %s \n",P.nom,P.prenom,P.numero );
	
	else
	
	 printf("A la ligne %d le Format (xxx)xxx-xxxx de votre numero de telephone est incorrect\n",ligne);
     
     ligne++;
 
  }
  fclose(fp);

}

int main()
{
Personne P;
lire_fichier(P);
return 0;
}