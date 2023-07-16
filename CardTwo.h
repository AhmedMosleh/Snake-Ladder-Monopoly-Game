#pragma once
#include "Card.h"

class CardTwo :public Card 
{
private:

	CellPosition  newcellposition;

public:
	CardTwo(const CellPosition& pos);
	CardTwo(); // default const.
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	Card* GetMyCopy(const CellPosition& pos);				//returns a new constructed CardTwo with same datamembers (walletamount)

	virtual void Save(ofstream& OutFile);					// Saves Card's data 

	virtual void Load(ifstream& InFile, Grid* pGrid);		// Loads and Reads the GameObject parameters from the file

	~CardTwo();
};


