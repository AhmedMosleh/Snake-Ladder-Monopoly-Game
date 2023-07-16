#pragma once
#include "Card.h"
class CardSeven :public Card
{
	CellPosition newcellposition;
public:
	CardSeven(const CellPosition& pos);
	CardSeven();
	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* GetMyCopy(const CellPosition&);		//returns a new constructed CardSeven with same datamembers 

	virtual void Save(ofstream& OutFile);				// Saves Card's data 

	virtual void Load(ifstream& InFile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

	virtual ~CardSeven();
};

