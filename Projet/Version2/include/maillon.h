#ifndef MAILLON_H
#define MAILLON_H
#include <stdint.h>

typedef uint32_t navire;

typedef struct _maillon {
	navire val;
	struct _maillon * suiv;
} maillon;

//Procédure qui insere v du bit petit au bit grand.
void set_field(navire * x, int petit, int grand, int v);

//Fonction qui renvoie la valeur de l'entier codé entre le bit petit et le bit grand.
int get_field(navire * x, int petit, int grand);

int prem_i(maillon * m);

int prem_j(maillon * m);

int der_i(maillon * m);

int der_j(maillon * m);

int est_coule(maillon * m);

void set_i_deb(maillon * m, int ideb);

void set_j_deb(maillon * m, int jdeb);

void set_i_fin(maillon * m, int ifin);

void set_j_fin(maillon * m, int jfin);

void set_coule(maillon * m, int etat);

void afficher_maillon(maillon * m);

maillon * nouveau (int ideb, int jdeb, int ifin, int jfin);

int appartient(maillon * m, int i, int j);

#endif