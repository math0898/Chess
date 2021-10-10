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
     * highlight pieces. The array has it stored as (x,y).
     */
    int focused[2];

} Game;

/**
 * This struct describes the way that a move is defined within the game. It has coordinates to the piece 
 * selection and the target position.
 */
typedef struct move {

    /**
     * A 2d int array used to describe the location of the piece selected.
     */
    int sel[2];

    /**
     * Another 2d int array which is used to describe the location that the piece would like to move to.
     */
    int tar[2];

    /**
     * This is set to 1 in the case that a player would like to exit the game. It is used by the move
     * input section to notify main that a player wishes to exit the game.
     */
    int exit;

} Move;

/**
 * Returns the char array representation of the given piece.
 * 
 * @param piece The piece a representation of needs to be found.
 * @return The char array representation preappended with the team color. The char array can be expected
 *         to be null terminated and possess fewer than 10 characters.
 */
char* getString (int piece);

/**
 * Creates a new move based on the given int arrays. Used to make sure things are created on the heap
 * instead of the stack.
 * 
 * @param sel The integer array describing the piece to be moved.
 * @param tar The target position as described by an integer array.
 */
Move* createMove (int sel[2], int tar[2]);

/**
 * Makes the given move for the given game. This functions preforms no checks on the given move to
 * determine its legality and simply carries out the movement.
 * 
 * @param game The game this move is taking place in.
 * @param move The move to take place. 
 */
void makeMove (Game* game, Move* move);

/**
 * Creates the actual game object by allocating it on the stack. The returned game is ready to play
 * and has all of the pieces in their starting position. 
 * 
 * @param bot The integer is a flag to represent whether white or black is on the bottom of the board.
 *            0 - White is on the bottom, not(0) - Black is on the bottom.
 * @return A game that is ready to play and initalized to the starting positions. If for some reason
 *         memory allocation fails this could be NULL.
 */
Game* createGame (int bot);

/**
 * Displays the chess board to console using the appropriate colors for each team. Additionally if a 
 * board position is specified under game->focused it will be highlighted in bold.
 * 
 * @param game The game that is being printed to console.
 */
void displayGame (Game* game);

#endif