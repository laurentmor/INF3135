#include <stdio.h>
#include "ex4.4.h"

void permuter(int *a, int *b, int *c){
    int temp1=*a;
    int temp2=*c;
    *a= *b;
    *b=temp2;
    *c=temp1;
}

