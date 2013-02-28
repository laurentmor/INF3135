#include <stdlib.h>
#include <stdio.h>

int **alloueTableau( int nblig, int nbcol );
void afficheTableau( int **tableau, int nblig, int nbcol );

int main(int argc, char * argv[]) {
  int nblig, nbcol, i, j, **tab;

  if (argc != 3)
    fprintf(stderr,"Usage : %s nblig nbcol\n", argv[0]);
	
  /* Il manque le test des arguments : sont-ils des entiers reellement ? */
  nblig = atoi(argv[1]);
  nbcol = atoi(argv[2]);
	
  /* Il manque la vérification que l'allocation se fait bien */
  tab = alloueTableau(nblig, nbcol);

  for (i=0; i < nblig; i++)
    for (j=0; j < nbcol; j++)
	tab[i][j] = i * j;
 
  afficheTableau(tab, nblig, nbcol);
  return(0);
}
	
int **alloueTableau( int nblig, int nbcol ) {
  int **tableau = (int **)malloc(sizeof(int *)*nblig);
  int i = 0;

  for( i = 0; i < nblig; i++ )
    /* Il manque la vérification que l'allocation se fait bien */
    tableau[i] = (int *)malloc( sizeof(int) * nbcol);
  return tableau;
}

void libereTableau( int ** tableau, int nblig ) {
  int i;
  for( i = 0; i < nblig; i++ )
    free(tableau[i]);
  free(tableau);
}

void afficheTableau( int **tableau, int nblig, int nbcol ) {
  int i = 0, j = 0;

  for( i = 0; i < nblig; i++ ) {
    for( j = 0; j < nbcol; j++ ) {
      printf( "%8d ", tableau[i][j] );
    }
    printf( "\n" );
  }
}

