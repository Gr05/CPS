#include <stdio.h>

//Exercice 6

int main (){
	int x, max, min, i, envi;
	
	max = 0;

	i = 0;

	do
	{
		do
		{
			printf ("Saisir x\n");
			scanf ("%d", &x);
		}while(x<0);
		if (max<x)
		{
			max = x;
		}
		i++;
		printf("Voulez vous continuer ?\n");
		scanf("%d", &envi);
	}while(envi);
	printf("La maximum est : %d\n", max);

	min = max;
	do
	{
		do
		{
			printf ("Saisir x\n");
			scanf ("%d", &x);
		}while(x<0);
		if (min>x)
		{
			min = x;
		}
		i++;
		printf("Voulez vous continuer ?\n");
		scanf("%d", &envi);
	}while(envi);

	printf("Le minimum est : %d\n", min);

	return 0;
}