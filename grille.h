#include <stdio.h>
#include <stdlib.h>

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


grille_m fen_to_grid(const char* fen);
char* grid_to_fen(struct grille_m);

grille_m new_grille_m();
position new_position();

void actualise_dot(const grille_m *morpion, const char *filename);
int estJouable(const char* fen);
