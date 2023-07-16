#include "CardNine.h"

#include "CellPosition.h"
#include "Ladder.h"
#include "Snake.h"

Player* CardNine::Owner = NULL;
int CardNine::Price = 0;
int CardNine::Fees = 0;
bool CardNine::isCardOwned = false;
bool CardNine::IsSaved = false;


CardNine::CardNine(const CellPosition& pos) : Card(pos), newCard(true)
{
	cardNumber = 9; 
}

CardNine::CardNine()
{
	cardNumber = 9;	// set the inherited cardNumber data member with the card number (1 here)
}

CardNine::~CardNine(void)
{
}



void CardNine::ReadCardParameters(Grid* pGrid)
{

	if (!newCard) // if the card is not on grid yet

	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		int x;
		pOut->PrintMessage("Enter card 11 station price :");
		x = pIn->GetInteger(pOut);
		while (x < 1)
		{
			if (x < 0) {
				pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed to  buy the cell ...");
				x = pIn->GetInteger(pOut);
			}
		}		 // validating the input not to be negative

		Price = x; // setting the price parameter

		int y;
		pOut->PrintMessage("Enter card 11 station fee :");
		y = pIn->GetInteger(pOut);

		while (y < 1)
		{
			pOut->PrintMessage("You entered an invalid Number: Plase enter The amount of coins needed  to pay fees to the player who owns the cell ...");
			y = pIn->GetInteger(pOut);

		}



		Fees = y; // setting the fee parameter



		pOut->ClearStatusBar();
		newCard = true;
	}
}


bool CardNine::StationIsBought()
{
	if (Owner == NULL)
	{
		return false; //not bought
	}
	else
	{
		return true; //bought
	}
}


void CardNine::BuyTheCard(Grid* pGrid, Player* pPlayer)
{
	if (!StationIsBought())
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();

		pOut->PrintMessage("This station worth " + to_string(Price) + ",Do you want to buy? (Y/N)");
		string Answer;
		Answer = pIn->GetSrting(pOut);

		while (Answer != "Y" || Answer != "N")
		{
			pOut->PrintMessage("Invalid character! Do you want to buy ? (Y/N)");
			string Answer = pIn->GetSrting(pOut);
		}
		if (Answer == "y" || Answer == "Y")
		{
			if (pPlayer->GetWallet() < Price)
				pOut->PrintMessage("Not Rich enough to buy the Station :)");
			else
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - Price);
				Owner = pPlayer;
				pOut->PrintMessage("Congratulations, you now own the station!");
			}
		}
		pOut->ClearStatusBar();
	}

}

void CardNine::FineStation(Grid* pGrid, Player* pPlayer)
{
	if (StationIsBought())
		if (Owner != pPlayer)
		{
			Output* pOut = pGrid->GetOutput();
			Input* pIn = pGrid->GetInput();

			pOut->PrintMessage("Congratulations! Player NO." + to_string(Owner->GetPlayerNum()) + " You will have  " + to_string(Fees) + " coins from the wallet of player NO." + to_string(pPlayer->GetPlayerNum()));

			pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
			Owner->SetWallet(Owner->GetWallet() + Fees);

			pOut->ClearStatusBar();

		}
}
void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	BuyTheCard(pGrid, pPlayer);
	FineStation(pGrid, pPlayer);
}



void CardNine::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);

	OutFile << "      " << this->celltogo.GetCellNum() << endl;
}

void  CardNine::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);

	int pos;
	InFile >> pos;
	this->celltogo = CellPosition::GetCellPositionFromNum(pos);
}

Card* CardNine::GetMyCopy(const CellPosition& pos)
{
	Card* pCard;
	pCard = new CardNine(pos);
	((CardNine*)pCard)->celltogo = this->celltogo;
	return pCard;

}

Player* CardNine::GetOwner()
{
	return Owner;
}

void CardNine::SetOwner(Player* Ptr)
{
	Owner = Ptr;
}