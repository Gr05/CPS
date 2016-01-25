#include <stdio.h>

//Exercice 5

int main (){
	int inf, sup, start;

	printf("Saisir borne inférieure, puis borne supérieure\n");
	scanf("%d", &inf);
	scanf("%d", &sup);
	
	start = inf + ((inf+1)%3 + (inf+2)%3)%3;

	while (start <= sup)
	{
		printf("%d ", start);
		start += 3;
	}
	printf("\n");
	
	return 0;
}
