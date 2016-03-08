/**********TP5**********/
/***Simon CHAMBONNET****/
/*****Lucas GUERRY******/

#include <stdio.h>
#include <stdlib.h>

#define NMAX 200

/*--------------------- Exercice 1 ----------------------*/

void init_crible (int * c, int n, int tailleMax);
int present (int k, int * c);
void suppression (int k, int * c);
void construit_crible (int * c, int taille, int n);


int main ()
{
	int crible [NMAX];
	int n, i;

	printf("Choisir N compris entre 0 et %d : \n", NMAX-1);
	scanf("%d", &n);
	while (!(n < NMAX) || n < 0)
	{
		printf("Le N choisi est trop grand : \n");
		scanf("%d", &n);
	}

	construit_crible(crible, NMAX, n);

	i = 0;
	printf("Les nombres premiers entre 0 et %d sont :\n", n);
	while (i <= n)
	{
		if (crible[i])
		{
			printf("%d ", i);
		}
		i++;
	}
}

void init_crible (int * c, int n, int tailleMax)
{
	int i = 2;
	c[0] = c[1] = 0;
	if (!(n <= 2))
	{
		while (i <= n)
		{
			c[i] = 1;
			i++;
		}
		while (i < tailleMax)
		{
			c[i] = 0;
			i++;
		}	
	}
}

int present (int k, int * c)
{
	return c[k];
}

void suppression (int k, int * c)
{
	c[k] = 0;
}

void construit_crible (int * c, int taille, int n)
{
	int num, numToDel;

	init_crible(c, n, taille);
	num = 2;
	while (num <= n)
	{
		if (present(num, c))
		{
			numToDel = num * 2;
			while(numToDel <= n)
			{
				suppression(numToDel, c);
				numToDel += num;
			}	
		}
		num++;
	}
}