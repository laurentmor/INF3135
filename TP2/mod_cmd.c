//NOM et Prénom : Morissette, Laurent
//Code permanent : MORL05058301
//antoine boutros
//BOUA06099209

#include "mod_cmd.h"
#include "mod_erreur.h"
#include <string.h>
#include <stdio.h>
int nombreArguments(char *const argv[]){
	int nombre=0;
	while(*argv){
		nombre++;
		argv++;
	}
	return nombre;
}

int chercherOption(char *const argv[],char option){
	int i=0;
	int occurences=0;
	int pos=0;
	option=toupper(option);
	if (option==OPTION_LIGNE)
	{
		 while (*argv) {
            if (!(strcmp(*argv, "-L"))) {
                pos = i;
                occurences++;
            }
            argv++;
            i++;
        }
	}
	else if (option==OPTION_COLONE)
	{
	  while (*argv) {
            if (!(strcmp(*argv, "-C"))) {
                pos = i;
                occurences++;
            }
            argv++;
            i++;
        }	
	}
	else if (option==OPTION_FUSION_VERTICALE)
	{
		while (*argv) {
            if (!(strcmp(*argv, "-V"))) {
                pos = i;
                occurences++;
            }
            argv++;
            i++;
        }	
	}
	else if (option==OPTION_FUSION_HORIZONTALE)
	{
		while (*argv) {
            if (!(strcmp(*argv, "-H"))) {
                pos = i;
                occurences++;
            }
            argv++;
            i++;
        }	
	}
	else{
		signaler(OPTION_ERREUR);
	}
	if (occurences>1)
	{
		signaler(OPTION_ERREUR);
		return -1;
	}
	return pos;
}