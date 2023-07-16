#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

CardFour::CardFour()
{
	cardNumber = 4;
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{

}
Card* CardFour::GetMyCopy(const CellPosition& pos)
{
	return new CardFour(pos);	//returning new constructed CardFour in CellPosition passed to the function 
}

void CardFour::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);			//Printing card numbre and its position 

	OutFile << endl;
}

void  CardFour::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);		//loading card number and position 
}


void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	if (pPlayer->getpreventP() == 0)
	{
		Card::Apply(pGrid, pPlayer);

		pPlayer->setpreventP(1);
	}
	
	

	
	
}


