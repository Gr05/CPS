#include <stdio.h>
#include <math.h>


//Exercice 2

int main (){
	int x, y;
	float M, N, PPCM, entier_f;
	int i, entier;


	printf ("Saisir x\n");
	scanf ("%d", &x);
	printf ("Saisir y\n");
	scanf ("%d", &y);

	M = x;
	N = y;
	if(x>y)
	{
		M = y;
		N = x;
	}

	i = 1;
	do{
		PPCM = M*i;
		i++;

		entier = (int) PPCM/N;
		entier_f = (float) entier;

	}while(PPCM/N != entier_f);

	printf("Le PPCM est %d \n", (int)PPCM);

	return 0;
}