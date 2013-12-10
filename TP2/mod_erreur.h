//NOM et Prénom : Morissette, Laurent
//Code permanent : MORL05058301
//antoine boutros
//BOUA06099209

#ifndef MOD_ERREUR_H
#define MOD_ERREUR_H 
#define OUVERTURE_FICHIER_ERREUR 0

//Fichier ne comporte aucun mot
#define FICHIER_SANS_DONNEE_ERREUR 1

// Les parmètres du programmes conformes 
// mais erreur de syntaxe dans l'un des domaines
#define SYNTAX_DOMAIN_ERREUR 2


//Erreur concernant une option
#define OPTION_ERREUR 3

//Le résultat est un tableau vide
#define TABLEAU2D_VIDE_ERREUR 4



void signaler(int code);

#endif