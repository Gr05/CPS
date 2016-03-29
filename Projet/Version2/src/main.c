#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "liste_navires.h"
#include "maillon.h"


int main (int argc, char * argv[]){
	int i,j, taille, nb_coup;
	int a = 31;
	int b = 31;
	int c = 1;
	grille g, gc;
	liste_navires * l;
	taille = 10;
	nb_coup = 0;
	navire test = 0;
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

	afficher_liste(l);

	/*printf("%x\n", test);
	set_field(&test, a, b, c);
	printf("%x\n", test);
	c = get_field(&test, a, b);
	printf("%x\n", c);*/

	while(!jeu_fini(l)){
		printf("Quel point ?\n");
		scanf("%d %d", &i, &j);
		joue(g, gc, taille, l, i, j);
		nb_coup++;
		//afficher gc

	}
	printf("Félicitation le jeu est terminé !!\nIl vous a fallut %d coup pour coulé tout les bateaux\n", nb_coup);

	return 0;
}