#include "CardThree.h"


CardThree::CardThree(const CellPosition& pos) : Card(pos)
{
	cardNumber = 3;
}

CardThree::CardThree()
{
	cardNumber = 3;
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{

}
Card* CardThree::GetMyCopy(const CellPosition& pos)
{
	return new CardThree(pos);		//returning new constructed CardThree in CellPosition passed to the function 
}

void CardThree::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);			//Printing card numbre and its position 

	OutFile << endl;
}

void  CardThree::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);		//loading card number and position 
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);

	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->PrintErrorMessage("You have an extra dice roll. Click to continue ...");



}


