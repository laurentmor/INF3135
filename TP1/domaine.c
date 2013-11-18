regex_t regExValide(char * expression);

regex_t regExValide(char * expression){
//TODO
    assert(expression!=NULL && "le domaine est obligatoire");
    regex_t regExPtr;
    int erreur=regcomp(&regExPtr,expression,REG_NOSUB | REG_EXTENDED);
    if(erreur==0){
        return regExPtr;
    }
    return NULL; 
}



int check(char * domaine){
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

    int get_debut(char * domaine,  int *debut)
    {
        assert(domaine!=NULL && "le domaine est obligatoire");
        assert(debut!=NULL   && "ECHEC d'une precondition - debut doit etre alloue hors fonction");
        


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

     while(argumentsPtr[i]!=NULL){
        int estC=strcmp("-C",argumentsPtr[i]);
        int estL=strcmp("-L",argumentsPtr[i]);
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