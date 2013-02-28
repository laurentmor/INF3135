/* Exemple6.listes.h : Module de listes generiques */
#ifndef EXEMPLE6_LISTES_H
# define EXEMPLE6_LISTES_H

struct liste {
	void *tete;
	struct liste *queue;
};

typedef struct liste Liste;

Liste * insere_liste(Liste * l, void *s);
void affiche_liste(Liste * l, void (*affiche) (void *, char *));
Liste * retire_liste(Liste * l, void **s);

#endif /* EXEMPLE6_LISTES_H */
