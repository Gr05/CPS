#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"


int main (int argc, char * argv[]){
	int i,j,a;
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

	g[0][9] = 'T';
	g[1][9] = 'T';
	
	a = un_navire_coule(l, 1, 9, g);
	printf("%d\n", a);

	afficher_liste(l);

	return 0;
}