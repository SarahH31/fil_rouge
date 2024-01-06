#include <stdio.h>
#include <stdlib.h>

#ifndef ARBRE_H
#define ARBRE_H

#include "grille.h"
#include "fact.h"

struct Liste {
    char *elements;  // Utilisez un pointeur pour représenter un tableau de caractères
};

struct Liste etats[9];

void initialiser_etats(const grille_m *morpion);
int get_compteur(const grille_m *morpion);
void actualise_dot_arbre(const grille_m *morpion, const char *filename, const char joueur_trait);
void generer_arbre_dot(FILE *file, const grille_m *morpion, int index, const char joueur_trait);
grille_m appliquer_coup(const grille_m *morpion, int i, const char joueur_trait);

#endif // ARBRE_H

