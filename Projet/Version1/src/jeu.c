#include <stdlib.h>
#include "jeu.h"

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
			set_coule(m, 1);
			return 1;
		} else {
			m = m->suiv;
		}
	}
	return 0;
}