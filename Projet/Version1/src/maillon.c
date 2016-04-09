/*Maillon.c*/
/***Simon CHAMBONNET***/
/*****Lucas GUERRY*****/


#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>

void afficher_maillon(maillon * m){
	if( m == NULL){
		printf("Le maillon n'existe pas\n");
	} else {
		printf("|%d|%d|%d|%d|c=%d|\n",prem_i(m), prem_j(m), der_i(m), der_j(m), est_coule(m));
	}
}

int prem_i(maillon * m){
	return m->i_deb;
}

int prem_j(maillon * m){
	return m->j_deb;
}

int der_i(maillon * m){
	return m->i_fin;
}

int der_j(maillon * m){
	return m->j_fin;
}

int est_coule(maillon * m){
	return m->coule;
}

void set_i_deb(maillon * m, int ideb){
	m->i_deb = ideb;
}

void set_j_deb(maillon * m, int jdeb){
	m->j_deb = jdeb;
}

void set_i_fin(maillon * m, int ifin){
	m->i_fin = ifin;
}

void set_j_fin(maillon * m, int jfin){
	m->j_fin = jfin;
}

void set_coule(maillon * m, int etat){
	m->coule = etat;
}

maillon * nouveau (int ideb, int jdeb, int ifin, int jfin){
	maillon * m = malloc(sizeof(maillon));
	set_coule(m, 0);
	set_i_deb(m, ideb);
	set_i_fin(m, ifin);
	set_j_deb(m, jdeb);
	set_j_fin(m, jfin);
	return m;
}

int appartient(maillon * m, int i, int j){
	return((i >= prem_i(m)) && (i <= der_i(m)) && (j >= prem_j(m)) && (j <= der_j(m)));
}