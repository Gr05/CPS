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

maillon * nouveau (int ideb, int jdeb, int ifin, int jfin);

#endif