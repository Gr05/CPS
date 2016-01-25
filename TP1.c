#include <stdio.h>

/* Exercice 1 */

/* Question 1 */ 

int calcul_terme (int n){
	int u = 1;
	int i = 1;
	while (i<=n){
		u = 3*u + 2;
		i++;
	}
	return u;
}

int main(){
	printf("u0 = %u\n", calcul_terme(0));
	return 0;
}