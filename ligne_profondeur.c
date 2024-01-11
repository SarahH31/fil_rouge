#include <stdio.h>
#include <stdlib.h>


// on écire en commande ./sm-refresh.exe 5
// on demande alors une profondeur d'horizon de 5 

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Erreur : Nombre incorrect d'arguments.");
        return 1;
    }

    int n = atoi(argv[1]);

	// reste du main

    return 0; 
}

