#include <stdio.h>
#include <stdlib.h>


#ifndef DICO_H
#define DICO_H
#include "grille.h"

grille_m fen_to_grid(const char* fen);
char* grid_to_fen(grille_m grille);

#endif // DICO_H
