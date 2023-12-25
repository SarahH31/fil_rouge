#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grille.h"


void new_grille_m(grille_m *grille) {

    for (int i = 0; i < 9; i++) {
        grille->cases[i].joueur = '.';
    }
}


void new_position(position *pos) {
    for (int j = 0; j < 9; j++) {
    	new_grille_m(&(pos->grilles[j]));
    }

    pos->joueurActuel = 'o';
}


int estJouable(const char* fen){
	int size = strlen(fen);
	for (int i = 0; i < size; i++) {
		// TODO: vérifier le format de la fen avec laquelle on travaille
        if (fen[i] == ' '){
        
        	int numGrille = atoi(&fen[i+1]);
        	int numCase = atoi(&fen[i+2]);
       
        	if (numGrille >= 0 && numGrille <= 9 && numCase >= 0 && numCase <= 9) {
    			grille_m grilleVerif = fen_to_grille(fen);
    			
    				if (grilleVerif.cases[numCase].joueur == '.'){
    					printf("Le coup est jouable");
    					return 0;
    				}
    				printf("Le coup n'est pas jouable");
    				return 1;
    				// TODO: dans la fonction, permettre au joueur de rentrer un autre coup
    		}
   			fprintf(stderr, "Message d'erreur : le coup demandé n'est pas au bon format\n");
   			// TODO: dans la fonction, permettre au joueur de rentrer un autre coup
     
       }
        
    fprintf(stderr, "Message d'erreur :format incorrect\n");
    } 
}



void actualise_dot(const grille_m *morpion, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier DOT");
        return;
    }

    fprintf(file, "digraph SuperMorpion {\n");

    // Insérer les informations pour m1
    fprintf(file, "  m1 [shape=none label=<<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n");
    for (int k = 0; k < 3; k++) {
        fprintf(file, "    <TR>\n");
        for (int l = 0; l < 3; l++) {
            char joueur = morpion->cases[k * 3 + l].joueur;
            const char *bgcolor = (joueur == 'o') ? "green" : (joueur == 'x') ? "red" : "white";
            fprintf(file, "      <TD bgcolor=\"%s\">%c</TD>\n", bgcolor, joueur);
        }
        fprintf(file, "    </TR>\n");
    }
    fprintf(file, "    <TR><TD bgcolor=\"white\" colspan=\"3\">m1</TD></TR>\n");
    fprintf(file, "  </TABLE>>];\n");

    fprintf(file, "}\n");

    fclose(file);
}
