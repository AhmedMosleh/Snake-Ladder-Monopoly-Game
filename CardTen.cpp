#include "CardTen.h"

bool CardTen::ongrid = false; // setting ongird intially as false
Player * CardTen::Owner = NULL;
int CardTen::Price = 0;
int CardTen::Fees = 0;
bool CardTen::isCardOwned = false;
bool CardTen::isSaved = false;
bool CardTen::isLoaded = false;

CardTen::CardTen(const CellPosition& pos) : Card(pos), newCard(true)
{
	cardNumber = 10;
}

CardTen::CardTen()
{
	cardNumber = 10;
}


void CardTen::setIsSaved(bool b)
{
	isSaved = b;
}



CardTen::~CardTen(void)
{
}

void CardTen::SetOwner(Player* Ptr)
{
	Owner = Ptr;
}

Player* CardTen::GetOwner()
{
	return Owner;
}

void CardTen::ReadCardParameters(Grid* pGrid)
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


bool CardTen::StationIsBought()
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


void CardTen::BuyTheCard(Grid* pGrid, Player* pPlayer)
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

void CardTen::FineStation(Grid* pGrid, Player* pPlayer)
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
void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	BuyTheCard(pGrid, pPlayer);

	FineStation(pGrid, pPlayer);
}

void CardTen::Save(ofstream& OutFile)
{
	this->Card::Save(OutFile);

	if (!isSaved)
	{
		OutFile << "      " << this->Fees << "      " << this->Price;
		isSaved = 1;
	}
	OutFile << endl;
}


void  CardTen::Load(ifstream& InFile, Grid* pGrid)
{
	this->Card::Load(InFile, pGrid);

	if (!isLoaded)
	{
		InFile >> this->Fees >> this->Price;
		ongrid = true;
		isLoaded = 1;
	}
}

void CardTen::setongridfalse()
{
	ongrid = false;
}

Card* CardTen::GetMyCopy(const CellPosition& pos)
{
	return new CardTen(pos);
}


