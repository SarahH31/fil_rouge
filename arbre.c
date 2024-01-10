#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre.h"
#include "gain_morpion.c"

char joueur_nous = 'o'; 


// numérotation des morpions
int n= 0;
 
// Nombre de cases vides au départ
static int compteur_init = 0;

int position_jouee = -1;

// traduit un entre en 1 et 9 et renvoie les coordonnées du coup sur le png
char* coup(int i){
    char coup_str[5];  //la taille est suffisante
    int colonne = -1;
    int ligne =-1;
    
    if ((i == 1) || (i == 4) || (i == 7)){
    	colonne = 1;
    	if (i == 1){ligne = 1;}
    	if (i == 4){ligne = 2;}
    	else{ligne = 3;}
    }
    
    if ((i == 2) || (i == 5) || (i == 8)){
    	colonne = 2;
    	if (i == 2){ligne = 1;}
    	if (i == 5){ligne = 2;}
    	else{ligne = 3;}
    }
    
    if ((i == 3) || (i == 6) || (i == 9)){
    	colonne=3;
    	if (i == 3){ligne = 1;}
    	if (i == 6){ligne = 2;}
    	else{ligne = 3;}
    }
    
    sprintf(coup_str, "%d, %d", colonne, ligne);
    return strdup(coup_str);  
}


int get_compteur(const grille_m *morpion){
	int compteur = 0;
	for (int i = 0; i < 9; ++i) {
		if (morpion->cases[i].joueur == '.') {
            compteur+= 1;
        }
	}
	return compteur;
}

//indice entre 1 et nb_enfants

grille_m prochain_coup(grille_m morpion, char joueur_trait, int indice){
	int pointeur = 0;
	grille_m temp_m = morpion;
	for (int i = 0; i < 9; ++i) {
		if (morpion.cases[i].joueur == '.') {
            pointeur+= 1;
            
        	// on joue la ième case vide - ie à chaque enfant, on joue un coup différent.
        	if (pointeur == indice){
        		temp_m.cases[i].joueur = joueur_trait;
        		// on garde la case jouée en mémoire pour afficher le coup
        		position_jouee = i+1;

        	}
        	
        }
        
	}
	//for (int i = 0; i < 9; ++i) {
	//printf("%c", temp_m.cases[i].joueur);}
	//printf("\n");
	return temp_m;
	
}

void link(FILE *file, int nom_parent, int nom_enfant, char *coup_a_jouer) {
    fprintf(file, "m%d-> m%d [label=\"%s\"];\n", nom_parent, nom_enfant, coup_a_jouer);
}



void actualise_dot_arbre(const grille_m *morpion, const char *filename, char joueur_trait) {
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier DOT");
        return;
    }

    fprintf(file, "digraph MorpionTree {\n");

    // Fonction récursive pour générer les nœuds et les arêtes
    generer_arbre_dot(file, morpion, joueur_trait);
    fprintf(file, "}\n");
    fclose(file);
}


void generer_arbre_dot(FILE *file, const grille_m *morpion, char joueur_trait) {
    
        
    int nom_parent = n;
    
    fprintf(file, "m%d [shape=none label=<\n", n);
    fprintf(file, "<TABLE border=\"0\" cellspacing=\"10\" cellpadding=\"10\" style=\"rounded\" bgcolor=\"black\">\n");


    for (int k = 0; k < 3; k++) {
        fprintf(file, "    <TR>\n");
        for (int l = 0; l < 3; l++) {
            char joueur = morpion->cases[k * 3 + l].joueur;
            
            fprintf(file, "<TD bgcolor=\"white\">%c</TD>\n", joueur);
            
        }
        fprintf(file, "    </TR>\n");
    }
    const char *bgcolor = (joueur_trait == 'o') ? "red" : (joueur_trait == 'x') ? "green" : "white";
    fprintf(file, "<TR><TD bgcolor=\"%s\" colspan=\"3\">m%d</TD></TR>\n", bgcolor, n);
    fprintf(file, "<TR><TD bgcolor=\"white\" colspan=\"3\">%d</TD></TR>\n", min_max2(*morpion, joueur_nous, joueur_trait));
    fprintf(file, "  </TABLE>> shape=plaintext];\n");

	

	n++;
	int nb_enfants = get_compteur(morpion);
	char joueur_parent = joueur_trait;
	
	// cas des noeuds extrémaux 
	if (partie_finie(*morpion) == 'n'){
		
	for (int i = 0; i < nb_enfants; i++){
		
		// i+1 pour correspondre au compteur qui prendre la valeur 1 lors de la première case vide
		grille_m grille_prochaine = prochain_coup(*morpion, joueur_trait, i+1);
		joueur_trait = (joueur_parent == 'o') ? 'x' : 'o';
		char* coup_a_jouer = coup(position_jouee);
		link(file, nom_parent, n, coup_a_jouer);
		
		generer_arbre_dot(file, &grille_prochaine, joueur_trait);
	}
	}
	
}
