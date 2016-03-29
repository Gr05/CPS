/*Grille.h*/
#ifndef GRILLE_H
#define GRILLE_H

#include "navires.h"
#include "gestion_fichier.h"
/*Fonctions implémantées par Grille*/

//Alloue la dynamiquement la grille
char** creer_grille (int taille);

//initialise la grille en placant des 'B' dans toutess les cases
void init_grille (char ** grille, int taille);

//regarde si la place sur la grille est prise
int emplacement_libre (char ** grille, int coordonnees[], int taille, int type);

//verifie si si les coordonnées passé appartinnent à la grille
int dans_grille (char ** grille, int coordonnees[], int taille);

//vérifie que les coordonnées suivent un axe orthonormé
int travers (int coordonnees[], int type);

//rassemble l'ensemble des vérifications
int controle (char ** grille, int coordonnees[], int taille, carac_navires tab[]);

//place un 'N' à l'emplacement d'un navire
void insere_navire (char ** grille, int coordonnees[], int taille);

//affiche dans le terminal les carectères sous forme de grille de la grille
void affichage (char ** grille, int taille);

//fonction qui remplit la grille
void remplit_grille (char ** grille, int taille, FILE * fichier, carac_navires tab[]);

char get_case (char ** grille, int x, int y);

void set_case (char ** grille, int x, int y, char c);
