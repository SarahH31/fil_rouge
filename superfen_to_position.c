#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grille.h"

// Fonction pour initialiser une grille_m avec un caractère spécifique
grille_m init_grille(char joueur) {
    grille_m grille;
    for (int i = 0; i < 9; i++) {
        grille.cases[i].joueur = joueur;
    }
    return grille;
}

// Fonction pour afficher une position
void afficher_position(position pos) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", pos.grilles[i].cases[j].joueur);
        }
        printf("\n");
    }
}

// Fonction pour transformer une chaîne FEN en position
position fen_to_position(const char *fen) {
    position pos;
    int fen_length = strlen(fen);
    int fen_index = 0;

    for (int i = 0; i < 9; i++) {
        pos.grilles[i] = init_grille('.');

        // Si le morpion est gagné par 'x' ou 'o'
        if (fen_index < fen_length && (fen[fen_index] == 'X')) {
            for (int j = 0; j < 9; j++) {
                pos.grilles[i].cases[j].joueur = 'x';
            }
            fen_index++;
        } else if (fen_index < fen_length && (fen[fen_index] == 'O')) {
            for (int j = 0; j < 9; j++) {
                pos.grilles[i].cases[j].joueur = 'o';
            }
            fen_index++;
        } else {
            int m = 0;
            while (fen_index < fen_length && m < 9) {
                if (fen[fen_index] >= '0' && fen[fen_index] <= '9') {
                    for (int k = 0; k < fen[fen_index] - '0'; k++) {
                        pos.grilles[i].cases[m].joueur = '.';
                        m++;
                    }
                    fen_index++;
                } else {
                    pos.grilles[i].cases[m].joueur = fen[fen_index];
                    fen_index++;
                    m++;
                }
            }
        }
    }

    return pos;
}


