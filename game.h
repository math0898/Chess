#ifndef GAME_H
#define GAME_H

/**
 * This is the actual struct that defines the board game itself. It defines the field.
 */
typedef struct game {

    /**
     * This is the actual array of the board. It is a double int array which is 8x8 and each element is a member of
     * the pieces.h constants.
     */
    int board[8][8];

    /**
     * The coordinates of the position of the board that is currently in focus. This is used by displayGame to
     * highlight pieces. The array has it stored as (y,x).
     */
    int focused[2];

} Game;

/**
 * Returns the char array representation of the given piece.
 * 
 * @param int The piece a representation of needs to be found.
 * @return The char array representation preappended with the team color. The char array can be expected
 *         to be null terminated and possess fewer than 10 characters.
 */
char* getString (int);

/**
 * Creates the actual game object by allocating it on the stack. The returned game is ready to play
 * and has all of the pieces in their starting position. 
 * 
 * @param int The integer is a flag to represent whether white or black is on the bottom of the board.
 *            0 - White is on the bottom, not(0) - Black is on the bottom.
 * @return A game that is ready to play and initalized to the starting positions. If for some reason
 *         memory allocation fails this could be NULL.
 */
Game* createGame (int);

/**
 * Displays the chess board to console using the appropriate colors for each team.
 * 
 * @param Game* The game that is being printed to console.
 */
void displayGame (Game*);

#endif