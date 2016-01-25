#include <stdio.h>


//Exercice 1.2.2

int main (){
	unsigned int x, y;
	int i, res;

	printf ("Saisir x\n");
	scanf ("%u", &x);
	printf ("Saisir y\n");
	scanf ("%u", &y);

	res = 0;
	i = x;
	while(i<=y)
	{
		res += i;
		i++;
	}

	printf("Le resultat est : %d \n", res);
	return 0;
}
