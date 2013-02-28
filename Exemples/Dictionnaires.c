/*Dictionnaires.c : Module de gestion de dictionnaires : type abstrait */
/*Le dictionnaire est implemente ici comme une liste chainee de (cle,definition) 
   ou les cles sont des chaines de caracteres, les definitions des pointeurs vers des donnees quelconques,
   et ou les elements de la liste sont maintenus dans l'ordre alphanumerique */

#include <string.h>
#include <stdlib.h>
#include "Dictionnaires.h"

struct dictionnaire {
	char *cle;
	Definition definition;
	struct dictionnaire *suivant;
};

typedef struct dictionnaire s_dictionnaire;

struct iter_dictionnaire {
	struct dictionnaire *dictionnaire;
	struct dictionnaire *suivant;
};

typedef struct iter_dictionnaire s_iter_dictionnaire;

dictionnaire dictionnaire_cree(void) {
	return(NULL);
}

statut dictionnaire_insere_entree(dictionnaire *d, char *nouvelle_cle, Definition entree) {
	dictionnaire nouvelle_entree = (dictionnaire) malloc(sizeof(s_dictionnaire));
	if (nouvelle_entree == NULL) 
		return(ERR_ECHEC_ALLOCATION);
	nouvelle_entree->cle = (char *) malloc(strlen(nouvelle_cle)+1);
	if (nouvelle_entree->cle == NULL) 
		return(ERR_ECHEC_ALLOCATION);
	strcpy(nouvelle_entree->cle,nouvelle_cle);
	nouvelle_entree->definition = entree;
	if (*d == NULL || strcmp(nouvelle_cle, (*d)->cle)<0) {
		nouvelle_entree->suivant = *d;
		*d = nouvelle_entree;
	}
	else {
		dictionnaire d_aux = *d;
		while (d_aux->suivant != NULL && strcmp(nouvelle_cle,d_aux->suivant->cle) >= 0) 
			d_aux = d_aux->suivant;
		if (strcmp(nouvelle_cle,d_aux->cle) > 0) {
			nouvelle_entree->suivant = d_aux->suivant;
			d_aux->suivant = nouvelle_entree;
		} 
		else {
			free(nouvelle_entree->cle);
			free(nouvelle_entree);
			return(ERR_INSERE_ENTREE_EXISTANTE);
		}
	}
	return(OK);
}

statut dictionnaire_supprime_entree(dictionnaire *d, char *cle, Definition *def) {
	if (*d == NULL) 
		return(ERR_DICTIONNAIRE_VIDE);
	if (!strcmp(cle, (*d)->cle)) {
		dictionnaire d_suppr = *d;
		*d = (*d)->suivant;
		*def = d_suppr->definition;
		free(d_suppr->cle);
		free(d_suppr);
	}
	else {
		dictionnaire d_aux = *d;
		while (d_aux->suivant != NULL && strcmp(cle,d_aux->suivant->cle) > 0) 
			d_aux = d_aux->suivant;
		if (d_aux->suivant != NULL && !strcmp(cle,d_aux->suivant->cle)) {
			dictionnaire d_suppr = d_aux->suivant;
			d_aux->suivant = (d_aux->suivant->suivant);
			*def = d_suppr->definition;
			free(d_suppr->cle);
			free(d_suppr);
		} 
		else 
			return(ERR_ENTREE_INEXISTANTE);
	}
	return(OK);
}

statut dictionnaire_lit_entree(dictionnaire d, char *cle, Definition *def) {
	*def = NULL;
	if (d == NULL) 
		return(ERR_DICTIONNAIRE_VIDE);
	while (d->suivant != NULL && strcmp(cle,d->cle) > 0) 
		d = d->suivant;
	if (!strcmp(cle,d->cle)) {
		*def = d->definition;
		return(OK);
	} 
	else 
		return(ERR_ENTREE_INEXISTANTE);
}

statut dictionnaire_init_lecture_seq(iter_dictionnaire *i, dictionnaire d) {
	if (d == NULL) {
		*i = NULL;
		return(ERR_DICTIONNAIRE_VIDE);
	}
	*i = (iter_dictionnaire) malloc(sizeof(iter_dictionnaire));
	if (*i == NULL)
		return(ERR_ECHEC_ALLOCATION);
	(*i)->dictionnaire = d;
	(*i)->suivant = d;
	return(OK);
}

statut dictionnaire_prochaine_entree(iter_dictionnaire i, char *cle, Definition *def) {
	*def = NULL;
	*cle = '\0';
	if (i->suivant == NULL)
		return(FIN_DICTIONNAIRE);
	else {
		strcpy(cle,i->suivant->cle);
		*def = i->suivant->definition;
		i->suivant = i->suivant->suivant;
		return(OK);
	}
}

