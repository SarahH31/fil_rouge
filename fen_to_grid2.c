#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "grille.h"

grille_m fen_to_grid(const char* fen) {
    int curseur = 0;
    grille_m grille = new_grille_m(); 
    
    int size = strlen(fen);
    int size_relle = size; 

    for (int k = 0; k < size; k++) {
        if (fen[k] == ' ') {
            size_relle = k; 
            break; // Sort de la boucle
        }
    }

    for (int i = 0; i < size_relle; i++) {
        if (isdigit(fen[i])) {
            int longueur = atoi(&fen[i]);
            for (int j = 0; j < longueur; j++) {
                grille.cases[curseur].joueur = '.'; 
                curseur += 1;
            }
        }

        if (isalpha(fen[i])) {
            grille.cases[curseur].joueur = fen[i]; 
            curseur += 1;
        }
    }

    return grille;
}

