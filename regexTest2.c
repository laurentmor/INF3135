#include<regex.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{
    int erreur;
    const char * chaine1="12--34";
    const char * expr="(^-{1}[0-9]+$){1}|(^[0-9]+-$)|(^[0-9]+-[0-9]+$)";
    regex_t expressionPtr;
    erreur=regcomp(&expressionPtr,expr,REG_NOSUB | REG_EXTENDED);
    if(erreur==0){
        int matched=regexec(&expressionPtr,chaine1,0,NULL,0);
        regfree(&expressionPtr);
        if (matched==0)
            {
                printf("Domaine ok\n" );
            }
    }
return 0;
}
