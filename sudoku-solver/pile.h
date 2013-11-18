/* pile.h

   Module gérant une pile de pointeurs de type void *, implementee
   sous la forme d'une machine abstraite.

   Emmanuel Chieze
*/

#ifndef PILE_H
#define PILE_H

typedef enum { PILE_OK, PILE_VIDE, PILE_PLEINE } PileStatut;

/* pileEmpiler : permet d'ajouter un element en haut de la pile.
  	Precondition : la pile n'est pas pleine. */
void pileEmpiler(void * x);

/* pileDepiler : permet de retirer l'element en haut de la pile,
	et de le recuperer.
	Precondition : la pile n'est pas vide. */
void * pileDepiler(void);

/* pileTaille : permet d'obtenir un indicateur sur la taille de la pile.
	Precondition : Aucune.
	Valeurs possibles du resultat :
		PILE_VIDE : si la pile est vide
		PILE_PLEINE : si la pile est pleine
		PILE_OK : dans les autres cas. */
PileStatut pileTaille(void);

#endif
