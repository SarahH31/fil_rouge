#include <stdio.h>
#include <stdlib.h>

#include "affiche.h"
#include "gain_morpion.c"

void actualise_sm(position *sm, const char *filename, char joueur_trait) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier DOT");
        return;
    }

    fprintf(file, "digraph {\n");
    fprintf(file, "a0 [shape=none label=<\n");
    fprintf(file, "<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n");

    generer_sm(file, sm, joueur_trait);

    fprintf(file, "</TABLE>\n");
    fprintf(file, ">];\n");
    fprintf(file, "}\n");

    if (fclose(file) != 0) {
        perror("Erreur lors de la fermeture du fichier DOT");
    }
}

void generer_sm(FILE *file, position *sm, char joueur_trait) {
    fprintf(file, "<TR>\n");  // Start a new row for the 3x3 grid

    for (int num_m = 0; num_m < 9; num_m++) {
        char *bgcolor = (partie_finie(sm->grilles[num_m]) == 'o') ? "black" : (partie_finie(sm->grilles[num_m]) == 'x') ? "white" : "black";
        fprintf(file, "<TD bgcolor=\"%s\">\n", bgcolor);
        fprintf(file, "<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"%s\">\n", bgcolor);

        bgcolor = (partie_finie(sm->grilles[num_m]) == 'o') ? "white" : (partie_finie(sm->grilles[num_m]) == 'x') ? "black" : "white";

        for (int k = 0; k < 3; k++) {
            fprintf(file, "    <TR>\n");

            for (int l = 0; l < 3; l++) {
                if (partie_finie(sm->grilles[num_m]) == 'n') {
                    char joueur = sm->grilles[num_m].cases[k * 3 + l].joueur;
                    fprintf(file, "      <TD bgcolor=\"%s\">%c</TD>\n", bgcolor, joueur);
                } else {
                    fprintf(file, "      <TD bgcolor=\"%s\">&nbsp;</TD>\n", bgcolor);
                }
            }

            fprintf(file, "    </TR>\n");
        }

        fprintf(file, "</TABLE>\n");
        fprintf(file, "</TD>\n");

        // Insert a line break after every 3 boards
        if ((num_m + 1) % 3 == 0 && num_m != 8) {
            fprintf(file, "</TR>\n");  // End the current row
            fprintf(file, "<TR>\n");   // Start a new row for the next set of 3 boards
        }
    }

    fprintf(file, "</TR>\n");  // End the last row
}

