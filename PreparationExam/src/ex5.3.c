#include <stdio.h>
#include "ex5.3.h"

questionA(int a, int b, int c) {
    
    int MAX;
    
    if (a > b)
        MAX = a;
    else
        MAX =b ;
    if (c > MAX)
        MAX = c;
    printf("La valeur maximale est %i\n", MAX);
    return 0;
}
