#########################
#MAKEFILE pour le projet#
#########################

COMPILER=gcc
OPTIONS= -W -Wall  -std=c99 
#changer le noa de l'exécutable pour la spec du TP2
EXEC=TP2

all:filtre

filtre:mod_regex
	echo "compilation du filtre"
	${COMPILER} filtre.c ${OPTIONS} 

mod_regex:mod_regex.h
	echo "compilation du module d'expression regulieres"
	${COMPILER} mod_regex.c ${OPTIONS} 

clean:
	rm -rf *.o

