#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pieces.h"
#include "game.h"
#include "input.h"

/**
 * Main.c is the main execution point of chess. For the sake of practice a single command line argument is taken which can specify the side
 * that the player controls. If one is not specified the side is random. 
 * 
 * @return -1 - Failed to initialize game. Not enough memory.
 * @return 0 - No errors, exit on game complition.
 * @return 1 - No errors, exited on player entering exit.
 */
int main () {
    Game* game = createGame(0);
    int x = 0;
    if (game == NULL) {
        printf("Failed to allocate enough memory for the board.\n");
        return -1;
    }
    while (x == 0) {
        Move* move = getMove(game);
        if (move->exit) {
            x = 1;
            continue;
        }
    }
    printf("\n");
    return x;
}