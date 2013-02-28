/* Exemple6.listesABS.h : Module de listes generiques */
#ifndef EXEMPLE6_LISTESABS_H
# define EXEMPLE6_LISTESABS_H

typedef struct liste * Liste;
typedef void * ListeElement;
#define TAILLEMAXELT 10

Liste cree_liste(void);
Liste insere_liste(Liste l, ListeElement s);
void affiche_liste(const Liste l, void (*affiche) (ListeElement, char *));
Liste retire_liste(Liste l, ListeElement *  s);

#endif /* EXEMPLE6_LISTESABS_H */
