#include "NewGameAction.h"


#include "Output.h"
#include "Input.h"
#include "Player.h"
#include "Grid.h"

#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	Player* ply;
	CellPosition* CellNum1 = new CellPosition(1);


	for (int i = 0; i < MaxPlayerCount; i++) {
		ply = pGrid->GetCurrentPlayer();
		//ply->Reset();
		pGrid->UpdatePlayerCell(ply, *CellNum1);
	}

	pGrid->SetCurrPlayerNum(0);
	pGrid->SetClipboard(NULL);
	pGrid->SetEndGame(false);




	pOut->PrintMessage("Let's play again");

	delete CellNum1;

}

NewGameAction::~NewGameAction()
{
}
