#include "liste_navires.h"
#include <stdlib.h>
#include <stdio.h>

//(A surtout servi pour degbugger) Affiche la liste de navire l.
void afficher_liste(liste_navires * l){
	if(l == NULL){
		printf("La liste n'existe pas\n");
	} else {
		maillon * maillon_courant = l->tete;
		while(maillon_courant != NULL){
			afficher_maillon(maillon_courant);
			maillon_courant = maillon_courant->suiv;
		}
	}
		
}

liste_navires * liste_vide (){
	liste_navires * l = malloc(sizeof(liste_navires));
	l->tete = NULL;
	l->queue = NULL;
	return l;
}

//Fonction qui retourne 1 si la liste est vide, 0 sinon.
int est_vide(liste_navires * l){
	return (l->tete == NULL);
}

void insertion (liste_navires * l, maillon * m){
	if(est_vide(l)){
		l->tete = m;
	} else {
		l->queue->suiv = m;
	}
	l->queue = m;
}

liste_navires * creer_liste_navires(grille g, int n){
	liste_navires * l = liste_vide();
	int i, j, ideb, jdeb;

	// parcours dans un premier sens pour detecter les bateaux verticaux
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if(g[i][j] == 'N'){
				ideb = i;
				jdeb = j;
				if((j+1 < n) && (g[i][j+1] == 'N')){
					j++;
					while((j+1 < n) && (g[i][j+1] == 'N')){
						j++;
					}
					maillon * m = nouveau(ideb, jdeb, ideb, j);
					insertion(l, m);
				} 
			}
		}
	}

	// parcour de la grille dans l'autre sens pour detecter les bateau hotizontaux
	for (j = 0; j < n; j++){
		for (i = 0; i < n; i++){
			if(g[i][j] == 'N'){
				ideb = i;
				jdeb = j;
				if((i+1 < n) && (g[i+1][j] == 'N')){
					i++;
					while((i+1 < n) && (g[i+1][j] == 'N')){
						i++;
					}
					maillon * m = nouveau(ideb, jdeb, i, jdeb);
					insertion(l, m);
				} 
			}
		}
	}
	return l;	
}