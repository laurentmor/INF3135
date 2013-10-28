#include<stdio.h>
#include<regex.h>
#include<stdlib.h>
#define REGEXOK=0;

int main(int argc, char const *argv[])
{
	int erreur;
	const char * chaine1="-12";
	const char * expr="(^-{1}\\d+$){1}|(\\d+-{1}$){1}|(^\\d+-{1}\\d+$){1}";
    regex_t expressionPtr;
	erreur=regcomp(&expressionPtr,expr,REG_NOSUB | REG_EXTENDED);
	if(erreur==REGEXOK){
	 int matched=regexec(&expressionPtr,chaine1,0,NULL,0);
	 regfree(&expressionPtr);
	 if (matched==0)
	 	{
	 		printf("Domaine ok\n" );
	 	}	
	} 
	return 0;
}
