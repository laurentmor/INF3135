# Makefile des fichiers d'exemples du cours INF3135 (E. Chieze)

# Variables additionnelles
ENTETES=include
BIBLISTES=lib

# Variables predefinies
CC = gcc
# Ajout de l'option -I pour signaler a gcc ou trouver les en-tetes
CFLAGS = -g -W -I $(ENTETES) 
# VPATH indique a make ou chercher les fichiers mentionnes dans les dependances
# repertoires determines relativement au repertoire courant
VPATH=$(ENTETES):$(BIBLISTES)

# Dependances
toto : toto.o $(BIBLISTES)/liblistes.o
toto.o : toto.c liblistes.h
$(BIBLISTES)/liblistes.o : liblistes.c liblistes.h

# Suppression des fichiers objets et des executables
clean :
	rm toto *.o $(BIBLISTES)/*.o
