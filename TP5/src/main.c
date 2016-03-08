/**********TP5**********/
/***Simon CHAMBONNET****/
/*****Lucas GUERRY******/

#include <stdio.h>
#include <stdlib.h>

#define NMAX 200

/*--------------------- Exercice 1 ----------------------*/

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

