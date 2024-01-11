#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "struct_sarah.h"
#ifndef CHOIXCOUPORDI_H
#define CHOIXCOUPORDI_H

int conversion_numcase(char num_col, int num_ligne);
position saisieCoup(position morpion, int num_grille, int num_case, char coup);
char partie_finie(grille_m grille);
int min_max2(grille_m grille, char joueur_nous, char joueur_auTrait);
grille_m morpion_duSuperM(position sm);
char detection_super_morpion(position sm);
int detection_coup_jouable(int indice, position sm);
int numCaseOrdiJoue(position pos, int numMorpion, char ordi);

#endif
