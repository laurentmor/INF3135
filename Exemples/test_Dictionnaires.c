#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Dictionnaires.h"

#define NBJOURS 7

int main(void) {
	char *a[NBJOURS] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
	int *definition, i;
	dictionnaire dico;
	iter_dictionnaire ils;
	char cle[50], cle_prec[50];

	/* Aucun test pour dictionnaire_cree() */

	/* Test de dictionnaire_supprime_entre() : dictionnaire vide */
	assert(dictionnaire_supprime_entree(&dico, a[0], (Definition *) &definition) == ERR_DICTIONNAIRE_VIDE);

	/* Test de dictionnaire_lit_entree() : dictionnaire vide */
	assert(dictionnaire_lit_entree(dico, a[0], (Definition *) &definition) == ERR_DICTIONNAIRE_VIDE);

	/* Test de lecture sequentielle : dictionnaire vide */
	assert(dictionnaire_init_lecture_seq(&ils, dico) == ERR_DICTIONNAIRE_VIDE && ils == NULL); 

	/* Test de dictionnaire_insere_entree() et de dictionnaire_lit_entree() */
	/* Inclut les cas suivants :
		1- ajout d'une entree a un dictionnaire vide
		2- ajout d'une entree en tête de dictionnaire
		3- ajout d'une entree a la fin du dictionnaire
	   Il faudrait rajouter l'ajout d'une entree au milieu du dictionnaire */

	for (i = 0; i< NBJOURS; i++) {
		definition = (int *) malloc(sizeof(int));
		*definition = i;
		assert(dictionnaire_insere_entree(&dico, a[i], (Definition) definition) == OK);
		definition = NULL;
		assert(dictionnaire_lit_entree(dico, a[i], (Definition *) &definition) == OK && *definition == i);
	}
	/* Test de dictionnaire_insere_entree() : entree existante */
	definition = (int *) malloc(sizeof(int));
	*definition = 9;
	assert(dictionnaire_insere_entree(&dico, a[0], (Definition) definition)== ERR_INSERE_ENTREE_EXISTANTE);
	free(definition);

	/* Test de dictionnaire_lit_entree() : entree inexistante */
	definition = NULL;
	assert(dictionnaire_lit_entree(dico,"toto", (Definition *) &definition)== ERR_ENTREE_INEXISTANTE);

	/* Test de dictionnaire_supprime_entree() : entree inexistante */
	definition = NULL;
	assert(dictionnaire_supprime_entree(&dico,"toto", (Definition *) &definition)== ERR_ENTREE_INEXISTANTE);

	/* Test de dictionnaire_supprime_entree() : entree existante */
	/* Entree au milieu du dictionnaire*/
	definition = NULL;
	assert(dictionnaire_supprime_entree(&dico,a[0], (Definition *) &definition)== OK && *definition == 0); 
	free(definition);
	/* Entree au debut du dictionnaire */
	definition = NULL;
	assert(dictionnaire_supprime_entree(&dico,a[6], (Definition *) &definition)== OK && *definition == 6); 
	free(definition);
	/* Entree a la fin du dictionnaire */
	definition = NULL;
	assert(dictionnaire_supprime_entree(&dico,a[5], (Definition *) &definition)== OK && *definition == 5); 
	free(definition);

	/* Test de lecture sequentielle */
	assert(dictionnaire_init_lecture_seq(&ils, dico) == OK); 
	i = 0;
	while(dictionnaire_prochaine_entree(ils, cle, (Definition *) &definition) == OK) {
		assert(!strcmp(cle,a[*definition])); /* Les cles correspondent a leur definition */
		assert(i==0 || strcmp(cle_prec,cle) < 0); /* Les cles sont ordonnees */
		strcpy(cle_prec,cle);
		i++;
	}
	assert (i == 4);

	printf("OK\n");
	return(0);
}
