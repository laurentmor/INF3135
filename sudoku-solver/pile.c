/* pile.c

   Module gérant une pile de pointeurs de type void *, implementee
   sous la forme d'une machine abstraite.

   Emmanuel Chieze
*/

#include <assert.h>
#include "pile.h"

#define MAX_ELEMS 100

static int nbElements = 0;
static void * elems[MAX_ELEMS];

void pileEmpiler(void * x) {
	assert (nbElements < MAX_ELEMS && "pile pleine");

	elems[nbElements++] = x;
}

void * pileDepiler(void) {
	assert (nbElements > 0 && "pile vide");

	return elems[--nbElements];
}

PileStatut pileTaille(void) {
	if (! nbElements)
		return PILE_VIDE;
	if (nbElements == MAX_ELEMS)
		return PILE_PLEINE;
	return PILE_OK;
}
