#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "liste_navires.h"


int main (int argc, char * argv[]){
<<<<<<< HEAD
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
=======
	int i,j, taille, nb_coup;
	grille g, gc;
	liste_navires * l;
	taille = 10;
	nb_coup = 0;
	g = malloc(sizeof(char*)*taille);
	for (i = 0; i < taille; i++){
		g[i] = malloc(taille);
	}
	for (i = 0; i < taille; i++){
		for (j = 0; j < taille; j++){
			g[i][j]='B';
		}
	}

	g[0][0] = 'N';
	g[0][1] = 'N';
	g[0][2] = 'N';
	g[0][3] = 'N';



	gc = malloc(sizeof(char*)*taille);
	for (i = 0; i < taille; i++){
		gc[i] = malloc(taille);
	}
	for (i = 0; i < taille; i++){
		for (j = 0; j < taille; j++){
			gc[i][j]='B';
		}
	}

	l = creer_liste_navires(g, taille);

	while(!jeu_fini(l)){
		printf("Quel point ?\n");
		scanf("%d %d", &i, &j);
		joue(g, gc, taille, l, i, j);
		nb_coup++;
		//afficher gc
>>>>>>> e4472b2a1a760f9b826de4eb04b66b1192c5334f

	}
	printf("Félicitation le jeu est terminé !!\nIl vous a fallut %d coup pour coulé tout les bateaux\n", nb_coup);

	return 0;
}