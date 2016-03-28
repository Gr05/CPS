/*Gestion_fichier.c*/

#include <stdio.h>
#include "gestion_fichier.h"


//on lit 4 int, qu'on stocke dans coordonnees[]
//retourne -1 si EOF, 0 sinon
int lecture_fichier (FILE * fichier, int coordonnees[])
{
	if(fscanf (fichier, "%d %d %d %d",
		coordonnees,
		coordonnees + 1,
		coordonnees + 2,
		coordonnees + 3) != EOF)
}

//open file 
FILE* open_file (char * chemin)
{
	FILE * fichier = NULL;
	fichier = fopen (../../Ressources/chemin, "r");
	if (fichier == NULL)
	{
		printf("Gestion_fichier.open_file : Le fichier n'est pas ouvert.\n");
		exit (1);
	}
	return fichier;
}

//close file
void close_file (FILE * fichier)
{
	fclose(fichier);
}
