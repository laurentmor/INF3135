#########################
#MAKEFILE pour le projet#
#########################

COMPILER=gcc
OPTIONS= -W -Wall  -std=c99 -o
#changer le noa de l'exécutable pour la spec du TP2
EXEC=TP2

all:mod_regex

mod_regex:mod_regex.h
	echo "compilation du module d'expression regulieres"
	${COMPILER} mod_regex.c ${OPTIONS} mod_regex.o

clean:
	rm -rf *.o

