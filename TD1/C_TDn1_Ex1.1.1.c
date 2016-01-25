#include <stdio.h>


//Exercice 1.1.1
int main (){
	unsigned int x;
	int i, res;

	printf ("Saisir x\n");
	scanf ("%u", &x);

	res = 0;
	for(i=0; i<=x; i++)
	{
		res += i;
	}

	printf("Le resultat est : %d \n", res);
	return 0;
}

