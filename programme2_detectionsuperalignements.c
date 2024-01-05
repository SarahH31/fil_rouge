int main() {
    char super_morpion[9][9];  #??
    char nouvelle_liste[9];  #new_grille_m()??

    // ... code pour remplir super_morpion ...

    for (int i = 0; i < 9; i++) {
        char gagnant = partie_finie(super_morpion[i]);  #changer le nom de l'argument
        if (gagnant == 'x') {
            nouvelle_liste[i] = 'X';
        } else if (gagnant == 'o') {
            nouvelle_liste[i] = 'O';
        } else if (gagnant == 'd') {
            nouvelle_liste[i] = 'D';
        } else {
            nouvelle_liste[i] = ' ';
        }
    }

    #détection des super alignements
return partie_finie(nouvelle_liste[9])
