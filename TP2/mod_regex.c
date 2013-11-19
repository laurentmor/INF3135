#include "mod_regex.h"

int valider(char *expression, regex_t regPtr) ;
int valider(char *expression, regex_t regPtr ){
	if (expression==NULL)
	{
		return REGEX_INVALIDE;
	}
	int erreur=regcomp(&regPtr,expr,REG_NOSUB | REG_EXTENDED);
	if (erreur==0) return REGEX_VALIDE;
	regfree(&regPtr);
	return REGEX_INVALIDE;
	
			
}

int chercherDansChaine(char *expression, char *chaine){
	regex_t regPtr;
	if(valider(expression,regPtr)==REGEX_VALIDE){
		int trouve=regexec(&regPtr,expression,0,NULL,0);
		regfree(&regPtr);
		if (trouve==0)return 1;
		else return 0;
	}
	else{
		fprintf(stderr, "expression %s invalide\n",expression );
		return 0;
        
	}
}