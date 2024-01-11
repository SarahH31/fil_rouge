#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "struct_sarah.h"
#ifndef CHOIXCOUPORDI_C
#define CHOIXCOUPORDI_C

int conversion_numcase(char num_col, int num_ligne){

	int num_case;
	if (num_col=='a' && num_ligne==1) {
		num_case = 0;
	}
	else if (num_col=='b' && num_ligne==1) {
		num_case = 1;
	}
	else if (num_col=='c' && num_ligne==1) {
		num_case = 2;
	}
	else if (num_col=='a' && num_ligne==2) {
		num_case = 3;
	}
	else if (num_col=='b' && num_ligne==2) {
		num_case = 4;
	}
	else if (num_col=='c' && num_ligne==2) {
		num_case = 5;
	}
	else if (num_col=='a' && num_ligne==3) {
		num_case = 6;
	}
	else if (num_col=='b' && num_ligne==3) {
		num_case = 7;
	}
	else if (num_col=='c' && num_ligne==3) {
		num_case = 8;
	}
	
	return num_case;
}

position saisieCoup(position morpion, int num_grille, int num_case, char coup){

	// Vérifier si le coup est valide
	if ((morpion.grilles[num_grille].cases[num_case].joueur == 'x') || (morpion.grilles[num_grille].cases[num_case].joueur == 'o')){
		printf("Coup invalide. Cette case est déjà occupée.\n");
		return morpion;
	}

	// Mettre à jour la chaîne fen
	else {
		morpion.grilles[num_grille].cases[num_case].joueur = coup;
	}

	return morpion;
}

char partie_finie(grille_m grille){
	int i;
	int j;
	int k;
	//vérification des colonnes
	for (i=0; i<3; i++){
		j = i + 3;
		k = i + 6;

		if ((grille.cases[i].joueur == grille.cases[j].joueur) && (grille.cases[i].joueur == grille.cases[k].joueur) && (grille.cases[i].joueur != '.')){
			return grille.cases[i].joueur;
		}
	}
	//vérification des lignes
	for (i=0; i<7; i+=3){
		j = i + 1;
		k = i + 2;
		if ((grille.cases[i].joueur == grille.cases[j].joueur) && (grille.cases[i].joueur == grille.cases[k].joueur) && (grille.cases[i].joueur != '.')){
			return grille.cases[i].joueur;
		}
	}
	//vérification de la diagonale 1
	i = 2;
	j = 4;
	k = 6;
	if ((grille.cases[i].joueur == grille.cases[j].joueur) && (grille.cases[i].joueur == grille.cases[k].joueur) && (grille.cases[i].joueur != '.')){
		return grille.cases[i].joueur;
	}
	//vérification de la diagonale 2
	i = 0;
	j = 4;
	k = 8;
	if ((grille.cases[i].joueur == grille.cases[j].joueur) && (grille.cases[i].joueur == grille.cases[k].joueur) && (grille.cases[i].joueur != '.')){
		return grille.cases[i].joueur;
	}
	//cas de match nul + cas où non finie
	for (i=0; i<9; i++){
		if (grille.cases[i].joueur == '.'){
			//partie non finie = n
			return 'n';
		}
	}
	//match nul = d
	return 'd';
}

int min_max2(grille_m grille, char joueur_nous, char joueur_auTrait){
	int i;
	int val_defaut;
	
	//cas de base
	if (partie_finie(grille)!='n'){
		//cas où le joueur a gagné
		if (partie_finie(grille) == joueur_nous){
			return 1;
		}
		//match nul
		if (partie_finie(grille) == 'd'){
			return 0;
		}
		//cas où le joueur a perdu
		return -1;
	}
	
	//cas général

	char val_c[9];
	
	if (joueur_nous == joueur_auTrait){
		val_defaut = -10;
	}else{
		val_defaut = 10;
	}
	//printf("%d\n", val_defaut);
	for (i=0; i<9; i++){
		if (grille.cases[i].joueur == '.'){
			grille.cases[i].joueur = joueur_auTrait;
			if (joueur_auTrait=='x'){
				val_c[i] = min_max2(grille, joueur_nous, 'o');
			}else{
				val_c[i] = min_max2(grille, joueur_nous, 'x');
			}
			grille.cases[i].joueur = '.';
		}else{
			val_c[i] = val_defaut;
		}
	}
		
	int mini_maxi = val_c[0];
	for (i=1; i<9; i++){
		if ((joueur_nous == joueur_auTrait) && (val_c[i]>mini_maxi) && (val_c[i]!=10)){
			mini_maxi = val_c[i];
		}
		if ((joueur_nous != joueur_auTrait) && (val_c[i]<mini_maxi) && (val_c[i]!=-10)){
			mini_maxi = val_c[i];
		}
	}
	//printf("%d\n", mini_maxi);
	return mini_maxi;
}

grille_m morpion_duSuperM(position sm){
	grille_m nouvelle_liste;

   	for (int i = 0; i < 9; i++) {
		char gagnant;
		gagnant = partie_finie(sm.grilles[i]);  
		if (gagnant == 'x') {
			nouvelle_liste.cases[i].joueur = 'X';
		} else if (gagnant == 'o') {
			nouvelle_liste.cases[i].joueur = 'O';
		} else if (gagnant == 'd') {
			nouvelle_liste.cases[i].joueur = 'D';
		} else {
			nouvelle_liste.cases[i].joueur = '.';
		}
	
	}
	return nouvelle_liste;
}

char detection_super_morpion(position sm) {
	grille_m SM;
	SM = morpion_duSuperM(sm);  

	//détection des super alignements
	return partie_finie(SM);
}

int detection_coup_jouable(int indice, position sm){

	//recup indice pour verif si partie finie, si pas fini min max appliqué à la grille de cet indice, sinon choix parmi tt
	
	//on est obligé de jouer dans le morpion car il est non fini
	if ((partie_finie(sm.grilles[indice]))=='n'){
		return indice;
	}
	
	//cas où le morpion où on doit jouer est rempli, on peut alors jouer sur n'importe quel autre morpion non plein
	if ((partie_finie (sm.grilles[indice]))!='n'){
		int a = indice;
		while((partie_finie(sm.grilles[a]))!='n'){
			srand(time(NULL));
			
			// Générez un nombre aléatoire entre 0 et 8
			a = rand() % 9;

		}

		return a;
	}
}


int numCaseOrdiJoue(position pos, int numMorpion, char ordi){
	grille_m grille = pos.grilles[numMorpion];
	int k;
	int indiceOrdi;
	int min_max =-10;
	int transi;
	for (k=0; k<9; k++){
		if (grille.cases[k].joueur == '.'){
			transi = min_max2(grille, ordi, ordi);
			printf("\n");
			printf("%d", transi);
			printf("\n");
			if (min_max<transi){
				min_max = transi;
				indiceOrdi = k;
			}
		}
			
	}
	
	return indiceOrdi;
}

#endif
