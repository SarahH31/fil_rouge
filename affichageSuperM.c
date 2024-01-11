#include <stdio.h>
#include "struct_sarah.h"
#ifndef AFFICHAGESUPERM_C
#define AFFICHAGESUPERM_C

void affSuperM_standard(position pos_etTrait){
	position pos = pos_etTrait;
	int i;
	int j;
	int i1;
	int i2;
	printf("-------------------------");
	printf("\n");
	printf("\n");
	printf("\n");
	for (i=0; i<7; i+=3){
		i1 = i+1;
		i2 = i+2;
		for (j=0; j<3; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i].cases[j].joueur);
		}
		printf("%c", ' ');
		printf("%c", ' ');
		printf("%c", ' ');
		for (j=0; j<3; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i1].cases[j].joueur);
		}
		printf("%c", ' ');
		printf("%c", ' ');
		printf("%c", ' ');
		for (j=0; j<3; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i2].cases[j].joueur);
		}
		printf("\n");
		
		for (j=3; j<6; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i].cases[j].joueur);
		}
		printf("%c", ' ');
		printf("%c", ' ');
		printf("%c", ' ');
		for (j=3; j<6; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i1].cases[j].joueur);
		}
		printf("%c", ' ');
		printf("%c", ' ');
		printf("%c", ' ');
		for (j=3; j<6; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i2].cases[j].joueur);
		}
		printf("\n");
		
		for (j=6; j<9; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i].cases[j].joueur);
		}
		printf("%c", ' ');
		printf("%c", ' ');
		printf("%c", ' ');
		for (j=6; j<9; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i1].cases[j].joueur);
		}
		printf("%c", ' ');
		printf("%c", ' ');
		printf("%c", ' ');
		for (j=6; j<9; j++){
			printf("%c", ' ');
			printf("%c", pos.grilles[i2].cases[j].joueur);
		}
		printf("\n");
		printf("\n");
		printf("\n");
		
		
	}
	
	printf("-------------------------");
	printf("\n");
}

#endif


