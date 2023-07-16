#include "CardTwelve.h"

#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"

#include "Player.h"
#include "Grid.h"
#include "Cell.h"
//This card moves the ownership of the most expensive station that the current user owns from the current user
//	to the player that has the least amount of coins in his wallet
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos)
{
	cardNumber = 12;

}

CardTwelve::CardTwelve()
{
	cardNumber = 12;

}


void CardTwelve::ReadCardParameters(Grid* pGrid)
{

}
void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	CardEleven* CrdObj11;
	CardTen* CrdObj10;
	CardNine* CrdObj9;

	//
	int flgplyer;
	Player* srchPlayer;
	int pprce = 0;
	int tmpwallet = 0, playerorder = 0;
	plwallet = 0;
	CrdPlayer = pGrid->GetCurrentPlayer();
	if (!CrdPlayer)  //
	{

	//	if ((CrdPlayer == CrdObj9->GetOwner()) || (CrdPlayer == CrdObj10->GetOwner()) || (CrdPlayer == CrdObj11->GetOwner()))
	//	{

	//		if (CrdPlayer == CrdObj9->GetOwner()) { pprce = CrdObj9->Price; flgplyer = 9; }
	//		if (CrdPlayer == CrdObj10->GetOwner() && (pprce < CrdObj10->Price)) { pprce = CrdObj10->Price; flgplyer = 10; }
	//		if (CrdPlayer == CrdObj11->GetOwner() && (pprce < CrdObj11->Price)) { pprce = CrdObj11->Price; flgplyer = 11; }

	//		switch (flgplyer) {
	//		case 9:
	//			CrdObj9->SetOwner(pGrid->Getpoorestplayer());
	//			break;
	//		case 10:
	//			CrdObj10->SetOwner(pGrid->Getpoorestplayer());
	//			break;
	//		case 11:
	//			CrdObj11->SetOwner(pGrid->Getpoorestplayer());
	//			break;
	//		}
	//	}
	}
}

//}
void CardTwelve::Save(ofstream& OutFile)
{
	OutFile << cardNumber << "    " << position.GetCellNum() << endl;
}

void  CardTwelve::Load(ifstream& InFile)
{
}

CardTwelve::~CardTwelve()
{
}