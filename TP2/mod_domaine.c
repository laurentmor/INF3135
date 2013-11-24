#include "mod_domaine.h"
#include "mod_regex.h"
#include "mod_erreur.h"
#include <assert.h>
#include <string.h>
/**
 definition des type de domaines
*/
#define TOUTE_SYNTAXE_VALIDE "(^-{1}[0-9]+$){1}|(^[0-9]+-$)|(^[0-9]+-[0-9]+$)"
#define _NUM "(^-{1}[0-9]+$){1}"
#define NUM_ "(^[0-9]+-$)"
#define NUM1_NUM2 "(^[0-9]+-[0-9]+$)"  


int check(char *domaine){
	if (chercherDansChaine(TOUTE_SYNTAXE_VALIDE,domaine))
	{
		return 1;
	}
	signaler(SYNTAX_DOMAIN_ERREUR);
	return 0;
} 

int get_nbre_domaines(char  *const argv[], int pos){

}
int get_debut(char *domaine,int *debut){
	 assert(domaine!=NULL && "le domaine est obligatoire");
     assert(debut!=NULL   && "ECHEC d'une precondition - debut doit etre alloue hors fonction");
        
	if (chercherDansChaine(NUM_,domaine))
	{
		int longueur=strlen(domaine)+1;
        char * debutStr=malloc(longueur*sizeof(char));
        strncpy(debutStr,domaine,longueur-1);
        *debut=(int)atoi(debutStr);
        free(debutStr);
        return 1;

	}
	else{
		if (chercherDansChaine(NUM1_NUM2,domaine))
		{
			 int longueur=strlen(domaine)+1;
             char delimiteur[2]="-";
             /*On convertit la chaîne du domaine en tableau
             de maniere a  pouvoir utiliser strtok() pour la diviser correctement
             Sûrement pas la meilleur/plus sécuritaire façon de faire*/
             char domaineTab[longueur];
             strncpy(domaineTab,domaine,longueur);
             char * partie=strtok(domaineTab,delimiteur);
             *debut=(int)atoi(partie);
             return 1;
		}
		else{
			if (chercherDansChaine(_NUM,domaine))
			{
				*debut=0;
				return 1;
			}
		}
	}
	return 0;


}

int get_fin(char *domaine,int *fin,int max){
	assert(domaine!=NULL && "le domaine est obligatoire");
    assert(fin!=NULL   && "ECHEC d'une precondition - fin doit etre alloue hors fonction");
    if (chercherDansChaine(NUM_,domaine))
    {
    	*fin=(int)max;
    	return 1;
    }
    else{
    	if (chercherDansChaine(_NUM,domaine))
    	{
    		        int longueur=strlen(domaine)+1;
                    char * finStr=malloc(longueur*sizeof(char));
                    strncpy(finStr,domaine+1,longueur);
                    *fin=(int)atoi(finStr);
                    free(finStr);
                    return 1;


    	}
    	else{
    		if (chercherDansChaine(NUM1_NUM2,domaine))
    		{
    			int longueur=strlen(domaine)+1;
                char delimiteur[2]="-";
                  /*On convertit la chaîne du domaine en tableau
                    de maniere a  pouvoir utiliser strtok() pour la diviser correctement
                   Sûrement pas la meilleur/plus sécuritaire façon de faire*/
                   char domaineTab[longueur];
                   strncpy(domaineTab,domaine,longueur);
                   char * partie=strtok(domaineTab,delimiteur);
                   //On récupère la fin
                   partie=strtok(NULL,delimiteur);
                   *fin=(int)atoi(partie);
                   return 1;
    		}
    	}
    }
    return 0;

}