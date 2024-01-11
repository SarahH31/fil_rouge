#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct_sarah.h"
#include "affichageSuperM.h"
#include "choixCoupOrdi.h"

//rajouter horizon de recherche réglable --> modifier en conséquence la fonction d'évaluation


int main(int argc, char *argv[]) {

	// Vérifier s'il y a suffisamment d'arguments en ligne de commande
	if (argc != 2) {
        	printf("Usage: %s <horizon>\n", argv[0]);
		return 1;  // Quitter avec un code d'erreur
	}

	// Récupérer l'horizon à partir du premier argument
	int horizon = atoi(argv[1]);

	printf("L'horizon de recherche est fixé à : %d\n", horizon);
	
	
	//Initialisation du morpion initial
	position pos_superM;
	int l;
	int m;
	for (l=0; l<9; l++){
		for (m=0; m<9; m++){
			pos_superM.grilles[l].cases[m].joueur = '.';
		}
	}
	pos_superM.joueurActuel = 'o';
	affSuperM_standard(pos_superM);
	
	//Définir le symbole de chaque joueur
	char signeOrdi = 'x';
	char signeJoueur = 'o';
	
	// Reste du code
	while(detection_super_morpion(pos_superM)=='n'){//grand morpion non fini{}
	
		//on demande un coup à l'utilisateur
		// Récupérer les numéros de grille, de colonne et de ligne
		int num_grille, num_ligne;
		char coup, num_col;
		char input[100];
		printf("Entrez votre coup sous la forme \"<#grille>(1..9) espace <#colonne>(a..c) <#ligne>(1..3) <#coup>(x,o)\" : ");
		fgets(input, sizeof(input), stdin);
		sscanf(input, "%d %c%d %c", &num_grille, &num_col, &num_ligne, &coup);
		
		num_grille = num_grille-1;
		int num_case = conversion_numcase(num_col, num_ligne);
		
		saisieCoup(pos_superM, num_grille, num_case, coup);
		
		//on vérifie que le coup est jouable
		//on met à jour le morpion
		pos_superM = saisieCoup(pos_superM, num_grille, num_case, coup);
		
		//on affiche le morpion
		affSuperM_standard(pos_superM);
		
		//on propose un morpion à l'ordi (imposé si non vide ou aléatoire)
		//int indice_morpion_pourJouer = detection_coup_jouable(num_case, pos_superM)+1;
		num_case = detection_coup_jouable(num_case, pos_superM);
		
		//l'ordi applique minimax sur le morpion
		//num_case++;
		int num_case2 = numCaseOrdiJoue(pos_superM, num_case, signeOrdi);
		printf("%d", num_case);
		printf("%d", num_case2);
		
		//on met à jour le supermorpion
		//num_case = num_case-1;
		pos_superM.grilles[num_case].cases[num_case2].joueur = signeOrdi;
		
		//on renvoie le résultat et on affiche le coup joué + supermorpion
		//que affichage pour le moment
		affSuperM_standard(pos_superM);
	}
	
	//printer le résultat
	
    
	return 0;  // Quitter avec succès
}
