#pragma once
#pragma once
#include "Card.h"

class CardFive :public Card
{
	CellPosition newcellposition;
public:
	CardFive(const CellPosition &pos);
	CardFive();
	void ReadCardParameters(Grid* pGrid);

	void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* GetMyCopy(const CellPosition&);		//returns a new constructed CardFive with same datamembers 

	virtual void Save(ofstream& OutFile);				// Saves Card's data 

	virtual void Load(ifstream& InFile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

	~CardFive();

};
