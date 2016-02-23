#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Pour exercice 5*/
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>


/*--------------------- Exercice 1 ----------------------*/

//Question 1

typedef struct _point_cart{
	float x;
	float y;
} point_cart;

typedef struct _point_pol{
	double r;
	double theta;
} point_pol;

point_pol create(double module, double argument){
	point_pol p;
	p.r = module;
	p.theta = argument;
}

//Question 2

point_cart fct_rt_vers_xy(point_pol p){
	point_cart p1;
	p1.x = p.r * cos(p.theta*M_PI/180);
	p1.y = p.r * sin(p.theta*M_PI/180);
	return p1;
}

void proc_rt_vers_xy(point_pol p, point_cart * p1){
	p1->x = p.r * cos(p.theta*M_PI/180);
	p1->y = p.r * sin(p.theta*M_PI/180);
}

//Question 3

int main_q3 (){
	point_pol p;
	point_cart p1;
	printf("Saisir coordonees polaires :\n");
	scanf("%lf %lf", &p.r, &p.theta);
	p1 = fct_rt_vers_xy(p);
	printf("Voici le point cartsien correspondant\n x=%lf y=%lf\n", p1.x, p1.y);
	return 0;
}

//Question 4

point_cart fct_rt_vers_negXnegY(point_pol p){
	point_cart p1;
	p1 = fct_rt_vers_xy(p);
	p1.x = -p1.x;
	p1.y = -p1.y;
	return p1;
}

point_cart fct_rt_vers_XnegY(point_pol p){
	point_cart p1;
	p1 = fct_rt_vers_xy(p);
	p1.y = -p1.y;
	return p1;
}

point_cart fct_rt_vers_negXY(point_pol p){
	point_cart p1;
	p1 = fct_rt_vers_xy(p);
	p1.x = -p1.x;
	return p1;
}
point_cart from_point_pol (point_cart (*func)(point_pol), point_pol p){
	return func(p);
}

int main_q4 (){
	point_pol p;
	point_cart p1;
	fprintf(stderr, "Saisir coordonnée polaire : ");
	scanf("%lf %lf", &p.r, &p.theta);
	p1 = from_point_pol(fct_rt_vers_xy, p);
	printf("Voici le point cart. correspondant :\n x=%lf, y = %lf\n", p1.x, p1.y);
	p1 = from_point_pol(fct_rt_vers_negXY, p);
	printf("Rotation pour avoir x negatif :\n x=%lf, y = %lf\n", p1.x, p1.y);
	p1 = from_point_pol(fct_rt_vers_XnegY, p);
	printf("Rotation pour avoir y negatif :\n x=%lf, y = %lf\n", p1.x, p1.y);
	p1 = from_point_pol(fct_rt_vers_negXnegY, p);
	printf("Rotation pour avoir x et y negatif :\n x=%lf, y = %lf\n", p1.x, p1.y);
}


/*--------------------- Exercice 2 ----------------------*/
void fact (int x, int *f) //le fonction attend un int et un pointeur sur int en paramètres
{
	int i;
	*f = 1;
	for(i=1; i<=x; i++)
	{
		*f = *f * i; //on utilise la valeur pointée par le pointeur pour faire les calculs
	}
}

int main_exo2 ()
{
	int x, res; //on déclare 2 int 

	printf("Saisir la valeur pour le calcul de factorielle : \n");
	scanf("%d", &x);
	fact(x, &res); //on passe bien un int et l'adresse d'un int (pointeur sur int) en paramètres
	printf ("Factorielle (%d) est %d\n", x, res); //on utilise la var res normalement
	return 0;
}


/*--------------------- Exercice 3 ----------------------*/

//Question 1 
//&t[1] = t+1 -> *(t+1)
//&t[2] = t+2 -> *(t+2)

//Question 2
// int *p = t; *p == t[0]
// p = &x;      *p == x
// *p = 371;   x == 371
// t = p;      invalid
// p = &y;     *p == y

// Question 3 

int main (){
	int t[7];
	int x = 5;
	int y = 36;

	printf("t : %p\nt + 1 : %p\n&t[1] : %p\nt + 2 : %p\n&t[2] : %p\n*(t+1) : %d\n*(t+2) : %d\n", t, t+1, &t[1], t+2, &t[2], *(t+1), *(t+2));

	int *p = t; printf("*p = %d, t[0] = %d\n", *p, t[0]);
	p = &x; printf("*p = %d, x = %d\n", *p, x);
	*p = 371; printf("x = %d\n", x);
	//t = p; erreur a la compilation 
	

}


/*--------------------- Exercice 4 ----------------------*/

void g()
{
	int n; //si on change de type ce n'est plus vrai
	n = 22;
}

void f()
{
	int compteur;
	compteur ++;
	printf("f --> %d\n", compteur);
}

void daffile (int * p)
{
	int * psuiv;
	psuiv = p + 1; //on avance d'une taille de int dans la pile
	*psuiv = *psuiv + 1;
	printf("La valeur qui suit l'adresse de (%p) est : %d\n", p, *psuiv);
}

int main ()
{
	int x,y; //avec ces 2 lignes on voit bien que ce processus a une pile independante
	y = 10;  //et que les variables sont adressees dans l'ordre d'apparition dans le prgm
	f();
	g();
	f();
	daffile(&x);
}

/*
Explication : on voit que l'on a pas des valeurs aléatoires à l'exécution. Lors du 1er appel
de f() la variable compteur vaut 1 et pour le 2nd appel cette variable vaut 23.
-Pour le 1er appel on suppose que c'est l'effet du compilateur qui met à 0 toute les variables non initialise.
-Et pour le second appel on l'explique par l'utilisation de la pile propre a chaque programme,
donc lorsque g() est appelé l'adresse de sa variable n est a la meme adresse que compteur qui
on a "n = 22" puis lorsque f() est appelé comme compteur n'est pas initialise la variable a donc
la même valeur que ce qu'il y avait avant.
Il faut donc que les adresse pointent sur la même case (position + type).
*/

/*--------------------- Exercice 5 ----------------------*/

 main(int argc, char *argv[])
 {
    char read, write, exec;
    struct stat sb;

    if (argc != 2) {
       printf("Il n'y a pas le bon nombre d'arguments\n");
       exit(EXIT_FAILURE);
    }

    if (stat(argv[1], &sb) == -1) {
       perror("stat");
       exit(EXIT_SUCCESS);
    }

    printf("Type de fichier :                ");
    switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:  printf("périphérique bloc\n");       break;
    case S_IFCHR:  printf("périphérique caractère\n");  break;
    case S_IFDIR:  printf("répertoire\n");              break;
    case S_IFIFO:  printf("FIFO/tube\n");               break;
    case S_IFLNK:  printf("lien symbolique\n");         break;
    case S_IFREG:  printf("fichier ordinaire\n");       break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("inconnu ?\n");               break;
    }

    printf("Voici ses permissions :\n");

    /*on cherche les permission de user*/
    if (sb.st_mode & S_IRUSR) {read = 'r';}
    else {read = '-';}
    if (sb.st_mode & S_IWUSR) {write = 'w';}
    else {write = '-';}
    if (sb.st_mode & S_IXUSR) {exec = 'x';}
    else {exec = '-';}
    printf("User : %c%c%c\n", read, write, exec); //on affiche permission de user

    /*group*/
    if (sb.st_mode & S_IRGRP) {read = 'r';}
    else {read = '-';}
    if (sb.st_mode & S_IWGRP) {write = 'w';}
    else {write = '-';}
    if (sb.st_mode & S_IXGRP) {exec = 'x';}
    else {exec = '-';}
    printf("Group : %c%c%c\n", read, write, exec);

    /*other*/    
    if (sb.st_mode & S_IROTH) {read = 'r';}
    else {read = '-';}
    if (sb.st_mode & S_IWOTH) {write = 'w';}
    else {write = '-';}
    if (sb.st_mode & S_IXOTH) {exec = 'x';}
    else {exec = '-';}
    
    printf("Other : %c%c%c\n", read, write, exec);

 }