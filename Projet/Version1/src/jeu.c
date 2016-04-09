#include <stdlib.h>
#include <stdio.h>
#include "jeu.h"

//Procedure qui met a 'C' toute les cases d'un navires et a 1 l'attribut coule du maillon m.
void coule_navire(maillon * m, grille gc){
	set_coule(m, 1);
	int i = prem_i(m);
	int j = prem_j(m);
	int ifin = der_i(m);
	int jfin = der_j(m);
	if (i == ifin){
		for (j = prem_j(m); j<=jfin; j++){
			gc[i][j] = 'C';
		}
	} else {
		for (i = prem_i(m); i<=ifin; i++){
			gc[i][j] = 'C';
		}
	}
}

int navire_coule(maillon * m, int ic, int jc, grille gc){
	if (!appartient(m, ic, jc)){
		return 0;
	} else {
		int i = prem_i(m);
		int j = prem_j(m);
		int ifin = der_i(m);
		int jfin = der_j(m);
		if (i == ifin){
			for (j = prem_j(m); j<=jfin; j++){
				if(gc[i][j] != 'T'){
					return 0;
				}
			}
			
			return 1;
		} else {
			for (i = prem_i(m); i<=ifin; i++){
				if(gc[i][j] != 'T'){
					return 0;
				}
			}
			return 1;
		}
	}
}

int un_navire_coule(liste_navires * l, int ic, int jc, grille gc){
	maillon * m = l->tete;
	while (m != NULL){
		if (navire_coule(m, ic, jc, gc)){
			coule_navire(m, gc);
			return 1;
		} else {
			m = m->suiv;
		}
	}
	return 0;
}

void joue(grille g, grille gc, int n, liste_navires * l, int i, int j){
	if (!(i>=0 && i < n && j < n && j>=0)){
		printf("veuillez rentré des coordonées valides\n");
	} else {
		if (gc[i][j] != 'B'){
			printf("Vous avez déja joué cette case, regardez votre grille !\n");
		} else {
			if (g[i][j] == 'B'){
				printf("raté !\n");
				gc[i][j] = 'X';
			} else {
				gc[i][j] = 'T';
				if (un_navire_coule(l, i, j, gc)){
					printf("coulé !!\n");
				} else {
					printf("touché !\n");
				}
			}
		}
	}
}

int jeu_fini(liste_navires * l){
	maillon * navire_courant = l->tete;
	while(navire_courant != NULL){
		if(!est_coule(navire_courant)){
			return 0;
		} else {
			navire_courant = navire_courant ->suiv;
		}
	}
	return 1;
}