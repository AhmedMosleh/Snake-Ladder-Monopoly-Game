#pragma once
#pragma once
#include"CellPosition.h"
#include "Card.h"

class CardSix : public Card
{
	CellPosition CellToMoveto;
public:
	CardSix(const CellPosition& pos);
	CardSix();
	virtual void ReadCardParameters(Grid* pGrid);  

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* GetMyCopy(const CellPosition&);		//returns a new constructed CardSix with same datamembers 

	virtual void Save(ofstream& OutFile);				// Saves Card's data 

	virtual void Load(ifstream& InFile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

	virtual ~CardSix();
};


