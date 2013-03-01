#include <stdio.h>

void transposer(int A[2][2])
{

int I,J,AIDE;
 
 for (I=0; I<2; I++)
     for (J=0; J<I; J++)
         {
          AIDE = A[I][J];
          A[I][J] = A[J][I];
          A[J][I] = AIDE;
         }
}

void afficherM(int M[2][2])
{

int J,I;

 for (I=0; I<2; I++)
    {
     for (J=0; J<2; J++)
          printf("%7d", M[I][J]);
     printf("\n");
    }
}



int main()
{
 
 int A[2][2]={{1,5},{2,4}}; 
 int I, J;      
 int AIDE;       
    
 printf("Matrice donnee :\n");
 afficherM(A);
 printf("Matrice resultat :\n");
 transposer(A);
 afficherM(A);
 return 0;
}
