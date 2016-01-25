#include <stdio.h>

//Exercice 1.1.1
int main (){
	unsigned int x;
	int i, res;

	printf ("Saisir x\n");
	scanf ("%u", &x);

	res = 0;
	i = 0;
	while(i<=x)
	{
		res += i;
		i++;
	}

	printf("Le resultat est : %d \n", res);
	return 0;
}
