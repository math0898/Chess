#ifndef INPUT_H
#define INPUT_H

#include "game.h"

/**
 * Prompts the user for a piece selection and a creates a move from their response. 
 * This even checks that the move selected is legal and prompts the user to change
 * parts of it if the move would be otherwise illegal.
 * 
 * @param game The current game state which the move is being selected for.
 * @return The move selected by the player.
 */
Move* getMove (Game* game);

/**
 * This checks if the given selection is legal for the player. In the future it may
 * need to depend on which player is at the bottom of the map but for now it need
 * only check if the piece is a white piece.
 * 
 * @param game The current game state.
 * @param sel The selection the legality is being determined.
 * @return True if the selection is legal, otherwise false.
 */
int legalSelection (Game* game, int sel[2]);

/**
 * This checks if the given move is legal or not. It starts at the first int array
 * and looks to see if it can move to the second int array.
 * 
 * @param game The current game state.
 * @param sel The piece selected.
 * @param tar The target location to move the piece.
 * @return True if and only if the move is legal.
 */
int legalMove (Game* game, int sel[2], int tar[2]);

#endif