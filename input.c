#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "pieces.h"

#ifndef ERROR_COLOR
#define ERROR_COLOR "\x1b[31m"
#endif

/**
 * This checks if the given move is legal or not. It starts at the first int array
 * and looks to see if it can move to the second int array.
 * 
 * @param game The current game state.
 * @param sel The piece selected.
 * @param tar The target location to move the piece.
 * @return True if and only if the move is legal.
 */
int legalMove (Game* game, int sel[2], int tar[2]) {
    int target = game->board[tar[1]][tar[0]];
    int source = game->board[sel[1]][sel[0]];
    if (source / 10 == target / 10) return 0; // Can't take own pieces.
    else if (source % 10 == WHITE_PAWN % 10) {
        if (target != NO_PIECE && abs(sel[0] - tar[0]) == 1 && sel[1] - tar[1] == (source == WHITE_PAWN ?  -1 : 1)) return 1; // Taking a piece
        else if (target == NO_PIECE && sel[1] == (source == WHITE_PAWN ? 1 : 6) && abs(sel[1] - tar[1]) == 2 && sel[0] == tar[0]) return 1; // Double move
        else if (target == NO_PIECE && abs(sel[1] - tar[1]) == 1 && sel[0] == tar[0]) return 1; // Single move
    } else if (source % 10 == WHITE_ROOK % 10) {
        if (sel[0] == tar[0]) {
            for (int i = sel[1]; i <= tar[1]; i++) if (game->board[i][tar[0]] != NO_PIECE) return 0; // Check for piece jumping. 
            for (int i = sel[1]; i >= tar[1]; i--) if (game->board[i][tar[0]] != NO_PIECE) return 0;
            return 1;
        } else if (sel[1] == tar[1]) {
            for (int i = sel[0]; i <= tar[0]; i++) if (game->board[tar[1]][i] != NO_PIECE) return 0; // Check for piece jumping. 
            for (int i = sel[0]; i >= tar[0]; i--) if (game->board[tar[1]][i] != NO_PIECE) return 0;
            return 1;
        }
    }
    return 0; //todo implement.
}

/**
 * This checks if the given selection is legal for the player. In the future it may
 * need to depend on which player is at the bottom of the map but for now it need
 * only check if the piece is a white piece.
 * 
 * @param game The current game state.
 * @param sel The selection the legality is being determined.
 * @return True if the selection is legal, otherwise false.
 */
int legalSelection (Game* game, int sel[2]) {
    if (game->board[sel[1]][sel[0]] >= 10 && game->board[sel[1]][sel[0]] <= 17) return 1;
    return 0;
}

/**
 * Prompts the user for a piece selection and a creates a move from their response. 
 * This even checks that the move selected is legal and prompts the user to change
 * parts of it if the move would be otherwise illegal.
 * 
 * @param game The current game state which the move is being selected for.
 * @return The move selected by the player.
 */
Move* getMove (Game* game) {
    int c[2] = { -1, -1 };
    int t[2] = { 0 };
    Move* toReturn = createMove(c, c);
    while (1) {
        if (toReturn->tar[0] > -1) break;
        else if (toReturn->sel[0] > -1) {
            game->focused[0] = toReturn->sel[0];
            game->focused[1] = toReturn->sel[1];
        }
        displayGame(game);
        printf("  > ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            toReturn->exit = 1;
            break;
        } else if (strcmp(input, "back") == 0) {
            toReturn->sel[0] = -1;
            toReturn->sel[1] = -1;
            game->focused[0] = -1;
            game->focused[1] = -1;
        } else if (strlen(input) == 2) { //todo implement conversion from standard chess moves into this system.
            t[0] = ((int) input[0]) - 'a'; 
            t[1] = ((int) input[1]) - '1'; //Kind of odd but needed.
            if (t[0] < 0 || t[1] < 0 || t[0] > 7 || t[1] > 7) printf("     %sSomething seems off about those cooridnates.\n%s", ERROR_COLOR, NO_COLOR);
            else {
                if (toReturn->sel[0] > -1) {
                    if (legalMove(game, toReturn->sel, t)) {
                        toReturn->tar[0] = t[0];
                        toReturn->tar[1] = t[1];
                    } else printf("     %sNot a legal move!%s\n", ERROR_COLOR, NO_COLOR);
                } else {
                    if (legalSelection(game, t)) {
                        toReturn->sel[0] = t[0];
                        toReturn->sel[1] = t[1];
                    } else printf("     %sNot a legal piece selection!%s\n", ERROR_COLOR, NO_COLOR);
                }
            }
        } else printf("     %sEnter the coordinates of the piece to move.%s (e4)\n", ERROR_COLOR, NO_COLOR);
    }
    game->focused[0] = -1;
    game->focused[1] = -1;
    return toReturn;
}