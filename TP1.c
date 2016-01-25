#include <stdio.h>

/*--------------------- Exercice 1 ----------------------*/

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

/* Question 2 */

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

/* Question 3 */

void calcul_terme_choix(){
	int u;
	int n;
	printf("Veuillez choisir le parametre u0 puis le parametre n\n");
	scanf("%d %d", &u, &n);
	printf("u%d=%d\n", n, calcul_terme_general(u, n));
}

/*--------------------- Exercice 2 ----------------------*/

/* Question 1*/
/*Mon ordinateur peut calculer les factorielles jusqu'à 13 (type : int)*/

/* Question 2 */
int factoriel (int n)
{
	
	if(n == 1 || n == 0)
	{
		return 1;
	}
	return n * factoriel (n - 1);
}

void exo2 ()
{
	int fact, res;
	printf("Saisir le nombre\n");
	scanf("%d", &fact);
	res = factoriel(fact);
	printf("La factorielle est : %d\n", res);
}

int main(){
	calcul_terme_choix();
	return 0;
}

