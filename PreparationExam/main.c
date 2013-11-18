/* 
 * File:   main.c
 * Author: laurent
 *
 * Created on 2 mars 2013, 14:35
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/hello.h"
#include "include/exer3.7.h"
#include "exs4.2.h"
#include "ex4.4.h"
#include "exchap7.h"
#include "exchap8.h"
#include "exchap9.h"
/*
 * 
 */
int main(int argc, char** argv) {
    if (argc < 1)fprintf(stderr, "usage: code aName\n");
    else {
        //if (*argv[1] == "hello") {
            //TODO FAIT sayHiTo(argv[2]);
        //}
           //FAIT math();
        //FAIT date();
        int a=3;
        int b=12;
        int c=8;
        permuter(&a,&b,&c);
        typedef struct {
            int lon;
             char nom[54];
        } BonHomme;
        BonHomme bo;
        bo.lon=12;
        scanf("%s",&bo.nom);                                     
        printf("A(%d)\nB(%d)\nC(%d) %s",a,b,c,bo.nom);
        //FAIT question71();
        //question72();
        //question75();
        //question82();
        //question83();
        //question85();
        //question86();
       // question812();
        //question92();
        
    }
    return (EXIT_SUCCESS);
}

