#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "grille.h"
#include "affichageSuperM.h"
#include "choixCoupOrdi.h"
#include "superfen_to_position.h"

//rajouter horizon de recherche réglable --> modifier en conséquence la fonction d'évaluation

int main(int argc, char *argv[]) {
	// Vérifier s'il y a suffisamment d'arguments en ligne de commande
	if (argc != 3) {
		printf("Usage: %s <FEN> <temps_restant>\n", argv[0]);
		return 1;  // Quitter avec un code d'erreur
	}

	// Récupérer la FEN depuis le premier argument
	char *fen = argv[1];
	
	// Récupérer le temps restant depuis le deuxième argument
	int temps_restant = atoi(argv[2]);
	
	//Initialisation du morpion initial
	position pos_superM;
	pos_superM = fen_to_position(fen);
	
	// Obtenir la longueur de la chaîne
    	size_t longueur = strlen(fen);
    	
	//Récupérer le symbole de notre programme
    	pos_superM.joueurActuel = fen[longueur - 1];
	
	//Récupérer le symbole de notre programme
	char signeProgrammeNous = pos_superM.joueurActuel;
	char adversaire;
	if (pos_superM.joueurActuel == 'x'){
		adversaire = 'o';
	}else{
		adversaire = 'x';
	}
	char c_grille = fen[longueur-4];
	int num_grille = atoi(&c_grille);
	//printf("%d", num_grille);
	//printf("\n");
	int num_case = atoi(&fen[longueur - 3]);
	//printf("%d", num_case);
	//printf("\n");
	int num_case2;
	
	affSuperM_standard(pos_superM);
	
	//on met à jour le superMorpion avec le coup de notre adversaire
	pos_superM.grilles[num_grille].cases[num_case].joueur = adversaire;
	
	// Reste du code
		
	//on propose un morpion à l'ordi (imposé si non vide ou aléatoire)
	//int indice_morpion_pourJouer = detection_coup_jouable(num_case, pos_superM)+1;
	num_case = detection_coup_jouable(num_case, pos_superM);
		
	//l'ordi applique minimax sur le morpion
	//num_case++;
	num_case2 = numCaseOrdiJoue(pos_superM, num_case, signeProgrammeNous);
		
	//on met à jour le supermorpion
	//num_case = num_case-1;
	pos_superM.grilles[num_case].cases[num_case2].joueur = signeProgrammeNous;
		
	//on renvoie le résultat et on affiche le coup joué + supermorpion
	//que affichage pour le moment
	affSuperM_standard(pos_superM);
	
	//printer le résultat
	//int coupNous = num_case*10 + num_case2;
	//printf("%d", coupNous);
	//printf("\n");
	char coup_str[2];
	sprintf(coup_str, "%d%d", num_case, num_case2);
	printf("%s\n", coup_str);
	
    
	return strdup(coup_str);  // Quitter avec succès
}
