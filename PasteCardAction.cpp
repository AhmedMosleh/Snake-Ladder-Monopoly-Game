#include "PasteCardAction.h"

#include "Input.h"
#include "Output.h"
#include"AddCardAction.h"

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

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
}

PasteCardAction::~PasteCardAction()
{
}
void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Click On The Destination Cell");
	cardPosition = pIn->GetCellClicked();
	pOut->ClearStatusBar();

}

void PasteCardAction::Execute() {
	ReadActionParameters();
	Grid* pGrid;
	if (pManager->GetGrid()->GetClipboard() != NULL) {
		int number = pManager->GetGrid()->GetClipboard()->GetCardNumber();
		AddCardAction* pAddCard;
		pAddCard = new AddCardAction(pManager);
		//	pAddCard->setPositionOfCardNum(number, cardPosition);////<----------------------
		pAddCard->Execute();
	}

	else
		pManager->GetGrid()->PrintErrorMessage("No Cards In Clipboard! click to continue...");



} // Executes action (code depends on action type so virtual)
