//NOM et Prénom : Morissette, Laurent
//Code permanent : MORL05058301
//antoine boutros
//BOUA06099209

#ifndef MOD_TABLEAU_H
#define MOD_TABLEAU_H
//Cette structure offre un type de donnée repésentant un tableau 2D
struct tab2D{
int lignes; //nombre de lignes du tableau 2D
int colonnes; //nombre de colonnes du tableau 2D
char* *ptr; // représente un tableau de char* celui est interprété comme
             // un tableau 2D de taille lignes x colonnes
}; 
void afficher(struct tab2D mat);
void fusionner(char mode,struct *tab2D t1,int count, struct *tab2D t2);

#endif