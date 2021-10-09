#include <stdio.h>
#include <string.h>
#include "game.h"
#include "pieces.h"

/**
 * Returns the char array representation of the given piece.
 * 
 * @param piece The piece a representation of needs to be found.
 * @return The char array representation preappended with the team color. The char array can be expected
 *         to be null terminated and possess fewer than 10 characters.
 */
char* getString (int piece) {
    char* c = malloc(sizeof(char) * 10);
    if (piece == NO_PIECE) {
        strcpy(&c, NO_COLOR);
        strcat(&c, '.');
        return c;
    }
    piece < 17 ? strcpy(&c, WHITE_COLOR) : strcpy(&c, BLACK_COLOR);
    switch (piece % 10) {
        case 1: strcat(&c, 'P'); break;
        case 2: strcat(&c, 'R'); break;
        case 3: strcat(&c, 'N'); break;
        case 4: strcat(&c, 'B'); break;
        case 5: strcat(&c, 'Q'); break;
        case 6: strcat(&c, 'K'); break;
    }
    return c;
}

/**
 * Creates the actual game object by allocating it on the stack. The returned game is ready to play
 * and has all of the pieces in their starting position. 
 * 
 * @param bot The integer is a flag to represent whether white or black is on the bottom of the board.
 *            0 - White is on the bottom, not(0) - Black is on the bottom.
 * @return A game that is ready to play and initalized to the starting positions. If for some reason
 *         memory allocation fails this could be NULL.
 */
Game* createGame (int bot) { //todo reduce scope.
    Game* toReturn = malloc(sizeof(Game));
    if (toReturn) return NULL;
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) toReturn->board[i][j] = NO_PIECE;
    for (int i = 0; i < 8; i++) {
        if (bot) {
            toReturn->board[1][i] = BLACK_PAWN;
            toReturn->board[6][i] = WHITE_PAWN;
        } else {
            toReturn->board[1][i] = WHITE_PAWN;
            toReturn->board[6][i] = BLACK_PAWN; 
        }
    }
    if (bot) {
        for (int i = 0; i <= 4; i++) {
            toReturn->board[0][i] = 22 + i; //Black pieces
            toReturn->board[0][7 - i] = 22 + i;
            toReturn->board[7][i] = 12 + i; //White pieces
            toReturn->board[7][7 - i] = 12 + i;
        }
        toReturn->board[0][4] = BLACK_KING;
        toReturn->board[7][4] = WHITE_KING;
    } else {
        for (int i = 0; i <= 4; i++) {
            toReturn->board[7][i] = 22 + i; //Black pieces
            toReturn->board[7][7 - i] = 22 + i;
            toReturn->board[0][i] = 12 + i; //White pieces
            toReturn->board[0][7 - i] = 12 + i;
        }
        toReturn->board[7][4] = BLACK_KING;
        toReturn->board[0][4] = WHITE_KING;
    }
    toReturn->focused[0] = -1;
    toReturn->focused[1] = -1;
    return toReturn;
}

/**
 * Displays the chess board to console using the appropriate colors for each team. //todo implement highlighting of pieces.
 * 
 * @param board The game that is being printed to console.
 */
void displayGame (Game* board) {
    printf("Uh... in development.\n");
}