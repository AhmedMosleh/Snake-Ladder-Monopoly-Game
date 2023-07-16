#include "CardEleven.h"
bool CardEleven::ongrid = false; // setting ongird intially as false
Player* CardEleven::Owner = NULL;
int CardEleven::Price = 0;
int CardEleven::Fees = 0;
bool CardEleven::isCardOwned = false;
bool CardEleven::IsSaved = false;


CardEleven::CardEleven(const CellPosition& pos) : Card(pos), newCard(true)
{
	cardNumber = 11;
}

CardEleven::CardEleven()
{
}

CardEleven::~CardEleven(void)
{
	cardNumber = 11;

}
void CardEleven::SetOwner(Player* Ptr)
{
	Owner = Ptr;
}

Player* CardEleven::GetOwner()
{
	return Owner;
}

void CardEleven::setongridfalse()
{
	ongrid = false;
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{

	if (!newCard) // checking the existence of card on grid

	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		int x;
		pOut->PrintMessage("Enter card 11 station price :");
		x = pIn->GetInteger(pOut);
		while (x < 1)
		{
			if (x < 0) {
				pOut->PrintMessage(" Invalid Number!Pay Card 11 station price");
				x = pIn->GetInteger(pOut);
			}
		}		 // validating the input not to be negative

		Price = x; // setting the price 

		int y;
		pOut->PrintMessage("You are fined for resting on card 11");
		y = pIn->GetInteger(pOut);

		while (y < 1)
		{
			pOut->PrintMessage("Invalid Number!: Plase pay your Fine");
			y = pIn->GetInteger(pOut);

		}



		Fees = y; // setting the fees



		pOut->ClearStatusBar();
		newCard = true;
	}
}


bool CardEleven::StationIsBought()
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


void CardEleven::BuyTheCard(Grid* pGrid, Player* pPlayer)
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

void CardEleven::FineStation(Grid* pGrid, Player* pPlayer)
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
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	BuyTheCard(pGrid, pPlayer);

	FineStation(pGrid, pPlayer);
}


void CardEleven::Save(ofstream& OutFile)
{
	if (Price < 0)Price = 0;
	if (Fees < 0)Fees = 0;
	OutFile << cardNumber << "    " << position.GetCellNum() << "    " << Price << " " << Fees << endl;

}

void  CardEleven::Load(ifstream& InFile)
{
	InFile >> Price >> Fees;

}

Card* CardEleven::GetMyCopy(const CellPosition& pos)
{
	return new CardEleven(pos);
}