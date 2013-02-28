# Makefile des fichiers d'exemples du cours INF3135 (E. Chieze)

# Variables predefinies
CC = gcc
CFLAGS = -W -Wall
# Variables additionnelles

# Dependances
# Cette "dependance" formelle permet de lancer la compilation de programmes independants
# Par defaut, make (sans arguments) ne se soucie que de la premiere dependance rencontree
# Aucune action par defaut ici, car gcc ne "sait" pas comment traiter ces dependances
all : exemple6.8 exemple6.2 exemple6.3 exemple6.4 exemple6.5 exemple6.6 exemple6.7 exemple6.1

# Dependances simples : gcc "sait" comment traiter les fichiers .c, et "comprend" d'apres
# le nom des fichiers cibles qu'il s'agit d'executables. Inutile de specifier une commande
# de compilation
exemple6.8 : exemple6.8.c
exemple6.1 : exemple6.1.c
exemple6.2 : exemple6.2.c
exemple6.3 : exemple6.3.c
exemple6.4 : exemple6.4.c

# Dependances plus complexes : on ne peut melanger .c, .o et .h dans la meme dependance
exemple6.5 : exemple6.5.o exemple6.listes.o
exemple6.5.o : exemple6.5.c exemple6.listes.h
exemple6.listes.o : exemple6.listes.c exemple6.listes.h

exemple6.6 : exemple6.6.o exemple6.listesABS.o
# On peut specifier une action de compilation (Pour l'exemple ici, non necessaire dans ce cas-ci)
	$(CC) exemple6.6.o exemple6.listesABS.o -o exemple6.6
exemple6.6.o : exemple6.6.c exemple6.listesABS.h
exemple6.listesABS.o : exemple6.listes.c exemple6.listesABS.h

exemple6.7 : exemple6.7.o exemple6.compteur.o
exemple6.7.o : exemple6.7.c exemple6.compteur.h
exemple6.compteur.o : exemple6.compteur.c exemple6.compteur.h

# Permet de nettoyer le repertoire de tous les fichiers compiles (objets et executables)
# make doit etre appelee avec clean comme argument, pour que cette "dependance" soit traitee
clean :
	rm exemple6.? exemple6*.o
