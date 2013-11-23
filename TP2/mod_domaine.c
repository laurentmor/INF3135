#include "mod_domaine.h"
#include "mod_regex.h"
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
	// Signaler les erreurs
	return 0;
} 