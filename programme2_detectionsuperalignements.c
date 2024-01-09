char détection_super_morpion(position sm) {
   
    char nouvelle_liste[9]={'.','.','.','.','.','.','.','.','.'}   #new_grille_m()??

    for (int i = 0; i < 9; i++) {
        char gagnant = partie_finie(sm.grilles[i]);  
        if (gagnant == 'x') {
            nouvelle_liste[i] = 'X';
        } else if (gagnant == 'o') {
            nouvelle_liste[i] = 'O';
        } else if (gagnant == 'd') {
            nouvelle_liste[i] = 'D';
        } else {
            nouvelle_liste[i] = ' ';
        }}
    

    #détection des super alignements
return partie_finie(nouvelle_liste[9])}
