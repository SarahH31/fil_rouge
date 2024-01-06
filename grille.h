#include <stdio.h>
#include <stdlib.h>


#ifndef GRILLE_H
#define GRILLE_H


typedef struct {
    char joueur; // 'o', 'x', ou '.' (vide)
} Case;

typedef struct {
    Case cases[9]; 
} grille_m;


typedef struct {
    grille_m grilles[9]; 
    char joueurActuel;
} position;



grille_m new_grille_m();
position new_position();

void actualise_dot(const grille_m *morpion, const char *filename);
int estJouable_sm(const char* fen);

#endif // GRILLE_H
