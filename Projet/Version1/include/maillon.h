#ifndef MAILLON_H
#define MAILLON_H

typedef struct _maillon {
	int i_deb;
	int j_deb;
	int i_fin;
	int j_fin;
	int coule;
	struct _maillon * suiv;
} maillon;

void afficher_maillon(maillon * m);

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

maillon * nouveau (int ideb, int jdeb, int ifin, int jfin);

int appartient(maillon * m, int i, int j);

#endif