#include "mod_regex.h"
#define TOUTE_SYNTAXE_VALIDE "(^-{1}[0-9]+$){1}|(^[0-9]+-$)|(^[0-9]+-[0-9]+$)"
#define _NUM "(^-{1}[0-9]+$){1}"
#define NUM_ "(^[0-9]+-$)"
#define NUM1_NUM2 "(^[0-9]+-[0-9]+$)"  

int main()
{
	char * cas=NUM1_NUM2;
	char *dom="1-23";
int state=chercherDansChaine("``","1-23");
printf("%d\n",state );	
//signaler(OPTION_ERREUR);

	return 0;
}
