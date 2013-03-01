/* 
 * File:   demo2.h
 * Author: laurent
 *
 * Created on 28 février 2013, 19:39
 */

#ifndef DEMO2_H
#define	DEMO2_H

#ifdef	__cplusplus
extern "C" {
#endif

    int calcule(int operande1, int operande2, char operateur);
    void minMax(int entiers[]);
    void inverse(int a[], int taille);
    void echange(int *i,int *j);
    void affiche_vecteur_int(int a[], int taille);


#ifdef	__cplusplus
}
#endif

#endif	/* DEMO2_H */

