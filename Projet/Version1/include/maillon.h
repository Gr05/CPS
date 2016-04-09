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

// Cette procédure sert surtout pour le debuggage
void afficher_maillon(maillon * m);

//getteurs
int prem_i(maillon * m);

int prem_j(maillon * m);

int der_i(maillon * m);

int der_j(maillon * m);

int est_coule(maillon * m);

//setteur
void set_i_deb(maillon * m, int ideb);

void set_j_deb(maillon * m, int jdeb);

void set_i_fin(maillon * m, int ifin);

void set_j_fin(maillon * m, int jfin);

void set_coule(maillon * m, int etat);

//constructeur de maillon avec allocation de la place mémmoire et initialisation des attributs.
maillon * nouveau (int ideb, int jdeb, int ifin, int jfin);

//fonction qui renvoi 1 si le point (i,j) appartient au navires représenter par m, 0 sinon.
int appartient(maillon * m, int i, int j);

#endif