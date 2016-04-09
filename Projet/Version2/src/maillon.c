/*Maillon.c*/
/***Simon CHAMBONNET***/
/*****Lucas GUERRY*****/


#include "maillon.h"
#include <stdlib.h>
#include <stdio.h>

void set_field(navire * x, int petit, int grand, int v){
	navire masque = ~0<<(grand - petit + 1);
	masque = ~masque; // 000000001111
	masque <<= petit; // 000011110000
	masque = ~masque; // 111100001111
	(*x) &= masque;   // *x = xxxx0000xxxx
	(*x) |= v<<petit; 
}

int get_field(navire * x, int petit, int grand){
	navire masque = ~0<<(grand - petit + 1);
	masque = ~masque;
	masque <<= petit;
	masque &= (*x);
	masque >>=petit;
	return masque;
}

int prem_i(maillon * m){
	return get_field(&(m->val), 0, 3);
}

int prem_j(maillon * m){
	return get_field(&(m->val), 7, 10);
}

int der_i(maillon * m){
	return get_field(&(m->val), 14, 17);
}

int der_j(maillon * m){
	return get_field(&(m->val), 21, 24);
}

int est_coule(maillon * m){
	return get_field(&(m->val), 31, 31);;
}

void set_i_deb(maillon * m, int ideb){
	set_field(&(m->val), 0, 3, ideb);
}

void set_j_deb(maillon * m, int jdeb){
	set_field(&(m->val), 7, 10, jdeb);
}

void set_i_fin(maillon * m, int ifin){
	set_field(&(m->val), 14, 17, ifin);
}

void set_j_fin(maillon * m, int jfin){
	set_field(&(m->val), 21, 24, jfin);
}

void set_coule(maillon * m, int etat){
	set_field(&(m->val), 31, 31, etat);
}

void afficher_maillon(maillon * m){
	if( m == NULL){
		printf("Le maillon n'existe pas\n");
	} else {
		printf("|%d|%d|%d|%d|c=%d|\n",prem_i(m), prem_j(m), der_i(m), der_j(m), est_coule(m));
	}
}

maillon * nouveau (int ideb, int jdeb, int ifin, int jfin){
	maillon * m = malloc(sizeof(maillon));
	m->suiv = NULL;
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