#include <stdio.h>
#include <string.h>
#include "exchap8.h"
#define TAILLE_MAX 200

void question82() {
    char mot1[TAILLE_MAX];
    char mot2[TAILLE_MAX];
    char mot3[TAILLE_MAX];
    char mot4[TAILLE_MAX];
    char mot5[TAILLE_MAX];

    printf("Entrez une phrase:\n");
    scanf("%s%s%s%s%s", mot1, mot2, mot3, mot4, mot5);
    printf("Phrase inversee: %s %s %s %s %s", mot5, mot4, mot3, mot2, mot1);
}

void question83() {
    char txt[TAILLE_MAX];
    int L = 0;
    int i = 0;
    int nbE = 0;
    printf("Entrez une ligne:\n");
    gets(txt);
    while (txt[i] != '\n') {
        if (txt[i] == 'e') {
            nbE++;


        }

        i++;


    }
    printf("Chaine %s\n", txt);
    printf("a) %i\n", i);
    printf("b) %i\n", nbE);


}

void question85() {
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    printf("Entrez votre nom et prenom\n");
    scanf("%s %s", prenom, nom);
    printf("Votre nom complet %s,%s est composé de %i", prenom, nom, strlen(nom) + strlen(prenom));

}

void question86() {
    char ch1[TAILLE_MAX];
    printf("Introduisez la première chaîne:\n");
    scanf("%s", ch1);
    char ch2[TAILLE_MAX];
    printf("Introduisez la deuxieme chaîne:\n");
    scanf("%s", ch2);
    int resCmp = strcmp(ch1, ch2);
    if (resCmp < 0) {
        printf("%s precede %s", ch1, ch2);
    }
    else if(resCmp>0){
        printf("%s precede %s", ch2, ch1);
    }
    else{
        printf("%s vaut %s", ch1, ch2);
    }
}

void question812(){
    char jours[8][9]={"Erreur","Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi","Dimanche"};
    int jour=0;
    printf("Jour:\n");
    scanf("%i",&jour);
    printf("Nom complet du jour: %s",jours[jour]);
}