#include "maillon.h"
#include <stdlib.h>

maillon * nouveau (int ideb, int jdeb, int ifin, int jfin){
	maillon * m = malloc(sizeof(maillon));
	m->i_deb=ideb;
	m->j_deb=jdeb;
	m->i_fin=ifin;
	m->j_fin=jfin;
	m->coule = 0;
	return m;
}