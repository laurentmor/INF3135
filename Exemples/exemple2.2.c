/* Exemple2.2.c : longueur d'une chaine de caracteres */

#include <stdio.h>
unsigned longueur(char a[]);

int main()
{
	char chaine[]= "";
	char chaine1[]= "toto";
	char chaine2[]= "\"chaine de caracteres\"";
	printf("%s est de longueur %d\n", chaine, longueur(chaine));
	printf("%s est de longueur %d\n", chaine1, longueur(chaine1));
	printf("%s est de longueur %d\n", chaine2, longueur(chaine2));
	return 0;
}
			
unsigned longueur(char a[]){
	unsigned l = 0;
	while(a[l] != '\0')
		l++;
	return l;
}
