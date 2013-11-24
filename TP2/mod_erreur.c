#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#include "mod_erreur.h"

void signaler(int code){
	switch (code)
    {
        case OUVERTURE_FICHIER_ERREUR :
            fprintf(stderr,"Erreur d'ouverture du fichier.\n");
        break;
        case SYNTAX_DOMAIN_ERREUR :
            fprintf(stderr,"Erreur de syntaxe dans un domaine.\n");
            break;
        case OPTION_ERREUR :
                fprintf(stderr,"Erreur dans une option.\n");
                break;
        case FICHIER_SANS_DONNEE_ERREUR : 
            fprintf(stderr,"Le fichier ne comporte aucune donnee.\n");
            break;
        case TABLEAU2D_VIDE_ERREUR :
            fprintf(stderr,"Tableau vide!\n");
            break;
        default : 
            break;
    }
}