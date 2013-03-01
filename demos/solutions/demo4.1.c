#include <stdio.h>


 
void transposer(int A[2][2], int B[2][2])
{

int I,J;
  for (I=0; I<2; I++)
  {
     for (J=0; J<2; J++)
	    {
          B[J][I]=A[I][J];
	    }	  
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
 int B[2][2] ; 
 int I, J;       
 
 printf("Matrice donnee :\n");
 afficherM(A);
 transposer(A,B);
 printf("Matrice resultat :\n");
 afficherM(B);
 return 0;
} 
