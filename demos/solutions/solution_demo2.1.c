
#include <stdio.h>
int calcule (int, int, char);

int main() {
	printf("5 + 8 = %d\n", calcule(5,8,'+'));
	printf("5 ? 8 = %d\n", calcule(5,8,'?'));
	printf("5 - 8 = %d\n", calcule(5,8,'-'));
	printf("5 / 8 = %d\n", calcule(5,8,'/'));
	printf("5 / 0 = %d\n", calcule(5,0,'/'));
	return(0);
}

int calcule (int operande1, int operande2, char operateur) {
	switch (operateur) {
		case '+' :
			return operande1 + operande2;
		case '-' :
			return operande1 - operande2;
		case '*' :
			return operande1 * operande2;
		case '/' :
			if (operande2 != 0) 
				return operande1 / operande2;
			else {
				printf("Erreur : division par zero\n");
				return 0;
			}
		default : 
			printf("Erreur : operateur %c non-defini\n", operateur);
			return 0;
	}
}
