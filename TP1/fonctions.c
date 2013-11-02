//NOM et Prénom :
//Code permanent :

#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fonctions.h"
void
signaler_erreur(int err)
{
    switch (err)
    {
        case OUVERTURE_FICHIER_ERREUR :
            fprintf(stderr,"Erreur d'ouverture du fichier.\n");
        break;
        case SYNTAX_DOMAIN_ERREUR :
            fprintf(stderr,"Erreur de syntaxe dans un domaine.\n");
            break;
        case OPTION_INCONNUE_ERREUR :
            fprintf(stderr,"Option inconnue.\n");
            fprintf(stderr,"Usasge : filtre <fichier> [-C <liste>] [-L <liste>]\n");
            fprintf(stderr,"         filtre <fichier> [-L <liste>] [-C <liste>]\n");
            break;
        case OPTION_DUPLIQUEE_ERREUR :
                fprintf(stderr,"Option en double.\n");
                break;
        case FICHIER_SANS_ENTIER_ERREUR :
            fprintf(stderr,"Le fichier ne comporte aucun entier.\n");
            break;
        case TABLEAU2D_VIDE_ERREUR :
            fprintf(stderr,"Tableau vide!\n");
            break;
        default :
            fprintf(stderr,"Erreur inconnue.\n");
            break;
    }

}

void
affiche_Tab2D(int *ptr, int n, int m)
{
    if (n>0 && m>0 && ptr!=NULL)
    {
        int (*lignePtr)[m];

        lignePtr = (int (*)[m]) ptr;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
            {
                printf("%5d ",lignePtr[i][j]);
            }
            printf("\b\n");
        }
    }
    else
    {
        signaler_erreur(TABLEAU2D_VIDE_ERREUR);
    }
}
//Precondition: fp doit être existant et ouvert
int nbre_lignes_fichier(FILE* fp){
    int nbLignes=0;
    int c;
    long tailleFichier=ftell(fp);
    //On signale le fichier vide
    if(tailleFichier!=0){
        while(!feof(fp)){
            c=getc(fp);
            if(c=='\n') nbLignes++;
        }
    }
    else{
        signaler_erreur(FICHIER_SANS_ENTIER_ERREUR);
    }
return nbLignes;

}
int seek_option(char *const argv[], char option){
 //pour prévenir les options dupliquées
 int occurences=0;
 int position=-1;
 //On valide l'option cherchée

 if(option!='L' ||option!='C'){
    signaler_erreur(OPTION_INCONNUE_ERREUR);
    return position;
 }
 else{
    //On contruit alors la chaine d'option (ex -L)
    
    char *tiret= "-";
    size_t len = sizeof(tiret); 
        
    char *optionCherchee = malloc(len + 1 + 1 ); 
    strcpy(optionCherchee , tiret);
       
    optionCherchee [len - 3] = option;
    optionCherchee [len - 2] = '\0';
    int indexArgument=0;
    for (;argv[indexArgument]!=NULL; ++indexArgument)
    {
        int trouve=strcmp(optionCherchee,argv[indexArgument]);
        if(trouve){
            occurences++;
            if(occurences>1){
                signaler_erreur(OPTION_DUPLIQUEE_ERREUR);
                break;
            }
            else position=indexArgument;
        }


        
    }
    
 }
 return position;
}

int check_domaine(char * domaine){
    int erreur;
    //Supporte tous les cas de syntaxe
    const char * expr="(^-{1}[0-9]+$){1}|(^[0-9]+-$)|(^[0-9]+-[0-9]+$)";
    regex_t expressionPtr;
    erreur=regcomp(&expressionPtr,expr,REG_NOSUB | REG_EXTENDED);
    if(erreur==0){
        int matched=regexec(&expressionPtr,domaine,0,NULL,0);
        regfree(&expressionPtr);
        if (matched==0)return 1;



    }
    signaler_erreur(SYNTAX_DOMAIN_ERREUR);
    return 0;
}

    int get_debut_fin_domaine(char * domaine, int max, int *debut, int *fin)
    {
        assert(domaine!=NULL && "le domaine est obligatoire");
        assert(debut!=NULL   && "ECHEC d'une precondition - debut doit etre alloue hors fonction");
        assert(fin!=NULL   && "ECHEC d'une precondition - fin doit etre alloue hors fonction");


        int erreur;
        //cas de domaine : -num
        const char * cas1="(^-{1}[0-9]+$){1}";
        //num-
        const char * cas2="(^[0-9]+-$)";
        //num-num
        const char * cas3="(^[0-9]+-[0-9]+$)";

        regex_t regExPtrCas1,
                regExPtrCas2,
                regExPtrCas3;
            //Compilons d'avance toutes les expressions de domaine possibles
            erreur=regcomp(&regExPtrCas1,cas1,REG_NOSUB | REG_EXTENDED);
        if (erreur==0)erreur=regcomp(&regExPtrCas2,cas2,REG_NOSUB | REG_EXTENDED);
        if (erreur==0)erreur=regcomp(&regExPtrCas3,cas3,REG_NOSUB | REG_EXTENDED);
        //Determinons dans quel cas nous sommes pour ls traiter differement
        int matched=regexec(&regExPtrCas1,domaine,0,NULL,0);
        if (matched==0)
                {

                                *debut=0;
                                int longueur=strlen(domaine)+1;
                    char * finStr=malloc(longueur*sizeof(char));
                    strncpy(finStr,domaine+1,longueur);

                                *fin=(int)atoi(finStr);
                                free(finStr);
                }
                else{

                    matched=regexec(&regExPtrCas2,domaine,0,NULL,0);
                    if (matched==0)
                    {

                                        *fin=(int)max;
                        int longueur=strlen(domaine)+1;
                        char * debutStr=malloc(longueur*sizeof(char));
                        strncpy(debutStr,domaine,longueur-1);

                                        *debut=(int)atoi(debutStr);
                                        free(debutStr);


                    }
                    else{
                        matched=regexec(&regExPtrCas3,domaine,0,NULL,0);
                        if (matched==0)
                        {
                            int longueur=strlen(domaine)+1;
                            char delimiteur[2]="-";
                            /*On convertit la chaîne du domaine en tableau
                            de maniere a  pouvoir utiliser strtok() pour la diviser correctement
                            Sûrement pas la meilleur/plus sécuritaire façon de faire*/
                            char domaineTab[longueur];
                            strncpy(domaineTab,domaine,longueur);
                            char * partie=strtok(domaineTab,delimiteur);


                            *debut=(int)atoi(partie);

                            //On récupère la fin
                            partie=strtok(NULL,delimiteur);
                            *fin=(int)atoi(partie);


                        }
                        else{
                                                //Dans le cas où le domaine est invalide on libère
                                                free(debut);
                                                free(fin);
                            return 1;
                        }
                    }
                }
            return 0;
    }
int get_nbre_domaines(char  *const argv[], int pos){
    assert(pos>=0 && "pos ne doit pas etre negatif");
     int nombreDeParam=sizeof(argv)/sizeof(char);
     char (* argumentsPtr)[nombreDeParam];
     argumentsPtr=(char (*)[nombreDeParam])argv;
     int i=pos;
     int estOptionConnue=-1;
     int nbDoms=0;

     while(*argumentsPtr[i]!=NULL){
        int estC=*argumentsPtr[i]=='-'&&*argumentsPtr[i+1]=='C';
        int estL=*argumentsPtr[i]=='-'&&*argumentsPtr[i+1]=='L';
        estOptionConnue=estC||estL;
        if (estOptionConnue)
        {
            break;
        }
        else{
            nbDoms++;
            i++;
        }

     }
      return nbDoms;
}
/*int *filter(int * mat, int *n, int *m, int *controlC, int *controlL){
    assert (n!=null && m!= null);
    int compteur;

    for(int i =0; i < n; i++){
        compteur =0;

        for(int j =0; j < m; j++){

            if(*mat[i][j] != NULL){
                compteur++;
            }

            if(j == m-1){
                if(compteur == 0){
                //on supprime la ligne
                }
            }
            if(i == n-1){
                if(compteur == 0){
                    //on supprime la colonne
                }
            }
            *tab[i][j] = *mat[n][m];
            
            for(int a =0; a < i; a++){
                for(int b =0; b < j; b++){
                    
     }
    }
}*/

