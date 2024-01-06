#include <stdio.h>
#include "grille.h"

//fonction de détection des alignements pour savoir si partie est finie ou pas

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

	// cas où non finie (= n)
	for (i=0; i<9; i++){
		if (grille.cases[i].joueur == '.'){
			//partie non finie = n
			return 'n';
		}
	}

	//cas où match nul = d
	return 'd';
}

//fonction min_max
//renvoie 1 si la position donnée est gagnante pour nous si on joue les meilleurs coups
//renvoie 0 si la position donnée menera à un match nul si les 2 joueurs jouent les meilleurs coups
//renvoie -1 si la position donnée est perdante pour nous si notre adversaire joue les meilleurs coups

//je rajouterai des commentaires sur cette fonction plus tard
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
