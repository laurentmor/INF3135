/* exemple3.1.c : generation de plusieurs executables pour un meme fichier source */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LANG
#	define LANG FR
#endif
#define FR 1
#define EN 2
#if LANG==FR
#  define MESSAGE_ERR1 "Usage : toto n" 
#  define MESSAGE_ERR2 "Fournir un nombre positif"
#  define MESSAGE_RES "La racine carree de %f est %f"
#elif LANG==EN
#  define MESSAGE_ERR1 "Usage : toto n" 
#  define MESSAGE_ERR2 "Provide a positive number"
#  define MESSAGE_RES "The square root of %f is %f"
#endif

int main (int argc, char *argv[])
{
        double x;
        if (argc != 2)
                printf(MESSAGE_ERR1);
        else {
	        x = atof(argv[1]);
	        if (x < 0)
	             printf(MESSAGE_ERR2);
	        else
	             printf(MESSAGE_RES,x,sqrt(x));
	}
	printf("\n");
	return 0;
}

