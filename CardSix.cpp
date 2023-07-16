#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos ) : Card(pos)
{
	cardNumber = 6;	//sets the inherited cardNumber data member with the card number
}

CardSix::CardSix()
{
	cardNumber = 6;	//sets the inherited cardNumber data member with the card number
}


void CardSix::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CardSix: Click on the Cell to Move to");
	CellToMoveto = pIn->GetCellClicked();
	pOut->ClearStatusBar();


}


void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	
	pGrid->PrintErrorMessage("You will Move to Cell Num " + to_string(CellToMoveto.GetCellNum())+". Click to continue ...");
	pGrid->UpdatePlayerCell(pPlayer, CellToMoveto);


}


Card* CardSix::GetMyCopy(const CellPosition& pos)
{
	return new CardSix(pos);	//returning new constructed CardSix in CellPosition passed to the function 
}

void CardSix::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);			//Printing card numbre and its position 

	OutFile << endl;
}

void  CardSix::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);		//loading card number and position 
}
CardSix::~CardSix(void)
{
}
