#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pieces.h"

/**
 * Main.c is the main execution point of chess. For the sake of practice a single command line argument is taken which can specify the side
 * that the player controls. If one is not specified the side is random. 
 * 
 * @return 0 - No errors, exit on game complition.
 * @return 1 - No errors, exited on player entering x.
 */
int main () {
    int x = 0;
    printf("%sGame started!%s\n", WHITE_COLOR, NO_COLOR);
    while (x == 0) {
        char input[10] = { '0' }; 
        scanf("%s", input);
        if (!strcmp(input, "exit")) {
            x = 1;
            continue;
        }
    }
    printf("%sGoodbye!%s\n", BLACK_COLOR, NO_COLOR);
    return x;
}