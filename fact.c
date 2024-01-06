#include <stdio.h>
#include <stdlib.h>
#include "fact.h"


// recodage de la fonction factorielle
int fact(int n){
	if (n<=1){
		return n;
	}
	return (n*fact(n-1));
}
