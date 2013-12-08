#ifndef MOD_CMD_H
#define MOD_CMD_H
#define OPTION_LIGNE 'L'
#define OPTION_COLONE 'C'
#define OPTION_FUSION_VERTICALE 'V'
#define OPTION_FUSION_HORIZONTALE 'H'

int nombreArguments(char *const argv[]);
int chercherOption(char *const argv[],char option);
#endif