/******************************************************************************/
/* POLYNOMES_C                                                                */
/******************************************************************************/

//toutes déclarations dans le fichier .h
#include"polynomes.h"

/******************************************************************************/
/* main                                                                       */
/******************************************************************************/
int main(void)
{
	system("clear");
    Polynome p;
    Polynome pBis;
    
    initPolynome(&p);
    str2Polynome("4x^5+7X^3-2",&p);
    str2Polynome("3x^2+4X^3", &pBis);
    printf("Polynome a vif:\n");
    affichePolynome(p);  // NE FAIT RIEN TANT QUE VOUS N'AUREZ PAS ECRIT LA FX!
    printf("\n");
    Monome leMonome;
    leMonome.coeff = 2;
    leMonome.degre = 2;
    multiplieMonomePolynome(&p, leMonome);
    printf("Polynome apres Prophase et Metaphase:\n");
    affichePolynome(p);
    leMonome.degre = 2;
    leMonome.coeff = 2;
    printf("\n");
    printf("%d\n", p.nb_monomes);
    ajouteMonomePolynome(&p, leMonome);
    printf("Polynome apres Anaphase et Telophase:\n");
    affichePolynome(p);
    printf("\n");
    ajouterPolyPolyPolynesie1(&p, pBis);
    printf("Polynome apres meiose:\n");
    affichePolynome(p);
    
    

    return 0;
}

/******************************************************************************/
/* initPolynomes - initialise le polynome fourni                              */
/*                                                                            */
/* INPUT  : polynome (pointeur) à initialiser                                 */
/* OUTPUT : néant                                                             */
/******************************************************************************/
void initPolynome(Polynome *p)
{
    p->nb_monomes = 0;
}





/******************************************************************************/
/* affichePolynome - self explained                                           */
/*                                                                            */
/* INPUT  : polynome à afficher                                               */
/* OUTPUT : néant                                                             */
/******************************************************************************/
void affichePolynome(Polynome p)
{	
	int i;
	printf("Le polynome est: ");
	for(i=0;i<=p.nb_monomes-1;i++)
		{
		if(p.tab_monomes[i].coeff<0)
			{
			affichePolynomeNega(p, i);
			}
		else
			{
			affichePolynomePosi(p, i);
			}
		}
	printf("\n");
}


void affichePolynomeNega(Polynome p, int i)
	{
	if(i>0)
		{
		
		}
	else
		{
		
		}
	if(p.tab_monomes[i].degre != 0)
		{
		if(p.tab_monomes[i].coeff!=0 && p.tab_monomes[i].degre!=1 && p.tab_monomes[i].degre!=0)
			{
			printf("%dX^%d", p.tab_monomes[i].coeff, p.tab_monomes[i].degre);
			}
		else if(p.tab_monomes[i].degre==0)
			{
			printf("%d", p.tab_monomes[i].coeff);
			}
		else if(p.tab_monomes[i].degre==1)
			{
			printf("%dX", p.tab_monomes[i].coeff);
			}
		}
	else
		{
		printf("%d", p.tab_monomes[i].coeff);
		}
	return;
	}

void affichePolynomePosi(Polynome p, int i)
	{
	if(i>0)
		{
		printf("+");
		}
	else
		{
		
		}
	if(p.tab_monomes[i].degre != 0)
		{
		if(p.tab_monomes[i].coeff!=0 && p.tab_monomes[i].degre!=1 && p.tab_monomes[i].degre!=0)
			{
			printf("%dX^%d", p.tab_monomes[i].coeff, p.tab_monomes[i].degre);
			}
		else if(p.tab_monomes[i].degre==0)
			{
			printf("%d", p.tab_monomes[i].coeff);
			}
		else if(p.tab_monomes[i].degre==1)
			{
			printf("%dX", p.tab_monomes[i].coeff);
			}
		}
	else if(p.tab_monomes)
		{
		
		}
	return;
	}



/*****************************************************************************
************************ Multiplication d'un polynome par un monome***********
*****************************************************************************/

void multiplieMonomePolynome(Polynome *p, Monome m)
	{
	int i = 0;
	while(i<p->nb_monomes)
		{
		p->tab_monomes[i].coeff = multiplieMonomePolynome_coeff(m.coeff, p->tab_monomes[i].coeff);
		p->tab_monomes[i].degre = multiplieMonomePolynome_degre(m.degre, p->tab_monomes[i].degre);
		i += 1;
		}
	}


int multiplieMonomePolynome_coeff(int monoCOEFF, int polyCOEFF)
	{
	int produitPolyMono;
	produitPolyMono = polyCOEFF * monoCOEFF;
	return produitPolyMono;
	}


int multiplieMonomePolynome_degre(int monoDEGRE, int polyDEGRE)
	{
	int produitPolyMono;
	produitPolyMono = polyDEGRE + monoDEGRE;
	return produitPolyMono;
	}






/*##############################################################################
##################################AJOUTE MONOME ET POLYNOMES####################
##############################################################################*/


void ajouteMonomePolynome(Polynome *p, Monome m)
	{
	int i = 0;
	int hahahayapasdedegrejelaiprismonprecieuxdegre = 0;
	while(i<=p->nb_monomes)
		{
		printf("Ici, le monome est %dX^%d\n\n", m.coeff, m.degre);
		if(p->tab_monomes[i].degre==(m.degre))
			{
			p->tab_monomes[i].coeff = p->tab_monomes[i].coeff + m.coeff;
			hahahayapasdedegrejelaiprismonprecieuxdegre = -1;
			}
		if(i==p->nb_monomes && p->tab_monomes[i].degre != (m.degre) && hahahayapasdedegrejelaiprismonprecieuxdegre == 0)
			{
			hahahayapasdedegrejelaiprismonprecieuxdegre = 1;
			break;
			}
		i++;
		}
	if(hahahayapasdedegrejelaiprismonprecieuxdegre == 1)
		{
		ajouteMonomePolynome_YAPASDEGRE(p, m);
		}
	}

void ajouteMonomePolynome_YAPASDEGRE(Polynome *p, Monome m)
	{
	Monome remplacement [MAXMONOME];
	int i=0;
	int j=0;
	int k=0;
	printf("\n\n\nNous sommes dans ajouteMonomePolynome\n\n");
	printf("Ici, le monome est %dX^%d\n\n", m.coeff, m.degre);
	while(i<p->nb_monomes)
		{
		if(p->tab_monomes[i].degre > m.degre)
			{
			if(p->tab_monomes[i+1].degre < m.degre)
				{
				remplacement[i+1].coeff = m.coeff;
				remplacement[i+1].degre = m.degre;
				i++;
				break;
				}
			}
		i++;
		}
	printf("valeur de i: %d\n", i);
	printf("valeur de p pour i: %dX^%d\n\n", p->tab_monomes[i].coeff, p->tab_monomes[i].degre);
	while(j<=p->nb_monomes)
		{
		if(j==i)
			{
			k=j;
			break;
			}
		else
			{
			remplacement[j].degre = p->tab_monomes[j].degre;
			remplacement[j].coeff = p->tab_monomes[j].coeff;
			}
		j++;
		}
	printf("Monome en i: %d^%d\nPolynome en i: %dX^%d\n\n", remplacement[i].coeff, remplacement[i].degre, p->tab_monomes[i].coeff, p->tab_monomes[i].degre);
	printf("Monome en k: %dX^%d\n\n", m.coeff, m.degre);
	remplacement[k].degre = m.degre;
	remplacement[k].coeff = m.coeff;
	printf("Monome en k: %dX^%d\n\n", m.coeff, m.degre);
	printf("valeur de k: %d\n", k);
	for(j=0;j<p->nb_monomes+1;j++)
		{
		printf("Position j=%d, il y a: %d^%d \n", j, remplacement[j].coeff, remplacement[j].degre);
		}
	for(j=0;j<p->nb_monomes+1;j++)
		{
		p->tab_monomes[j].coeff = remplacement[j].coeff;
		p->tab_monomes[j].degre = remplacement[j].degre;
		}
	}


/*######################################################################
######################AJOUTER POLYNOMYPOLYNOME#####################
######################################################################*/

void ajouterPolyPolyPolynesie1(Polynome *p, Polynome pBis)
	{
	int i = 0;
	for(i=0;i<pBis.nb_monomes;i++)
		{
		ajouteMonomePolynome(p, pBis.tab_monomes[i]);
		}
	}












/******************************************************************************/
/* standardiseDescription - ajoute des + devant les -, vire les char étranges */
/* et change 'x' en 'X', remplace X par 1X                                    */
/*                                                                            */
/* INPUT : s est la chaîne source (celle qui contient une description         */
/* réduite du polynôme                                                        */
/*         d est la chaîne de destination dans laquelle on ecrit              */
/* une description standardisée                                               */
/* OUPUT : néant                                                              */
/******************************************************************************/
void standardiseDescription(char *s, char *d)
{
    char *l=s, *e=d;
    //l pointeur qui lit la chaîne source
    //e pointeur qui écrit la chaîne destination

    while(*l!='\0')
    {
        if(*l=='-')  //remplacer - par +-
        {
            *e = '+';
            e++;
            *e = '-';
        }
        else
        {
            if(*l=='x' || *l=='X')  // X ou x
            {
                if(*(l-1)<'0' || *(l-1)>'9') // ...non précédé d'un chiffre
                {
                    *e='1';
                    e++;
                    *e='X';
                }
                else
                    *e = 'X';
            }
            // autre cas on recopie
            else if((*l>='0' && *l<='9') || *l=='+' || *l=='^')
                *e = *l;
            else // caractères erronés
            {
                e--; // on recule
                if (*l!=' ') // et on signale (sauf si espace)
                    fprintf(stderr,"Err: caractère '%c' ignoré\n",*l);
            }
        }

        e++;
        l++;
    }
    *e = '\0'; // fin de chaîne
}






/******************************************************************************/
/* str2Polynome - lit un polynome dans une string et charge un Polynome       */
/* format pour écrire les polynômes                                           */
/*     X^3 - X - 1, 1X^3 - 1X^1 - 1 sont acceptés                             */
/*                                                                            */
/* INPUT  : str chaîne de caractères qui décrit le polynôme                   */
/*          p   polynôme dans lequel écrire le résultat                       */
/* OUTPUT : néant                                                             */
/******************************************************************************/
void str2Polynome(char *str,Polynome *p)
{
    char *tok, *ptr;
    int coeff, degre;
    int nb_monomes = 0;


    //on commence par standardiser la description
    //dans une chaîne assez longue pur la contenir
    char *str2 = (char *) malloc(strlen(str)+50);

    //la nouvelle description
    standardiseDescription(str,str2); // Nettoie et normalise

    tok = strtok(str2,"+"); // Récupération d'un "token" grâce au séparateur +

    while(tok!=NULL)
        {
        ptr=strchr(tok,'X'); // Y a-t-il un X dans le token?
        if(ptr) // Oui, il y a un X
            {
            //Y a-t'il un '^nombre' derriere le X
            if(sscanf(tok,"%dX^%d",&coeff,&degre)!=2) // Cas 5X^2
                {
                if(sscanf(tok,"%dX%d",&coeff,&degre) != 2) // Cas 5X2
                    {
                    if((sscanf(tok,"X%d",&degre) == 1) || (sscanf(tok,"X^%d",&degre) == 1)) // Cas X2 ou X^2
                        coeff = 1;
                    else if (sscanf(tok,"%dX",&coeff)==1) // Cas 5X
                        degre = 1;
                    else // ...sinon on considère qu'il s'agit de X
                        {
                        coeff = 1;
                        degre = 1;
                        }
                    }
                }
            }
        else // Pas de X
            {
            sscanf(tok,"%d",&coeff);
            degre = 0;
            }
        p->tab_monomes[nb_monomes].coeff = coeff;
        p->tab_monomes[nb_monomes].degre = degre;
        nb_monomes++;

        tok = strtok(NULL,"+");
    }

    p->nb_monomes = nb_monomes;
    free(str2);
}
