#ifndef EXEMPLE6_COMPTEUR_H
# define EXEMPLE6_COMPTEUR_H

typedef struct compteur * Compteur;

Compteur compteur_creer(int nouvelle_valeur, int pas);
int compteur_reinitialiser(Compteur p);
int compteur_prochaine_valeur(Compteur p);
void compteur_supprimer(Compteur p);

#endif /* EXEMPLE6_COMPTEUR_H */
