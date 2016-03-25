#include <stdio.h>
#include <stdlib.h>
#include "liste_navires.h"
#include "maillon.h"


void afficher_maillon(maillon * m){
	if( m == NULL){
		printf("ta mere la pute pour le maillon");
	} else {
		printf("|%d|%d|%d|%d|c=%d|\n",m->i_deb, m->j_deb, m->i_fin, m->j_fin, m->coule);
	}
}

void afficher_liste(liste_navires * l){
	if(l == NULL){
		printf("ta mere la pute pour la liste\n");
	} else {
		maillon * maillon_courant = l->tete;
		while(maillon_courant != NULL){
			afficher_maillon(maillon_courant);
			maillon_courant = maillon_courant->suiv;
		}
	}
		
}

int main (int argc, char * argv[]){
	int i,j;
	grille g;
	g = malloc(sizeof(char*)*10);
	for (i = 0; i < 10; i++){
		g[i] = malloc(10);
	}
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			g[i][j]='B';
		}
	}

	g[0][0] = 'N';
	g[0][1] = 'N';
	g[0][2] = 'N';

	g[0][9] = 'N';
	g[1][9] = 'N';

	g[9][7] = 'N';
	g[9][8] = 'N';
	g[9][9] = 'N';


	liste_navires * l = creer_liste_navires(g, 10);

	afficher_liste(l);

	return 0;
}