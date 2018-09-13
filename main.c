#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

/*#define uniPrix 39.00;*/

int main(void)
	{
	float uniPrix = 39.00;
	float nbreArticles = 1.00; 				//Nombre d'articles à loot
	float prixHT = 0.00;				//Prix total Hors-Taxes
	float prixTTC = 0.00;				//Prix total Toutes Taxes Comprises
	float oui = 0.00;
	printf("Bonjour\n");
	printf("Combien d'articles comptez-vous acheter ?\n");
	scanf(" %d", &nbreArticles);
	oui = uniPrix * nbreArticles;
	printf("Le prix HT est de: %9.6f\n", oui);
	printf("\n\n")
	return 0;
	}
