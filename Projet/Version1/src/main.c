/*main.c*/
/***Simon CHAMBONNET***/
/*****Lucas GUERRY*****/


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

	if (argc != 3)
	{
		printf("main.c : Il n'y a pas le bon nombre d'arguments\n");
		exit(1);
	}
	else
	{
		taille = atoi(argv[1]);
		fichierIn = open_file(argv[2]);
	}

	liste_navires * l;
	nb_coup = 0;

	g = creer_grille(taille);
	init_grille(g, taille);
	init_carac_navires (tab_def_jeu);

	gc = creer_grille(taille);
	init_grille(gc, taille);

	remplit_grille(g, taille, fichierIn, tab_def_jeu);	

	l = creer_liste_navires(g, taille);

	while(!jeu_fini(l)){
		printf("Quel point ?\n");
		if (scanf("%d", &i)!= 1){
			printf("Entrer un couple d'entier svp !\n");
			getchar();
		}
		if (scanf("%d", &j)!= 1){
			printf("Entrer un couple d'entier svp !\n");
			getchar();
		}
		joue(g, gc, taille, l, i, j);
		nb_coup++;
		affichage(gc, taille);
	}

	printf("Félicitation le jeu est terminé !!\nIl vous a fallut %d coup pour coulé tout les bateaux\n", nb_coup);

	return 0;
}