#include "CardEight.h"
CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

CardEight::CardEight()
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Please enter the amount to decrement from the player wallet:");
	int amount = pIn->GetInteger(pOut);
	walletAmount= amount ;

	pOut->ClearStatusBar();
}



void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Do you want pay or did't play 3 turns: enter (p or t)");
	
	if (pIn->GetSrting(pOut) == "p")
	{
		pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);
	}
	else
	{
		for(int i=0;i<3;i++)
		{
		 pPlayer->setpreventP(1);
		}
	}
	
}

Card* CardEight::GetMyCopy(const CellPosition& pos)
{
	return new CardEight(pos);		//returning new constructed CardEight in CellPosition passed to the function 
}

void CardEight::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);			//Printing card numbre and its position 

	OutFile << endl;
}

void  CardEight::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);		//loading card number and position 
}


CardEight::~CardEight(void)
{
}
