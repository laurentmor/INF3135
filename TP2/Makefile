######################################
#MAKEFILE pour le projet#
#NOM et Prénom : Morissette, Laurent 
#Code permanent : MORL05058301
#antoine boutros
#BOUA06099209
#####################################

COMPILER=gcc
OPTIONS= -W  -Wall  -std=c99 -g 


SOURCES= filtre.c mod_regex.c mod_domaine.c mod_erreur.c mod_tableau.c mod_cmd.c mod_fichier.c
OBJETS=${SOURCES:.c=.o}
EXECUTABLE=filtre	

${EXECUTABLE}:	${OBJETS}
	${COMPILER} ${OPTIONS} ${OBJETS} -o ${EXECUTABLE}

filtre.o: filtre.c mod_erreur.h

mod_regex.o:mod_regex.c mod_regex.h 

mod_cmd.o:	mod_cmd.h mod_erreur.h mod_cmd.c
mod_domaine.o: mod_regex.h mod_domaine.h mod_erreur.h mod_cmd.h mod_domaine.c
mod_erreur.o:  mod_erreur.h mod_erreur.c
mod_tableau.o: mod_tableau.h mod_erreur.h mod_tableau.c
mod_fichier.o:	mod_fichier.h mod_erreur.h mod_fichier.c	 



clean:
	rm -f *.o
