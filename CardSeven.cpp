#include "CardSeven.h"


CardSeven::CardSeven(const CellPosition &pos) : Card(pos)
{
	cardNumber = 7;
	newcellposition = pos;
}
CardSeven::CardSeven()
{
	cardNumber = 7;
}
void CardSeven::ReadCardParameters(Grid* pGrid) 
{
	
}
Card* CardSeven::GetMyCopy(const CellPosition& pos)
{
	return new CardSeven(pos);	//returning new constructed CardSeven in CellPosition passed to the function 
}

void CardSeven::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);			//Printing card numbre and its position 

	OutFile << endl;
}

void  CardSeven::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);		//loading card number and position 
}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer) 
{
	Card::Apply(pGrid, pPlayer);
	pGrid->AdvanceCurrentPlayer();
	pGrid->UpdatePlayerCell(pPlayer,newcellposition. GetCellPositionFromNum(1));
}
CardSeven::~CardSeven() 
{
	
}
