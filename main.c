#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "arbre.h"
#include "dico.h"
#include "grille.h"


#include "arbre.c"
#include "dico.c"
#include "grille.c"



int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Erreur : Nombre incorrect d'arguments.");
        return 1; 
    }


    const char *fen = argv[1];

    int size = strlen(fen);
    int space_position = -1;


    for (int i = 0; i < size; i++) {
        if (fen[i] == ' ') {

            if (space_position != -1) {
                fprintf(stderr, "Erreur : Format incorrect de la FEN. Trop d'espaces.\n");
                return 1;
            }
            space_position = i;
        } else if (!isdigit(fen[i]) && !isalpha(fen[i])) {

            fprintf(stderr, "Erreur : Caractère invalide dans la FEN.\n");
            return 1; 
        }
    }

    if (space_position == -1) {
        fprintf(stderr, "Erreur : Format incorrect de la FEN. Aucun espace trouvé.\n");
        return 1; 
    }

    char etat_grille[space_position + 1];
    strncpy(etat_grille, fen, space_position);
    etat_grille[space_position] = '\0';

    char joueur_trait[2];
    joueur_trait[0] = fen[space_position + 1];
    joueur_trait[1] = '\0';

	char fen_complete[space_position + size - space_position];
    strcpy(fen_complete, etat_grille);
    strcat(fen_complete, joueur_trait);
	

	grille_m morpion = fen_to_grid(fen_complete);
	actualise_dot_arbre(&morpion, "g1.dot", joueur_trait[0]);
	
	system("dot -Tpng g1.dot -o g1.png");

	return 0;
	
}
