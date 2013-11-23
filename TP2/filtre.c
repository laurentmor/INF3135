#include "mod_regex.h"
#define TOUTE_SYNTAXE_VALIDE "(^-{1}[0-9]+$){1}|(^[0-9]+-$)|(^[0-9]+-[0-9]+$)"
#define _NUM "(^-{1}[0-9]+$){1}"
#define NUM_ "(^[0-9]+-$)"
#define NUM1_NUM2 "(^[0-9]+-[0-9]+$)"  

int main()
{
	
/**
pour fin de tests
 definition des type de domaines
*/
 printf("%d\n",chercherDansChaine(_NUM,"-12") );
 printf("%d\n",chercherDansChaine(NUM_,"12-") );
 printf("%d\n",chercherDansChaine(NUM1_NUM2,"1-12") );    
	return 0;
}
