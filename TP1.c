#include <stdio.h>
#include <stdlib.h>

/*--------------------- Exercice 1 ----------------------*/

/* Question 1 */ 

int calcul_terme_general (int u0, int n){
	int u = u0;
	int i = 1;
	while (i<=n){
		u = 3*u + 2;
		i++;
	}
	return u;
}
int calcul_terme ( int n ){
	return calcul_terme_general(1, n);
}

/* Question 2 */

void afficher_terme (){
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
/*Mon ordinateur peut calculer les factorielles jusqu'à 12 (type : int) et fact 13 > 2^31*/

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
	int n;
	printf("Saisir le nombre\n");
	scanf("%d", &n);
	printf("La factorielle est : %d\n", factoriel(n));
}


/*--------------------- Exercice 3 ----------------------*/

int compte (int x)
{
	int i;
	for(i=1; i<=4; i++)
		x = x * i;
	return x;
}

void exo3 ()
{
	int k;
	printf("Saisir la valeur pour le calcul : \n");
	scanf("%d", &k);
	printf("La fonction renvoie %d et k vaut maintenant %d\n", compte(k), k);
}

/*C'est affiché k fois la factorielle de 4 et on voit que k n'est pas modifié
contrairement a ce que l'on pourrai penser qu'il est modifié pour la ligne x = x * i*/



/*--------------------- Exercice 4 ----------------------*/

void un_switch (char c){
	switch(c){
		case '@': case '.': printf("caractere qui peux ce trouver dans une adresse mail\n");
		break;
		case '/': printf("Caractere qui peutse trouver dans une adresse http\n");
		break;
		case '<': case '>': case '=': printf("Caractere de comparaison\n");
		break;
		default: 
		if ( c>= 'A' && c <= 'Z'){
			printf("Lettre majuscule\n");
		} else if( c>='0' && c<='9'){
			printf("Chiffres\n");
		} else {
			printf("Autre caractere\n");
		};
		break;
	}
}


/*--------------------- Exercice 5 ----------------------*/

void exo5 ()
{
	int x, y, z;
	printf("Saisir x \n");
	scanf("%d", &x);
	printf("Saisir y \n");
	scanf("%d", &y);

	if(y==0)
	{
		fprintf(stderr,"Division par 0 impossible\n");
		exit(0);
	}
	else
	{
		printf("On va diviser x par y ... ");
		z = x / y;
		printf("Le resultat est : %d\n", z);
	}
}

/* Question 1 */
/*On s'attend à ce que lorsque l'on affect y à 0 ça affiche "Division par 0 impossible",
et pour tout autre valeur de y on est le resultat casté en int de la divison.*/

/* Question 2 */
/*A l'exécution on voit que pour toute valeur de y on a le message d'erreur
 "Exception en point flottant", en faisant le if (y=0) on réalise une affection
 et pas une comparaison, une affectation doit renvoyer une autre valeur que 1
 et on passe dans le else et on fait la division avec y qui vaut 0. Donc il faut écrire "=="*/

 /* Question 3 */

 /* Question 4 */









/*--------------------- Exercice 6 ----------------------*/

int main(){
	int i;
	for (i = 0; i<= 255; i++){
		printf("%c ", i);
		un_switch(i);
	}
	return 0;
}

