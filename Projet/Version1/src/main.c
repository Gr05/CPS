#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]){
	int i;
	char ** grille;
	if (argc < 2){ return 1;}
	int taille = atoi(argv[1]);
	grille = malloc(taille);
	for (i = 0; i < taille; i++){
		grille[i] = malloc(taille);
	}
	return 0;
}