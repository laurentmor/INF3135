/* 
 * File:   main.c
 * Author: laurent
 *
 * Created on 27 février 2013, 19:30
 */

#include <stdio.h>
#include <stdlib.h>
#include "include/demo1.h"
#include "include/demo2.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //genererTables();
   // printf("%2d",calcule(12,12,'+'));
    int m[]={1,3,5,7,2};
    inverse(m,5);
    affiche_vecteur_int(m,5);
    //minMax(m);
    return (EXIT_SUCCESS);
}

