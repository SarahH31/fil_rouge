#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "gain_morpion.c"

int get_compteur(const grille_m *morpion) {
    int compteur = 0;
    for (int i = 0; i < 9; i++) {
        if (morpion->cases[i].joueur == '.') {
            compteur += 1;
        }
    }
    return compteur;
}

// Initialisation des listes
void initialiser_etats(const grille_m *morpion) {
    for (int i = 0; i < 9; ++i) {
        etats[i].elements = (char *)malloc((2 * fact(get_compteur(morpion) + 1)) * sizeof(char));
    	etats[i].elements[1] = morpion->cases[i].joueur;
        printf("%c", etats[i].elements[1]);
	}
}


void actualise_dot_arbre(const grille_m *morpion, const char *filename, const char joueur_trait) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier DOT");
        return;
    }

    fprintf(file, "digraph MorpionTree {\n");

    // Fonction récursive pour générer les nœuds et les arêtes
    generer_arbre_dot(file, morpion, 0, joueur_trait);

    fprintf(file, "}\n");
    fclose(file);
}

void generer_arbre_dot(FILE *file, const grille_m *morpion, int index, const char joueur_trait) {
    // Noeud actuel
    fprintf(file, "  n%d [label=<<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n", index);

    for (int k = 0; k < 3; k++) {
        fprintf(file, "    <TR>\n");
        for (int l = 0; l < 3; l++) {
            char joueur = morpion->cases[k * 3 + l].joueur;
            const char *bgcolor = (joueur == 'o') ? "green" : (joueur == 'x') ? "red" : "white";
            fprintf(file, "      <TD bgcolor=\"%s\">%c</TD>\n", bgcolor, joueur);
        }
        fprintf(file, "    </TR>\n");
    }

    fprintf(file, "  </TABLE>> shape=plaintext];\n");

    printf("%c\n", partie_finie(*morpion));

	
    if (partie_finie(*morpion) != 'n') {
        for (int i = 0; i < 9; i++) {
            //etats[i].elements[1] = morpion->cases[i].joueur;
            //printf("%c", etats[i].elements[1]);
            if (morpion->cases[i].joueur == '.') {
                grille_m nouvelle_grille = appliquer_coup(morpion, i, joueur_trait);
                fprintf(file, "n%d -> n%d\n", index, index + 1);
                generer_arbre_dot(file, &nouvelle_grille, index + 1, (joueur_trait == 'o') ? 'x' : 'o');
            }
        }
    }
}

grille_m appliquer_coup(const grille_m *morpion, int i, const char joueur_trait) {
    grille_m coup_prochain = *morpion;
    for (int k = 0; k < 9; k++) {
        if (coup_prochain.cases[k].joueur == '.') {
            coup_prochain.cases[k].joueur = joueur_trait;
            break;
        }
    }

    return coup_prochain;
}

void liberer_etats() {
    for (int i = 0; i < 9; ++i) {
        free(etats[i].elements);
    }
}

