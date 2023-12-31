#include "CutCardAction.h"
#include "Output.h"
#include "Input.h"
#include"Grid.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"



CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp)
{
}
// Initializes the pManager pointer of Action with the passed pointer

CutCardAction::~CutCardAction()
{
}
void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("select the card you want to cut ");
	cardpos = pIn->GetCellClicked();
	if (cardpos.HCell() == -1)
	{
		pGrid->PrintErrorMessage("Please enter a valid cell. Click to continue");
		cardpos = pIn->GetCellClicked();
	}
}
void CutCardAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	pCard = pGrid->GetCurrentCard(cardpos);
	if (pCard == NULL)
	{
		pOut->PrintMessage("no card here ");
		return;
	}
	//pGrid->SetClipboard(pCard->GetMyCopy(cardpos));
	pGrid->RemoveObjectFromCell(pCard->GetPosition());
	pOut->PrintMessage("cut succesful");

}





