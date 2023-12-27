#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "grille.h"

char* grid_to_fen(grille_m grille) {
    char* fen = (char*)malloc(10); 
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

int main() {

    grille_m grille;
    grille.cases[0].joueur = 'x';
    grille.cases[1].joueur = 'o';
    grille.cases[2].joueur = '.';
    grille.cases[3].joueur = '.';
    grille.cases[4].joueur = 'x';
    grille.cases[5].joueur = 'x';
    grille.cases[6].joueur = 'o';
    grille.cases[7].joueur = 'o';
    grille.cases[8].joueur = '.';


    char* fen_result = grid_to_fen(grille);
    printf("%s\n", fen_result);


    free(fen_result);

    return 0;
}

