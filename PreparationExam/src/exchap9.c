#include <stdio.h>
#include "exchap9.h"
void question92(){
    /* Déclarations */
 int A[100], B[50]; /* tableaux */
 int N, M;  /* dimensions des tableaux */
 int I;     /* indice courant */
 
 /* Saisie des données */
 printf("Dimension du tableau A (max.50) : ");
 scanf("%d", &N );
 for (I=0; I<N; I++)
     {
      printf("Elément %d : ", I);
      scanf("%d", A+I);
     }
 printf("Dimension du tableau B (max.50) : ");
 scanf("%d", &M );
 for (I=0; I<M; I++)
     {
      printf("Elément %d : ", I);
      scanf("%d", B+I);
     }
 /* Affichage des tableaux */
 printf("Tableau donné A :\n");
 for (I=0; I<N; I++)
      printf("%d ", *(A+I));
 printf("\n");
 printf("Tableau donné B :\n");
 for (I=0; I<M; I++)
      printf("%d ", *(B+I));
 printf("\n");
 /* Copie de B à la fin de A */
 for (I=0; I<M; I++)
       *(A+N+I) = *(B+I);
 /* Nouvelle dimension de A */
 N += M; 
  /* Edition du résultat */
 printf("Tableau résultat A :\n");
 for (I=0; I<N; I++)
       printf("%d ", *(A+I));
 printf("\n");
}
