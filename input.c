#include <stdio.h>
#include <string.h>
#include "game.h"

#ifndef ERROR_COLOR
#define ERROR_COLOR "\x1b[31m"
#endif
#ifndef NO_COLOR
#define NO_COLOR "\x1b[0m"
#endif

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
    Move* toReturn = createMove(c, c);
    while (1) {
        if (toReturn->tar[0] > -1) break; //todo add check for legal move and legal selection.
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
            toReturn->sel[0] = c[0];
            toReturn->sel[1] = c[0];
        } else if (strlen(input) == 2) {
            int i = ((int) input[0]) - 'a';
            int j = ((int) input[1]) - '0';
            if (i < 0 || j < 0 || i > 7 || j > 7) printf("     %sSomething seems off about those cooridnates.\n%s", ERROR_COLOR, NO_COLOR);
            else {
                if (toReturn->sel[0] > -1) {
                    toReturn->tar[0] = i;
                    toReturn->tar[1] = j;
                } else {
                    toReturn->sel[0] = i;
                    toReturn->sel[1] = j;
                }
            }
        } else printf("     %sEnter the coordinates of the piece to move.%s (e4)\n", ERROR_COLOR, NO_COLOR);
    }
    return toReturn;
}