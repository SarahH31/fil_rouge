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


struct grille_m fen_to_grille(const char* fen);
char* grille_to_fen(struct grille_m);
void new_grille_m(grille_m *grille);
void new_position(position *pos);
void actualise_dot(const grille_m *morpion, const char *filename);
int estJouable(const char* fen);
