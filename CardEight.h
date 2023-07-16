#pragma once
#include "Card.h"
class CardEight :public Card
{
	int walletAmount;
public:
	CardEight(const CellPosition& pos);
	CardEight();
	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual Card* GetMyCopy(const CellPosition&);		//returns a new constructed CardEight with same datamembers 

	virtual void Save(ofstream& OutFile);				// Saves Card's data 

	virtual void Load(ifstream& InFile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

	virtual ~CardEight();
};

