#pragma once
#pragma once

#include "Card.h"

class CardThree : public Card
{
	
		
	
	public:
		CardThree(const CellPosition& pos); 
		CardThree();
		virtual void ReadCardParameters(Grid* pGrid); 

		virtual void Apply(Grid* pGrid, Player* pPlayer); 
		virtual Card* GetMyCopy(const CellPosition&);			//returns a new constructed CardThree with same datamembers

		virtual void Save(ofstream& OutFile);					// Saves Card's data 

		virtual void Load(ifstream& InFile, Grid* pGrid);		// Loads and Reads the GameObject parameters from the file

		virtual ~CardThree(); 
};
