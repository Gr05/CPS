#ifndef LISTE_NAVIRES_H
#define LISTE_NAVIRES_H
#include "maillon.h"
//#include "grille.h"


typedef char** grille;

typedef struct _liste_navires {
	maillon * tete;
	maillon * queue;
} liste_navires;

liste_navires * liste_vide ();

//procédure qui insert m en fin de l
void insertion (liste_navires * l, maillon * m);

liste_navires * creer_liste_navires(grille g, int n);

#endif
