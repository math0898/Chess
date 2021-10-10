#ifndef INPUT_H
#define INPUT_H

#include "game.h"

/**
 * Prompts the user for a piece selection and a creates a move from their response. 
 * This even checks that the move selected is legal and prompts the user to change
 * parts of it if the move would be otherwise illegal.
 * 
 * @param Game* The current game state which the move is being selected for.
 * @return The move selected by the player.
 */
Move* getMove (Game*);

#endif