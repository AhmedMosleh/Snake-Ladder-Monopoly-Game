#include "AddCardAction.h"

#include "Input.h"
#include "Output.h"

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


AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}
void AddCardAction::setPositionOfCardNum(int number, CellPosition position) {
	cardNumber = number;
	cardPosition = position;

}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Type card number :");
	int check;
	check = pIn->GetInteger(pOut);
	if (check > 0 && check < 15) //Checks if the card number between (1 & 14)
		cardNumber = check;
	else
	{
		pOut->PrintMessage("Invalid card number");
		cardNumber = 0;
		return;
	}
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("click on the card cell");
	cardPosition = pIn->GetCellClicked();

	if (cardNumber > 12 || cardNumber < 1) {
		pGrid->PrintErrorMessage("Error: Invalid card number ! Click to continue ...");
		return;
	}


	// 4- Make the needed validations on the read parameters
	if (!cardPosition.IsValidCell()) {
		pGrid->PrintErrorMessage("Please click on a valid cell!");
		return;
	}
	if (cardPosition.GetCellNum() == 1 || cardPosition.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("You cannot set any cards in first or last cells");
		cardNumber = 0;
		return;
	}
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	if (cardPosition.IsValidCell())
	{
		switch (cardNumber)
		{
		case 1:
			pCard = new CardOne(cardPosition);
			break;
		case 2:
			pCard = new CardTwo(cardPosition);
			break;
		case 3:
			pCard = new CardThree(cardPosition);
			break;
		case 4:
			pCard = new CardFour(cardPosition);
			break;
		case 5:
			pCard = new CardFive(cardPosition);
			break;
		case 6:
			pCard = new CardSix(cardPosition);
			break;
		case 7:
			pCard = new CardSeven(cardPosition);
			break;
		case 8:
			pCard = new CardEight(cardPosition);
			break;
		case 9:
			pCard = new CardNine(cardPosition);
			break;
		case 10:
			pCard = new CardTen(cardPosition);
			break;
		//case 11:
		//	pCard = new CardEleven(cardPosition);
		//	break;
		//case 12:
		//	pCard = new CardJTwelve(cardPosition);
		//	break;

		// A- Add the remaining cases

		}
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool val = pGrid->AddObjectToCell(pCard);
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!val)
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction
		else
		{
			pCard->Draw(pGrid->GetOutput());
			string s = "Card " + to_string(cardNumber) + " established successfully in cell " + to_string(cardPosition.GetCellNum()) + ". Click to continue";
			pGrid->GetOutput()->PrintMessage(s);
			int x, y;
			pGrid->GetInput()->GetPointClicked(x, y);
			pGrid->GetOutput()->ClearStatusBar();
		}
	}

}