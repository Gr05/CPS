/**********TP6**********/
/**********Exo1*********/
/***Simon CHAMBONNET****/
/*****Lucas GUERRY******/


#include <stdio.h> 
#include <stdlib.h> //pour srand
#include <math.h>

/*bibliothèques nécessaire pour exploiter les propriétées d'un fichier*/
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h> //pour srand
 
#define BORNEINF 125
#define BORNESUP 250
#define N 500
/*--------------------- Exercice 1 ----------------------*/



int recherche (int x, int *tabl, int taille)
{
	int i;
	i = 0;
	while (i < taille)
	{
		if (tabl[i] == x)
		{
			return i;
		}
		i++;
	}
	return -1;
}

/* void init (int *tabl, int taille)
{
	int i;

	i = 0;

	while (i < taille)
	{
		tabl[i] = (rand () % (BORNESUP - BORNEINF + 1) + BORNEINF);
		i++;
	}
} */

int * init (int taille){
	int * tableau = malloc(taille * sizeof(int));
	return tableau; 
}

int main ()
{
	int tabint [N];
	int cherche, res;

	srand(time(0));

	init (tabint, N);
	cherche = (rand () % (BORNESUP - BORNEINF + 1) + BORNEINF);
	res = recherche(cherche, tabint, N);

	if (res != -1)
	{
		printf("Le nombre %d est à l'indice %d du tableau.\n", cherche, res);
		printf("Le chiffre à l'indice %d est %d\n", res, tabint[res]);
	}
	else
	{
		printf("Le nombre %d n'est pas dans le tableau.\n", cherche);
	}
	return 0;
}
