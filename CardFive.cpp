#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos)
{
	cardNumber = 5 ;
	newcellposition = pos;
}

CardFive::CardFive()
{
	cardNumber = 5;
}

void CardFive::ReadCardParameters(Grid* pGrid)
{

}
Card* CardFive::GetMyCopy(const CellPosition& pos)
{
	return new CardFive(pos);	//returning new constructed CardFive in CellPosition passed to the function 
}

void CardFive::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);			//Printing card numbre and its position 

	OutFile << endl;
}

void  CardFive::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);		//loading card number and position 
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	newcellposition.AddCellNum(-(pPlayer->GetjustRolledDiceNum()));
	pGrid->UpdatePlayerCell(pPlayer, newcellposition);

}

CardFive::~CardFive()
{

}
