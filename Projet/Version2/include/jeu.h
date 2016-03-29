#ifndef JEU_H
#define JEU_H
#include "liste_navires.h"
#include "maillon.h"
//#include "grille.h"

int navire_coule(maillon * m, int ic, int jc, grille gc);

int un_navire_coule(liste_navires * l, int ic, int jc, grille gc);


#endif