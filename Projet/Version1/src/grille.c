/*Grille.c*/

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

//retourne un pointeur sur grille allouer avec n carré cases
grille creer_grille (int taille)
{
	int i;
	grille g = malloc(sizeof(char*)*taille);
	for (i = 0; i < taille; i++){
		g[i] = malloc(taille);
	}
	return g;
}

//initialise la grille avec des B
void init_grille (grille g, int taille)
{
	//on remplit la grille de 'B'
	int i, j;
	for (i = 0; i < taille; i++)
	{
		for (j = 0; j < taille; j++)
		{
			g[i][j] = 'B';
		}
	}
}

//retourne 0 si navire autour ou dessus, 1 sinon
int emplacement_libre (grille g, int coordonnees[], int taille, int type)
{
	int x_deb = coordonnees[0]; // ! dans le fichier dentrée (x,y) début est celui le plus
	int y_deb = coordonnees[1]; //proche de l'origine !
	int x_fin = coordonnees[2];
	int y_fin = coordonnees[3];	
	int i;
	int bord_haut, bord_bas, bord_gauche, bord_droite;
	
	if (x_deb == x_fin)
	{
		if (x_deb == 0)
		{
			bord_gauche = 0;
			bord_droite = 1;
		}
		else if (x_deb == taille-1)
		{
			bord_gauche = -1;
			bord_droite = 0;
		}
		else
		{
			bord_gauche = -1;
			bord_droite = 1;
		}

		i = 0;
		while(i<type)
		{
			if (g[x_deb][y_deb + i] == 'N'               || 
				g[x_deb + bord_gauche][y_deb + i] == 'N' ||
				g[x_deb + bord_droite][y_deb + i] == 'N')
			{
				printf("Grille.controle : Il n'y a pas la place.\n");
				return 0;
			}
			i++;
		}
		if (y_deb != 0)
		{
			if (g[x_deb][y_deb - 1] == 'N')
			{
				printf("Grille.controle : Il n'y a pas la place.\n");
				return 0;
			}
		}
		if (y_fin != taille -1)
		{
			if (g[x_deb][y_fin + 1] == 'N')
			{
				printf("Grille.controle : Il n'y a pas la place.\n");
				return 0;
			}
		}
	}
	else if (y_deb == y_fin)
	{
		if (y_deb == 0)
		{
			bord_haut = 0;
			bord_bas = 1;
		}
		else if (y_deb == taille-1)
		{
			bord_haut = -1;
			bord_bas = 0;
		}
		else
		{
			bord_haut = -1;
			bord_bas = 1;
		}

		i = 0;
		while(i<type)
		{
			if (g[x_deb + i][y_deb] == 'N'             || 
				g[x_deb + i][y_deb + bord_haut] == 'N' ||
				g[x_deb + i][y_deb + bord_bas] == 'N')
			{
				printf("Grille.controle : Il n'y a pas la place.\n");
				return 0;
			}
			i++;
		}
		if (x_deb != 0)
		{
			if (g[x_deb - 1][y_deb] == 'N')
			{
				printf("Grille.controle : Il n'y a pas la place.\n");
				return 0;
			}
		}
		if (x_fin != taille -1)
		{
			if (g[x_deb + 1][y_fin] == 'N')
			{
				printf("Grille.controle : Il n'y a pas la place.\n");
				return 0;
			}
		}
	}
	return 1; //Le navire n'a aucun contact
}

//retourne 0 si pas sur grille 1 sinon
int dans_grille (int coordonnees[], int taille)
{
	int x_deb = coordonnees[0]; // ! dans le fichier dentrée (x,y) début est celui le plus
	int y_deb = coordonnees[1]; //proche de l'origine !
	int x_fin = coordonnees[2];
	int y_fin = coordonnees[3];
	if (x_deb < 0          ||
		y_deb < 0          ||
		x_fin > taille - 1 ||
		y_fin > taille - 1)
	{
		printf("Grille.controle : Le navire n'est pas sur la grille.\n");
		return 0;
	}
	return 1;
}

//retourne 0 si de travers, 1 sinon
int travers (int coordonnees[], int type)
{
	int x_deb = coordonnees[0]; // ! dans le fichier dentrée (x,y) début est celui le plus
	int y_deb = coordonnees[1]; //proche de l'origine !
	int x_fin = coordonnees[2];
	int y_fin = coordonnees[3];

	if (x_deb != x_fin && y_deb != y_fin)
	{
		printf("Grille.controle : Le navire à %d cases est en travers\n", type);
		return 0;
	}
	return 1;
}


//retourne 1 si pb, 0 sinon
int controle (grille g, int coordonnees[], int taille, carac_navires tab[])
{
	int x_deb = coordonnees[0]; // ! dans le fichier dentrée (x,y) début est celui le plus
	int y_deb = coordonnees[1]; //proche de l'origine !
	int x_fin = coordonnees[2];
	int y_fin = coordonnees[3];
	int type_navire;


	if (!(dans_grille(coordonnees, taille)))
	{
		return 1;
	}

	if (x_deb == x_fin)
	{
		type_navire = (y_fin - y_deb) + 1;
	}
	else
	{
		type_navire = (x_fin - x_deb) + 1;
	}

	//on regarde si c'est un navire du jeu (nb cases) et si le nombre est bon
	if (!(navire_appartient(type_navire, tab)))
		{
			//on sort
			return 1;
		}
	
	if (!(emplacement_libre(g, coordonnees, taille, type_navire)));
	{
		return 1;
	}

	if (!(travers(coordonnees, type_navire)))
	{
		return 1;
	}
	return 0;
}

/*insere_navire : 
  @param : un tableau de 2 coordonnées début et fin
  @param : la grille de jeu
  @param : taille de la grille
  @return : int qui vaut le type du navire*/
void insere_navire (grille g, int coordonnees[], int taille)
{
	int x_deb = coordonnees[0]; // ! dans le fichier dentrée (x,y) début est celui le plus
	int y_deb = coordonnees[1]; //proche de l'origine !
	int x_fin = coordonnees[2];
	int y_fin = coordonnees[3];
	int type_navire;
	int i;

	if (x_deb == x_fin)
	{
		type_navire = (y_fin - y_deb) + 1;
		i = 0;
		while (i < type_navire)
		{
			g[x_deb][y_deb + i] = 'N';
			i++;
		}
	}
	else
	{
		type_navire = (x_fin - x_deb) + 1;
		i = 0;
		while (i < type_navire)
		{
			g[x_deb + i][y_deb] = 'N';
			i++;
		}
	}
}

void affichage (grille g, int taille)
{
	int i,j;

	printf("\n   ");
	for (i = 0; i < taille; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 0; i < taille; i++)
	{
		printf(" %d ", i);
		for (j= 0; j < taille; j++)
		{
			if (g[j][i] == 'B')
			{
				printf("   ");
			}
			else
			{
				printf(" %c ", g[j][i]);
			}
		}
		printf("\n");
	}
}

//retourne 1 si pb, 0 sinon
void remplit_grille (grille g, int taille, FILE * fichier, carac_navires tab[])
{
	int coordonnees [4];
	int numero_navire;

	numero_navire = 0;
	while(lecture_fichier(fichier, coordonnees) != 1)
	{
		if (controle(g, coordonnees, taille, tab))
		{
			printf("Grille.remplit_grille : Défaut sur le navire %d du fichier.\nexit\n", numero_navire);
			exit(1);
		}
		insere_navire (g, coordonnees, taille);
		numero_navire++;
	}

	close_file (fichier);

	if(navire_pioche (tab))
	{
		printf("Grille.remplit : exit\n");
		exit(1);
	}
	printf("Grille.remplit_grille : Affichage grille =>\n");
	affichage (g, taille);
}


//retourne le caractère des coordonnées passées en param
char get_case (grille g, int x, int y)
{
	return g[x][y];
}

//change la valeur de la cases des coordonnées avec le char en param
void set_case (grille g, int x, int y, char c)
{
	g[x][y] = c;
}