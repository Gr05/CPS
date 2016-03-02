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

/*Fonction my_strcat*/

char * my_strcat(char * s1, char * s2){
	char * res = (char *) malloc(my_strlen(s1) + my_strlen(s2) + 1);
	char * current_char = res;
	while(*s1){
		*current_char++ = *s1++;
	}
	while(*s2){
		*current_char++ = *s2++;
	}
	*current_char = 0;
	return(res);
}