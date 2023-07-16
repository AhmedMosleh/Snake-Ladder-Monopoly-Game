#include "CardTwo.h"
#include "Ladder.h"

CardTwo::CardTwo(const CellPosition &pos) : Card(pos)
{
	cardNumber = 2;
	newcellposition = pos;
}

CardTwo::CardTwo()
{
	cardNumber = 2;
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{

}


Card* CardTwo::GetMyCopy(const CellPosition& pos)
{
	Card* pCard = new CardTwo(pos);			//construct a new CardTwo in the CellPosition passed to the function 
	((CardTwo*)pCard)->newcellposition = this->newcellposition;		//Equalize datatmembers of the new card 
	return pCard;		//returning the new constructed card 
}

void CardTwo::Save(ofstream& OutFile)
{
	OutFile << cardNumber << "    " << position.GetCellNum() << "    " << endl;
}

void  CardTwo::Load(ifstream& InFile, Grid* pGrid)
{

}
void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	 Ladder *pladder=pGrid->GetNextLadder(newcellposition);
	if (pladder != NULL) 
	{
		
		GameObject* Gptr = (GameObject*)pladder;
		newcellposition = Gptr->GetPosition();
		pGrid->UpdatePlayerCell(pPlayer,newcellposition);
		pladder->Apply(pGrid, pPlayer);

	}
	else {}
}



CardTwo::~CardTwo()
{

}

