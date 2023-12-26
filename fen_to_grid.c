#include <stdio.h>
#include <string.h>

#define MAX_LEN 9

void displayBoard(char board[MAX_LEN]) {
    for (int i = 0; i < MAX_LEN; i++) {
        printf("%c ", board[i]);
    }
    printf("\n");
}

int getBoard(char *fen, char board[MAX_LEN]) {
    int rank = 0, file = 0;
    char *ptr = strtok(fen, " ");
    if (ptr == NULL) return 0;
    for (int i = 0; i < strlen(ptr); i++) {
        if (ptr[i] == '/') {
            rank++;
            file = 0;
        } else if (isdigit(ptr[i])) {
            file += ptr[i] - '0';
        } else {
            board[rank * MAX_LEN + file] = ptr[i];
            file++;
        }
    }
    return 1;
}

char getPlayer(char *fen) {
    char *ptr = strtok(NULL, " ");
    if (ptr == NULL) return '\0';
    return ptr[0];
}

int main() {
    char FEN[MAX_LEN * MAX_LEN + 1]; // Modification de la taille du tableau FEN
    printf("Entrez la liste FEN: ");
    fgets(FEN, MAX_LEN * MAX_LEN + 1, stdin); // Modification de la fonction fgets pour correspondre à la nouvelle taille du tableau FEN
    printf("Liste FEN entrée: %s\n", FEN); // Ajout de ce "printf" pour afficher la liste FEN entrée par l'utilisateur

    char board[MAX_LEN];
    memset(board, '.', sizeof(board));

    if (!getBoard(FEN, board)) {
        printf("Erreur dans la lecture de la liste FEN.\n");
        return 1;
    }

    char player = getPlayer(FEN);

    displayBoard(board);

    if (player != '\0') {
        printf("Joueur au trait: %c\n", player);
    } else {
        printf("Information sur le joueur actuel non disponible.\n");
    }

    return 0;
}
