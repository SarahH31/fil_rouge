#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dico.h"
#include "grille.h"

char* grid_to_fen(grille_m grille) {
    char* fen = (char*)malloc(12); 
    int curseur = 0;
    int compteur = 0;

    for (int i = 0; i < 9; i++) {
        if (isalpha(grille.cases[i].joueur)) {
            if (compteur != 0) {
                fen[curseur++] = '0' + compteur;
                compteur = 0;
            }
            fen[curseur++] = grille.cases[i].joueur;
        } else if (grille.cases[i].joueur == '.') {
            compteur++;
        }
    }

    if (compteur != 0) {
        fen[curseur++] = '0' + compteur;
    }

    fen[curseur] = '\0';
    return fen;
}


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
