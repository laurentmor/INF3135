/* Exemple5.10.c : Calcul de dérivée de fonctions */
#include <stdio.h>
#include <math.h>
#define PAS 0.00001

double derivee(double (*f) (double), double x);
double carre(double x);

int main ()
{
	printf("Derivee de sin pour x = 0 : %f\n", derivee(sin, 0));
	printf("Derivee de cos pour x = 0 : %f\n", derivee(cos, 0));
	printf("Derivee de exp pour x = 0 : %f\n", derivee(exp, 0));
	printf("Derivee de x^2 pour x = 3 : %f\n", derivee(carre, 3));
	return 0;
}

double derivee(double (*f) (double), double x){
	return ((*f)(x+PAS)-(*f)(x))/PAS;
}

double carre(double x) {
	return x*x;
}
