#########################
#MAKEFILE pour le projet#
#########################

COMPILER=gcc
OPTIONS= -W  -Wall  -std=c99 -g 


SOURCES= filtre.c mod_regex.c mod_domaine.c mod_erreur.c
OBJETS=${SOURCES:.c=.o}
EXECUTABLE=filtre	

${EXECUTABLE}:	${OBJETS}
	${COMPILER} ${OPTIONS} ${OBJETS} -o ${EXECUTABLE}

filtre.o: filtre.c mod_erreur.h

mod_regex.o:mod_regex.c mod_regex.h 

mod_domaine.o: mod_regex.h mod_domaine.h mod_erreur.h mod_domaine.c
mod_erreur.o:  mod_erreur.h mod_erreur.c 

clean:
	rm -f *.o
