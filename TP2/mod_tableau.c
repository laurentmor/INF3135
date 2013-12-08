#include "mod_tableau.h"
#include "mod_erreur.h"
#include <stdio.h>
#include <stdlib.h>
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