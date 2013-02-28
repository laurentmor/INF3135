/*Dictionnaires.h : Module de gestion de dictionnaires : type abstrait */
#ifndef DICTIONNAIRES_H
# define DICTIONNAIRES_H

/* Un dictionnaire est une collection de couples (cle, definition) ou
	cle est une chaîne de caracteres, dont la valeur est utilisee au plus une fois dans la collection,
	definition un pointeur vers une donnee quelconque
   La reservation d'espace pour stocker la cle et la definition sont du ressort de l'utilisateur 

   Les fonctions du module retournent OK (equivalent à 0) en cas de succes, et des statuts varies (equivalents à non-0) en cas d'echec

   NB : il n'y a pas de fonction de destruction de dictionnaire, car le module ne peut recuperer l'espace associe aux definitions
*/
typedef void * Definition;
typedef struct dictionnaire * dictionnaire;
typedef struct iter_dictionnaire * iter_dictionnaire;

typedef enum statut {OK, ERR_ECHEC_ALLOCATION, ERR_INSERE_ENTREE_EXISTANTE, ERR_DICTIONNAIRE_VIDE, ERR_ENTREE_INEXISTANTE, FIN_DICTIONNAIRE} statut;

/* Creation d'un nouveau dictionnaire 
   Retourne un element de type dictionnaire. 
   Reussit toujours.
*/

dictionnaire dictionnaire_cree(void);

/* Insertion d'une entree dans le dictionnaire
   Le premier argument est l'adresse d'un element de type dictionnaire, car l'adresse du dictionnaire peut changer 
   Retourne OK si l'insertion est faite;
   Retourne ERR_ECHEC_ALLOCATION si un manque de memoire a empêche l'action de s'executer (le dictionnaire n'est alors pas modifie)
   Retourne ERR_INSERE_ENTREE_EXISTANTE si la cle est dejà utilisee (le dictionnaire n'est alors pas modifie)
*/
statut dictionnaire_insere_entree(dictionnaire *d, char *nouvelle_cle, Definition entree);

/* Suppression d'une entree du dictionnaire
   Le premier argument est l'adresse d'un element de type dictionnaire, car l'adresse du dictionnaire peut changer 
   Le troisieme argument est un pointeur vers une definition, de facon à permettre à l'utilisateur de liberer l'espace memoire associe à la
   definition au besoin.  
   Retourne OK si la suppression est faite;
   Retourne ERR_DICTIONNAIRE_VIDE si le dictionnaire est vide lors de l'appel
   Retourne ERR_ENTREE_INEXISTANTE si la cle n'existe pas dans le dictionnaire (le dictionnaire n'est alors pas modifie)
*/
statut dictionnaire_supprime_entree(dictionnaire *d, char *cle, Definition *def);

/* Lecture d'une entree (definie par sa cle) dans le dictionnaire
   Le premier argument est un dictionnaire
   Le troisieme argument est un pointeur vers une definition, de facon à permettre à l'utilisateur de lire ou de modifier la definition 
   Retourne OK si la lecture est faite;
   Retourne ERR_DICTIONNAIRE_VIDE si le dictionnaire est vide lors de l'appel (*def vaut alors NULL)
   Retourne ERR_ENTREE_INEXISTANTE si la cle n'existe pas dans le dictionnaire  (*def vaut alors NULL)
*/
statut dictionnaire_lit_entree(dictionnaire d, char *cle, Definition *def);

/* Lecture sequentielle du dictionnaire
   Les elements sont retournes selon l'ordre alphanumerique des cles (defini par le code ASCII).
   Le premier argument est un iterateur, cree par dictionnaire_init_lecture_seq
   Le troisieme argument est un pointeur vers une definition, de facon à permettre à l'utilisateur de lire ou de modifier la definition 
   Pour entamer ou reprendre la lecture au debut du dictionnaire, creer un nouvel iterateur
   Retourne OK si la lecture est faite;
   Retourne FIN_DICTIONNAIRE s'il n'y a plus d'entree à lire (*cle est alors vide, et *def vaut NULL)

   dictionnaire_init_lecture_seq : retourne ERR_ECHEC_ALLOCATION en cas de manque de memoire, ERR_DICTIONNAIRE_VIDE si le dictionnaire est vide, OK sinon

   Le comportement de dictionnaire_prochaine_entree n'est pas defini si le dictionnaire subi des modifications entre l'initialisation
   de la lecture sequentielle et une lecture, ou entre deux lectures sequentielles.
*/
statut dictionnaire_init_lecture_seq(iter_dictionnaire *i, dictionnaire d); 
statut dictionnaire_prochaine_entree(iter_dictionnaire i, char *cle, Definition *def);
#endif /* DICTIONNAIRES_H */

