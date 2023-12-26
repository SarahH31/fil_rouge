#include <stdio.h>
#include <stdlib.h>
#include "grille.c"



int main(){

	grille_m morpion = new_grille_m();
	
	// estJouable("9 01");


	actualise_dot(&morpion, "graphviz_output.dot");

   	// commande convertit le fichier DOT en PNG
	system("dot -Tpng graphviz_output.dot -o graphviz_output.png");

	return 0;

}
