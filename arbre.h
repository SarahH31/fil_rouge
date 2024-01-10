#include <stdio.h>
#include <stdlib.h>

#ifndef ARBRE_H
#define ARBRE_H

#include "grille.h"



void generer_arbre_dot(FILE *file, const grille_m *morpion, char joueur_trait);
void link(FILE *file,int nom_parent, int nom_enfant, char *coup);
int get_compteur(const grille_m *morpion);

void actualise_dot_arbre(const grille_m *morpion,const char *filename, char joueur_trait);
char* coup(int i);
grille_m prochain_coup(grille_m morpion, char joueur_trait, int indice);


#endif // ARBRE_H


