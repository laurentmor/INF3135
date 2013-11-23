#include "mod_domaine.h"
#include "mod_regex.h"
int check(char *domaine){
	if (chercherDansChaine(TOUTE_SYNTAXE_VALIDE,domaine))
	{
		return 1;
	}
	// Signaler les erreurs
	return 0;
} 