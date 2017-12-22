/******************************************************************************/
/* POLYNOMES_H                                                                */
/******************************************************************************/

#ifndef POLYNOMES_H
#define POLYNOMES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMONOME 50




/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
typedef struct monome {
    int coeff;
    int degre;
    } Monome;

typedef struct polynome {
    Monome      tab_monomes[MAXMONOME];
    int         nb_monomes;
    } Polynome;




/******************************************************************************/
/* PROTOTYPES                                                                 */
/******************************************************************************/
void initPolynome(Polynome *);

void affichePolynome(Polynome);
void affichePolynomeNega(Polynome p, int i);
void affichePolynomePosi(Polynome p, int i);

void multiplieMonomePolynome(Polynome *p, Monome m);
int multiplieMonomePolynome_coeff(int monoCOEFF, int polyCOEFF);
int multiplieMonomePolynome_degre(int monoDEGRE, int polyDEGRE);


void ajouteMonomePolynome(Polynome *p, Monome m);
void ajouteMonomePolynome_YAPASDEGRE(Polynome *p, Monome m);


void ajouterPolyPolyPolynesie1(Polynome *p, Polynome pBis);


void multipliePolynomePolygamie(Polynome *p, Polynome pBis);



int normaliserTermes(Polynome p, int i);

void standardiseDescription(char *s, char *d);
void str2Polynome(char *str,Polynome *p);

















#endif

