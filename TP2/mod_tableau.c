#include "mod_tableau.h"
#include "mod_erreur.h"
#include <stdio.h>
#include <stdlib.h>

void afficher(int *ptr, int n, int m)
{
    if (n>0 && m>0 && ptr!=NULL)
    {
        int (*lignePtr)[m];

        lignePtr = (int (*)[m]) ptr;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                printf("%5d ",lignePtr[i][j]);
            }
            printf("\b\n");
        }
    }
    else
    {
        signaler_erreur(TABLEAU2D_VIDE_ERREUR);
    }
}