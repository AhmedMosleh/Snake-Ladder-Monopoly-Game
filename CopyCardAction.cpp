#include"Grid.h"
#include "Output.h"
#include"CopyCardAction.h"
#include "ApplicationManager.h"
#include "Cell.h"
#include"Card.h"

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp)

{
}
void CopyAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->PrintMessage(" Click on its source Cell ...");
	CopiedPos = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();

	Copied = dynamic_cast<Card*>(pGrid->GetCellFromPos(CopiedPos)->GetGameObject());// we also can use pGride->HasCard(v,h)

	if (Copied != NULL)
	{

		pGrid->SetClipboard(Copied);



	}
	else
		pGrid->PrintErrorMessage("error");// this order is only to indicate




}


CopyAction::~CopyAction() {}

