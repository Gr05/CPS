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

/*Question 2*/

int afficher_terme (){
	int n = 0;
	printf("Saisissez des entier positif, entrez -1 pour quitter\n");
	while ( n != -1){
		scanf("%d", &n);
		if (n != -1) {
			printf("u%d = %d\n", n, calcul_terme(n));
		}
	}
}

int main(){
	afficher_terme();
	return 0;
}
