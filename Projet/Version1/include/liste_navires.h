/*Liste_navires.h*/
/***Simon CHAMBONNET***/
/*****Lucas GUERRY*****/

#ifndef LISTE_NAVIRES_H
#define LISTE_NAVIRES_H
#include "maillon.h"
#include "grille.h"


typedef struct _liste_navires {
	maillon * tete;
	maillon * queue;
} liste_navires;

//Créer une liste de navire vide.
liste_navires * liste_vide ();

//Procédure qui insert m en fin de l
void insertion (liste_navires * l, maillon * m);

//Fonction qui renvoie la liste de navires compris dans la grille g (Les navires verticaux sont detecté en premier et ensuite les navires horizontaux), n est la taille de la grille g.
liste_navires * creer_liste_navires(grille g, int n);

#endif
