/**********TP4**********/
/***Simon CHAMBONNET****/
/*****Lucas GUERRY******/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*bibliothèques nécessaire pour exploiter les propriétées d'un fichier*/
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>


/*--------------------- Exercice 1 ----------------------*/

/*Fonction my_strlen*/
int my_strlen (char * chaine)
{
	int i = 0;
	while (*chaine++)
	{
		i++;
	}
	return i;
}