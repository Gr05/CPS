#include <stdio.h>

//Exercice 4.1

int main (){
	int x, res, i;
	
	res = 0;
	i = 0;

	while(i < 10)
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
	}
	printf("La factorielle est : %d\n", res);

	return 0;
}