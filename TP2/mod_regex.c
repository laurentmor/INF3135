#include "mod_regex.h"



int chercherDansChaine(char *expression, char *chaine){
	regex_t regPtr;
	if (expression==NULL)
	{
		return REGEX_INVALIDE;
	}
	int erreur=regcomp(&regPtr,expression,REG_NOSUB | REG_EXTENDED);
	if (erreur==0){
		int trouve=regexec(&regPtr,chaine,0,NULL,0);
		regfree(&regPtr);
		if (trouve==0)return 1;
		else return 0;
	}
	else{
		fprintf(stderr, "expression %s invalide\n",expression );
		
        
	}
	 
	
		
	return 0;
}

