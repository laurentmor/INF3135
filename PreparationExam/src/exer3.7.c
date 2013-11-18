#include <math.h>
#include <stdio.h>
#include "exer3.7.h"
void math();

void math() {
    double A;
    double B;
    double RES;
    /* Saisie de A et B */
    printf("Introduire la valeur pour A : ");
    scanf("%lf", &A);
    printf("Introduire la valeur pour B : ");
    scanf("%lf", &B);
    /* Calcul */
    RES = A*A;
    /* Affichage du résultat */
    printf("Le carré de A est %f \n", RES);
    /* Calcul */
    RES = B*B;
    /* Affichage du résultat */
    printf("Le carré de B est %f \n", RES);
    RES=pow(A,B);
    printf("A^b %f\n",RES);
    
//    return 0;
}