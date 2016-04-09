/*Jeu.h*/
/***Simon CHAMBONNET***/
/*****Lucas GUERRY*****/

#ifndef JEU_H
#define JEU_H
#include "liste_navires.h"
#include "maillon.h"
#include "grille.h"

// Fonction qui renvoi 1 si le bateau représenté par le maillon m est coulé par une attaque en (ic, jc), 0 sinon.
int navire_coule(maillon * m, int ic, int jc, grille gc);

//Fonction qui renvoi 1 et s'occupe de mettre à jour l et gc si un navire est coulé par une attaque en (ic, jc)(Ce traitement est fais ici pour ne pas avoir à rechercher quel navire c'est fais toucher dans la fonction joue), renvoi 0 sinon.
int un_navire_coule(liste_navires * l, int ic, int jc, grille gc);

//Fonction principale du jeu qui permet d'afficher le résultat d'une attaque en (i,j) et de mettre a jour l et gc.
void joue(grille g, grille gc, int n, liste_navires * l, int i, int j);

//Fonction qui renvoi 1 si tout les navires de l sont coulé, 0 sinon.
int jeu_fini(liste_navires * l);


#endif