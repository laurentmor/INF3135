#include <stdio.h>
#include <stdlib.h>

#define EOL "\n"
#define TAILLE_MAX 128

void lireEntree(){
char c;
int count = 0;
while ((c = getc(stdin)) != '\n')
   count++;
    printf("%c", c);
}

int main()
{
    lireEntree();
    return 0;
}

