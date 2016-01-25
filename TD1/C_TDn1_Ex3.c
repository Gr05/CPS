#include <stdio.h>

//Exercice 3

int main (){
	int x, res;


	printf ("Saisir x\n");
	scanf ("%d", &x);
	
	res = 1;

	while(x > 0)
	{
		res *= x;
		x--;
	}
	printf("La factorielle est : %d\n", res);

	return 0;
}