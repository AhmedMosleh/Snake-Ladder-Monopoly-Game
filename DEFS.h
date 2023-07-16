#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action
	COPY_CARD,		// Copy Card Action
	PASTE_CARD,		// Paste Card Action
	CUT_CARD,		// Cut Card Action
	DELETE_OPJECT,	// Delete Game Object Card Action
	SAVE_GRID,		// Save Grid Card Action
	OPEN_GRID,		// Open Grid Card Action
	TO_PLAY_MODE,	// Go to Play Mode
	EXIT,			// Exit Application


	///*TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	DICE_VALUE,		// Input Dice Value
	NEW_GAME,		// New Game Action
	TO_DESIGN_MODE,	// Go to Design Mode
	EXIT_GAME,		// Exit Application		


	///*TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};


enum ObjectType
{
	TLadder,
	TSnake,
	TCard,

};

enum type
{
	ladder,
	snake,
	card
};


#endif