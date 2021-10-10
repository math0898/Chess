#include <stdio.h>
#include <stdlib.h>
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
        strcpy(c, NO_COLOR);
        strcat(c, ".");
        return c;
    }
    piece < 17 ? strcpy(c, WHITE_COLOR) : strcpy(c, BLACK_COLOR);
    switch (piece % 10) {
        case 1: strcat(c, "P"); break;
        case 2: strcat(c, "R"); break;
        case 3: strcat(c, "N"); break;
        case 4: strcat(c, "B"); break;
        case 5: strcat(c, "Q"); break;
        case 6: strcat(c, "K"); break;
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
Game* createGame (int bot) {
    Game* toReturn = malloc(sizeof(Game));
    if (toReturn == NULL) return NULL;
    if (bot) {
        int temp[8][8] = { {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK},
                           {BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,  BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN},
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,  WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN},
                           {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK}};
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) toReturn->board[i][j] = temp[i][j];
    } else {
        int temp[8][8] = { {WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK},
                           {WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN,  WHITE_PAWN, WHITE_PAWN,   WHITE_PAWN,   WHITE_PAWN},
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE,    NO_PIECE,   NO_PIECE,     NO_PIECE,     NO_PIECE  },
                           {BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN,  BLACK_PAWN, BLACK_PAWN,   BLACK_PAWN,   BLACK_PAWN},
                           {BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK}};
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) toReturn->board[i][j] = temp[i][j];
    }
    toReturn->focused[0] = -1;
    toReturn->focused[1] = -1;
    return toReturn;
}

/**
 * Displays the chess board to console using the appropriate colors for each team. //todo implement highlighting of pieces.
 * 
 * @param game The game that is being printed to console.
 */
void displayGame (Game* game) {
    printf("\n\n      1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("  %c : ", 'a' + i);
        for (int j = 0; j < 8; j++) {
            printf("%s ", getString(game->board[i][j]));
        }
        printf("%s\n", NO_COLOR);
    }
    printf("\n");
}