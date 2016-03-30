/*Gestion_fichier.h*/
#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H


//open file le chemin est spécifique à la hiérarchie des dossiers
FILE* open_file (char * chemin);

//lit 4 int dans un fichier
int lecture_fichier (FILE * fichier, int coordonnees[]);

//close file
void close_fichier (FILE * fichier);
