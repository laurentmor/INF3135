#########################
#MAKEFILE pour le projet#
#########################

COMPILER=gcc
FILTRE_OPTIONS= -W -Wall  -std=c99  -o
MOD_OPTIONS= -W -Wall  -std=c99 -c -o
#changer le noa de l'exécutable pour la spec du TP2
EXEC=TP2

all:filtre

filtre:mod_regex.o mod_domaine.o
	echo "compilation du filtre"
	${COMPILER} filtre.c ${FILTRE_OPTIONS} filtre 

mod_regex:mod_regex.h
	echo "compilation du module d'expression regulieres"
	${COMPILER} mod_regex.c ${MOD_OPTIONS} mod_regex.o

mod_domaine:mod_domaine.h
	${COMPILER} mod_domaine.c ${MOD_OPTIONS} mod_domaine.o


clean:
	rm -rf *.o

