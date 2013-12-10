#include "mod_tableau.h"
#include "mod_erreur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fusVerticale(struct tab2D *source, int count, struct tab2D *destination);
void fusHorizontale(struct tab2D *source, int count, struct tab2D *destination);

void fusVerticale(struct tab2D *source, int count, struct tab2D *destination){
    int i = 0, ix = 0;
    char * (*destinationPtr)[destination->colonnes];
    destinationPtr= (char * (*)[destination->colonnes]) destination->ptr;
    for (i = 0; i < count; i++) {
        int k = 0, j = 0;
        char * (*sourcePtr)[source[i].colonnes];
        sourcePtr = (char * (*)[source[i].colonnes]) source[i].ptr;
        for (k = 0; k < source[i].lignes; k++) {
            for (j = 0; j < source[i].colonnes; j++){
                size_t len = strlen(sourcePtr[k][j]) + 1;
                destinationPtr[k + ix][j] = memcpy(malloc(strlen(sourcePtr[k][j]) + 1), sourcePtr[k][j], len);
            }
            for (j = source[i].colonnes; j < destination->colonnes; j++) 
                destination[k + ix][j] = memcpy(malloc(sizeof ("")), "",sizeof (""));
        }
        ix += source[i].lignes;
    }
}



void fusHorizontale(struct tab2D *source, int count, struct tab2D *destination){
    int i = 0, 
    ix = 0;
    char * (*destinationPtr)[destination->colonnes];
    destinationPtr = (char * (*)[destination->colonnes]) destination->ptr;
    
    for (i = 0; i < count; i++) {
        int k = 0, j = 0;
        char * (*sourcePtr)[source[i].colonnes];
        sourcePtr = (char * (*)[source[i].colonnes]) source[i].ptr;
        for (j = 0; j < source[i].colonnes; j++) {
            for (k = 0; k < source[i].lignes; k++){
                size_t len = strlen(sourcePtr[k][j]) + 1;
                destinationPtr[k][j + ix] = memcpy(malloc(len), sourcePtr[k][j], len);
            }
            for (k = source[i].lignes; k < destination->lignes; k++) 
                destinationPtr[k][j + ix] = memcpy(malloc(sizeof ("")), "",sizeof (""));
        }
        ix += source[i].colonnes;
    }
}

void afficher(struct tab2D mat)
{
if (mat.lignes>0 && mat.colonnes>0 && mat.ptr!=NULL)
{
    char * (*lignePtr)[mat.colonnes];

    lignePtr = (char * (*)[mat.colonnes]) mat.ptr;
    int i = 0 ;
    for (; i < mat.lignes ; i++)
    {
        printf("[");
        int j = 0;
        for ( ; j < mat.colonnes ; j++) 
        {
            printf("%-10s ",lignePtr[i][j]);
        }
        printf("]\n");
    }    
}
else
 {
    signaler(TABLEAU2D_VIDE_ERREUR);
 }
}