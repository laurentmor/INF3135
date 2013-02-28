#include <stdio.h>

#include "demo1.h"
void genererTables(){
   
    int i;
    int j;
    int k;
    printf("0 1 2 3 4 5 6 7 8 9 \n ");
    for(k=0;k<10;k++){printf("--");}
    printf("\n");
    for( i=1;i<10;i++){
        printf("%d |",i);
        for(j=0;j<10;j++){
            printf("%d ",i*j);
        }
        printf("\n");
    }
}
