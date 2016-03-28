#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"


int main (int argc, char * argv[]){
	int i,j,a;
	grille g;
	int taille = 10;
	FILE * fichier;
	carac_navires tab_def_jeu[4]; //tableau ou sont associé les types au nombre

	if (argc != 2)
	{
		printf("Il n'y a pas le bon nombre d'arguments\n");
		exit(1);
	}
	
	g = creer_grille(taille);
	fichier = open_file(argv[1]);

	init_grille (g, taille);
	init_carac_navires (tab_def_jeu);

	remplit_grille (g, taille, fichier, tab_def_jeu);

	liste_navires * l = creer_liste_navires(g, taille);

	afficher_liste(l);


	//mauvaise conv !!
	g[0][9] = 'T';
	g[1][9] = 'T';
	
	a = un_navire_coule(l, 1, 9, g);
	printf("%d\n", a);

	afficher_liste(l);

	return 0;
}