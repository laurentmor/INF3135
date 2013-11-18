/* 
 * File:   indent.c
 * Author: laurent
 *
 * Created on 10 février 2013, 15:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *
 */
#define EOL "\0"
#define CR '\n'
#define TAILLE_MAX 128
#define TABULATION '\t'
void analyser();
void afficherCodeIndente(char codeAAfficher[]);
char *lireEntree(char *code, int taille);
char indenterAPartirDe(char *c[],int index);

int estCommentaireUniligne(int index);
int estCommentaireMultiligne(int index);
int estAccoladeOuvrante(int index);
int estAccoladeFermante(int index);
int estPrintf(int index);
//variables

char code[TAILLE_MAX];
int niveauIndentation = 0;
int nombreAccoladesOuvrantes = 0;
int nombreAccoladesFermantes = 0;

void analyser() {
    int indexCaractereCourant = 0;

    while (indexCaractereCourant < strlen(code)) {
        //printf("index %d ",indexCaractereCourant); 
        if (estCommentaireUniligne(indexCaractereCourant)) {
            /*S'Il s'agit de commentaire uniligne on décale l'analyse à partir de la fin
             * commentaire*/

            int indexProchaineFinDeLigne = strchr(code, CR) - code;
            indexCaractereCourant += indexProchaineFinDeLigne;
        }

        if (estAccoladeOuvrante(indexCaractereCourant)) {
            niveauIndentation++;
            *code=indenterAPartirDe(indexCaractereCourant);
            nombreAccoladesOuvrantes++;


        }
        if (estAccoladeFermante(indexCaractereCourant)) {
            nombreAccoladesFermantes++;
            niveauIndentation--;
        }
        if (estCommentaireMultiligne(indexCaractereCourant)) {
            int indexProchaineFinDeCommentaire = strchr(code, '/') + 1 - code;
            indexCaractereCourant += indexProchaineFinDeCommentaire;
        }

        if (estPrintf(indexCaractereCourant)) {
            int indexProchaineFinDeLigne = strchr(code, CR) - code;
            indexCaractereCourant += indexProchaineFinDeLigne;
        }

        if (nombreAccoladesFermantes != nombreAccoladesOuvrantes) {
            printf("Il manque %d accolade(s) fermantes", nombreAccoladesOuvrantes - nombreAccoladesFermantes);
        }

        indexCaractereCourant++;
    }

}

void afficherCodeIndente(char codeAAfficher[]) {
    int i;
    for (i = 0; i < sizeof(codeAAfficher); i++) {
        putc(codeAAfficher[i], stdout);
    }
}

char *lireEntree(char *code, int taille) {
    int car;

    while ((car = getchar()) != EOF) {
        taille--;
        if (!taille) {
            if (car != CR)
                ungetc(car, stdin);
            *code = '\0';
            return code;
        }
        if (car == CR) {
            *code = '\0';
            return (code);
        }
        *(code++) = car;
    }
    *(code) = '\0';
    return (NULL);
}

int main(void) {
    //code[] = "allo//zz";

    //char text[];
    char text[]="allo";
    text=indenterAPartirDe(*text,2);
    printf(text);
    // lireEntree(code, TAILLE_MAX);
    //analyser();
    //afficherCodeIndente(code);
    return (EXIT_SUCCESS);
}

// testons ici les cas type où ne pas faire d'indentation

/**
 * couvre le cas des commentaires uniligne
 * @param index
 * @return 1 si le caractère fait partie d'un commentaire uniligne
 */
int estCommentaireUniligne(int index) {

    if (code[index] == '/'
            && code[index + 1] == '/')
        return 1;
    else return 0;
}

/**
 * couvre le cas des commentaires multilignes
 * @param index
 * @return 1 si le caractère fait partie d'un commentaire multiligne
 */
int estCommentaireMultiligne(int index) {
    if (code[index] == '/'
            && code[index + 1] == '*')
        return 1;
    else return 0;
}

int estAccoladeOuvrante(int index) {
    return code[index] == '{';
}

int estAccoladeFermante(int index) {
    return code[index] == '}';
}

int estPrintf(int index) {
    return (code[index] == 'p'
            && code[index + 1] == 'r'
            && code[index + 2] == 'i'
            && code[index + 3] == 'n'
            && code[index + 4] == 't'
            && code[index + 5] == 'f');
}

char indenterAPartirDe( char *c[], int index) {
    

    

    size_t len = strlen(c);
    char *resultante = malloc(len + niveauIndentation + 1);
    strcpy(resultante, c);
    int i;
    for (i = 0; i < niveauIndentation; i++) {
        resultante[index + i] = TABULATION;
    }
//    resultante[len - 1] = EOL;

   return  *resultante;

    


}
