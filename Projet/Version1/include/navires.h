/*Navires.h*/
#ifndef NAVIRES_H
#define NAVIRES_H


#define NB_PORTE_AVION 1
#define NB_CROISEURS 2
#define NB_CONTRE_TORPILLEURS 3
#define NB_TORPILLEURS 4

#define NB_CASES_PORTE_AVION 6
#define NB_CASES_CROISEURS 4
#define NB_CASES_CONTRE_TORPILLEURS 3
#define NB_CASES_TORPILLEURS 2

typedef struct _carac_navires
{
	int type_navire;
	int nb_navires;
} carac_navires;

//initialise le tableau associant le type du navire au nombre
void init_carac_navires (carac_navires tab[]);

//vérifie si un navire existe et si il y en a encore de disponible
int navire_appartient (int type, carac_navires tab[]);

//vérifie que tous les navires ont été utilisé
int navire_pioche (carac_navires tab[]);
#endif
