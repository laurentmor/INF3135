/* liblistes.h : Module de listes generiques */
#ifndef LIBLISTES_H
# define LIBLISTES_H

typedef struct liste * p_liste;

p_liste insere_liste(p_liste l, void *s);
void affiche_liste(p_liste l, void (*affiche) (void *, char *));
p_liste retire_liste(p_liste l, void *s);
p_liste concatene_listes(p_liste p1, p_liste p2);

#endif /* LIBLISTES_H */
