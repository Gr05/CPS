/**********TP6**********/
/**********Exo2*********/
/***Simon CHAMBONNET****/
/*****Lucas GUERRY******/


#include <stdio.h> 

int x = 10000;

void f ()
{
	fprintf(stdout, "---> x = %d\n", x);
	x = x / (x-x);
}

int main ()
{
	f();
	return 0;
}