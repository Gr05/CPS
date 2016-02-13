#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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