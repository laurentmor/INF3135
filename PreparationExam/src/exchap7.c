#include <stdio.h>
#include <stdlib.h>
#include "exchap7.h"

void question71() {
    int n = 0;
    printf("Taille:");
    scanf("%i", &n);
    if (TAILLE_MAX >= n) {
        int tab[n];
        int i = 0;
        int somme = 0;
        for (; i < n; i++) {
            scanf("%i", &tab[i]);
            somme += tab[i];
        }
        printf("\nSomme %i", somme);
    }
}

void question72() {
    int n = 0;
    printf("Taille:");
    scanf("%i", &n);
    if (TAILLE_MAX >= n) {
        int tab[n];
        int i = 0;
        int somme = 0;
        for (; i < n; i++) {
            scanf("%i", &tab[i]);

        }
        malloc(sizeof (tab));
        size_t s = sizeof (tab);
        printf("%i", s);
        for (i = 0; i < n; i++) {
            printf("%i", tab[i]);

        }
        printf("recherchons 0\n");
        for (i = 0; i < n; i++) {
            if (tab[i] == 0) {
                tab[i] = tab[i + 1];
                n--;

            }

        }
        s = sizeof (tab);
        printf("(%i)", s);
        for (i = 0; i < n; i++) {
            printf("[%i]", tab[i]);

        }
        free(tab);

    }
}

void question75() {
    int n = 0;
    int m = 0;
    printf("Taille:");
    scanf("%i%i", &n, &m);
    if ((TAILLE_MAX >= n)&&(TAILLE_MAX >= m)) {
        int tab[n][m];
        int i = 0;
        int j = 0;
        int somme = 0;
        for (; i < m; i++) {
            for (j; j < n; j++) {
                
                scanf("%i", &tab[i][j]);
                somme += tab[i][j];
            }
        }
        printf("\nSomme %i", somme);
    }
}