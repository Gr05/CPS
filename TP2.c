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
		/*fprintf(stderr,"Division par 0 impossible\n");
		//return 1;*/
		exit(1);
	}
	else
	{
		printf("On va diviser x par y ... ");
		z = x / y;
		printf("Le resultat est : %d\n", z);
		//return 0;
		exit(0);
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
 /*Dans le cas ou y est égal a 0 on voit apparaitre le message d'erreur Division par 0 impossible
   et lorsque y est différent de 0 nous avons bien "On va diviser x par y ... Lesrésultat : !(&z)"
   l'alternative a ce coode est d'utiliser exit au lieu de return.*/

 /* Question 4 */
 /*On récèpe le code de sortie du 1er programme que l'on exécute pour voir quelle action
   on fait a la suite ./TP1 || ./TP1_b*/


/*--------------------- Exercice 6 ----------------------*/

void exo6 (){
	int x, y, z, i, j, k;
	printf("Saisir x \n");
	scanf("%d", &x);
	printf("Saisir y \n");
	scanf("%d", &y);
	i = x;
	j = y;

	if(y==0)
	{
		fprintf(stderr,"Division par 0 impossible\n");
		//return 1;
		exit(1);
	}
	else
	{
		printf("On va diviser x par y ... \n");
		z = ++x / y;
		printf("Pour ++x : On a x = %d, et z = %d\n", x, z);
		k = i++ / j;
		printf("Pour x++ : On a i = %d, et k = %d\n", i, k);
		//return 0;
		exit(0);
	}
}

/* Question 1 */
/*On voit que la variable x est incrémenté avant le calcul mais i est incrémenté apres
  le calcul*/


/*--------------------- Exercice 7 ----------------------*/

int main (){
	int x, y, z;
	y = 0;
	printf("Saisir x\n");
	scanf("%d", &x);
	printf("On va le diviser par y ...");
	printf("Affiche\nNonAffiche");
	z = x / y;
	printf("Le resultat est : %d\n", z);
	exit (0);
}

/* Question 1 */
/* On devrai avoir ecrit Saisir x, puis "On va le diviser par y ... " une erreur de type "Exception en point flottant"*/

/* Question 2 */
/* L erreur est affichee tout de suite apres la saisie de x, car le buffer correspondant a printf
  n etait pas plein donc il ne l a pas affiche a l ecran, le mode par defaut est line buffered. */

/* Question 3 */
/* Pour pouvoir afficher ce qu'il aurai du être affiché il faut placer un retour a la ligne, pour le buffer stdout soit envoyé
   en ecriture, ou bien on aurai pu changer le mode lors de l'appel de notre exec et le mettre en unbuffered (_IONBF)*/





/*--------------------- Test des progs ----------------------*/

/*int main(){
	
	exo7();
	return 0;
}
*/
