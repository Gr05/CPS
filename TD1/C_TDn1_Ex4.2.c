#include <stdio.h>

//Exercice 4.2

int main (){
	int x, res, i, envi;
	
	res = 0;
	i = 0;

	do
	{
		do
		{
			printf ("Saisir x\n");
			scanf ("%d", &x);
		}while(x<0);
		if ((x%2) == 0)
		{
			res ++;
		}
		i++;
		printf("Voulez vous continuer ?\n");
		scanf("%d", &envi);
	}while(envi);
	printf("La factorielle est : %d\n", res);

	return 0;
}