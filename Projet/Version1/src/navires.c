/*Navires.c*/
/***Simon CHAMBONNET***/
/*****Lucas GUERRY*****/


#include <stdio.h>
#include <stdlib.h>
#include "navires.h"
/*Fonctions relatives à la gestion du type et du nombre de navires*/


//remplit le tableau avec les constantes définit
void init_carac_navires (carac_navires tab[])
{
	//TORPILLEUR
	tab[0].type_navire = NB_CASES_TORPILLEURS;
	tab[0].nb_navires = NB_TORPILLEURS;

	//CONTRE TORPILLEUR
	tab[1].type_navire = NB_CASES_CONTRE_TORPILLEURS;
	tab[1].nb_navires = NB_CONTRE_TORPILLEURS;

	//CROISEUR
	tab[2].type_navire = NB_CASES_CROISEURS;
	tab[2].nb_navires = NB_CROISEURS;

	//PORTE AVION
	tab[3].type_navire = NB_CASES_PORTE_AVION;
	tab[3].nb_navires = NB_PORTE_AVION;
}

//compare le type du navire passé an param avec ceux stocké et le nombre restant
//retourne 1 si ok, 0 sinon
int navire_appartient (int type, carac_navires tab[])
{
	int i = 0;

		while (i<4)
		{
			if(tab[i].type_navire == type) //le type correspond ?
			{
				if (tab[i].nb_navires == 0) //il y en a pas trop ?
				{
					printf("Navires.navire_pioche : Il y a trop de navire à %d cases. \n", tab[i].type_navire);
					return 0;
					
				}
				else
				{
					tab[i].nb_navires = tab[i].nb_navires - 1;
					return 1;					
				}
			}
			i++;
		}

		if (i == 4) //le type ne correspond pas
		{
			printf("Navires.navire_pioche : Le navire à %d cases n'existe pas.\n", type);
			return 1;
		}
		return 0;
}

//compare le nombre de navire à 0, si différent retourne 1, sinon 0
int navire_pioche (carac_navires tab[])
{
	int i = 0;
	int retour = 0;
	while (i<4)
	{
		if (tab[i].nb_navires != 0)
		{
			retour = 1;
			printf("Navires.navire_pioche : Tous les navires ne sont pas placé.\n");
			printf("Il reste %d navire(s) à %d cases.\n", tab[i].nb_navires, tab[i].type_navire);
		}
		i++;
	}
	return retour;
}