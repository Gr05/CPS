#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "liste_navires.h"
#include "grille.h"
#include "navires.h"
#include "gestion_fichier.h"


int main (int argc, char * argv[])
{
	int i,j, taille, nb_coup;
	grille g, gc;
	carac_navires tab_def_jeu[4];
	FILE * fichierIn;

	liste_navires * l;
	taille = 10;
	nb_coup = 0;
	g = creer_grille(taille);

	init_grille(g, taille);
	init_carac_navires (tab_def_jeu);


	gc = creer_grille(taille);
	init_grille(gc, taille);

	fichierIn = open_file(argv[1]);
	remplit_grille(g, taille, fichierIn, tab_def_jeu);	

	l = creer_liste_navires(g, taille);

	while(!jeu_fini(l)){
		printf("Quel point ?\n");
		scanf("%d %d", &i, &j);
		joue(g, gc, taille, l, i, j);
		nb_coup++;
		affichage(gc, taille);
	}

	printf("Félicitation le jeu est terminé !!\nIl vous a fallut %d coup pour coulé tout les bateaux\n", nb_coup);

	return 0;
}