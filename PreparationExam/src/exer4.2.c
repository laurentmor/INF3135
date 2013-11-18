#include<stdio.h>
#include "exs4.2.h"
void date(){
    int nbVal=0;
    int an=0;
    int mois=0;
    int jour=0;
    printf(" Introduisez la date (jour mois année):\n");
    nbVal=scanf("%d-%d-%d",&an,&mois,&jour);
    printf("Recu %i\n Date:%d %d %d\n",nbVal,an,mois,jour );
}
