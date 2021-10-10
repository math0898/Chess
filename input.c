#include <stdio.h>
#include <string.h>
#include "game.h"

/**
 * Prompts the user for a piece selection and a creates a move from their response. 
 * This even checks that the move selected is legal and prompts the user to change
 * parts of it if the move would be otherwise illegal.
 * 
 * @param game The current game state which the move is being selected for.
 * @return The move selected by the player.
 */
Move* getMove (Game* game) {
    Move* toReturn = NULL;
    while (!toReturn) {
        printf("  > ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            int c[2] = { 0, 0};
            toReturn = createMove(c, c);
            toReturn->exit = 1;
            break;
        }
    }
    return toReturn;
}