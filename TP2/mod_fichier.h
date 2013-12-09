#ifndef MOD_FICHIER_H
#define MOD_FICHIER_H 
int nombreDeLignes(FILE* fp);
char ** charger(FILE *fp, char *vecteur, int nbLignes, int nbColonnes);
#endif