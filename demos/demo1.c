#include <stdio.h>

#include "include/demo1.h"
void genererTables(){
   
    int i;
    int j;
    int k;
    printf("0 1 2 3 4 5 6 7 8 9 \n ");
    char c='-';
    printf("*   ");

    printf("\n");
    for( i=1;i<1000;i++){
        printf("%4d|",i);
        for(j=0;j<1000;j++){
            printf("%4d",i*j);
        }
        printf("\n");
    }
}
