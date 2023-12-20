typedef struct {
    char joueur; // 'o', 'x', ou ' ' (vide)
} Case;

typedef struct {
    Case cases[9]; 
} grille_m;


typedef struct {
    grille_m grilles[9]; 
    char joueurActuel;
} position;
