#include <stdio.h>
#include <stdlib.h>

#include "affiche.h"
#include "grille.h"
#include "superfen_to_position.c"

int main() {
    const char *fen = "6xoxOOOXx1xo1ox1oXo2xo4oox4ox";
    position pos = fen_to_position(fen);
    char joueur_trait = 'x';

    // Afficher la position résultante
 	actualise_sm(&pos, "sm.dot", joueur_trait);
 	system("dot -Tpng sm.dot -o sm.png");

    return 0;
}
