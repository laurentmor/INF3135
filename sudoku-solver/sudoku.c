#include <stdlib.h>

#include "pile.h"
#include "sudoku.h"
#include "messages.h"
#include <assert.h>
  typedef struct Grille {
    int grid[TAILLE][TAILLE];
} *Sudoku;
Sudoku sudokuCree(void){
 Sudoku sudoku;
  if(!(sudoku = (Sudoku)malloc(sizeof(struct Grille)))) {
        return NULL;
    }
    int i=0;
    int j=0;
    
    for(;i<TAILLE;i++){
       for(;j<TAILLE;j++){
           //sudoku.grid[i][j]=0;
       }
    }
    return sudoku;
}
Sudoku sudokuCopie(Sudoku sudoku){
    assert(sudoku!=NULL && MSG_ARGUMENT_NULL);
    Sudoku copie;
    //=(Sudoku)malloc(sizeof(struct Sudoku));
    copie=sudoku;
    return copie;
}

void sudokuDetruit(Sudoku sudoku){
    if(sudoku!=NULL){
        free(sudoku);
    }
}
Statut sudokuJouerCase(Sudoku sudoku, int ligne, int colonne, int valeur){
}

Statut sudokuRetirerValeurPossible(Sudoku sudoku, int ligne, int colonne, int valeur){
}
int sudokuNbCasesVides(Sudoku sudoku){
}
Statut sudokuChercheCoup(Sudoku sudoku, NbValeurs nbValeursRecherchees, int * ligne, int * colonne, int * valeur){
}
void sudokuAffiche(Sudoku sudoku){}