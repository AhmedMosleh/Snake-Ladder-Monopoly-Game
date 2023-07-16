#include "SaveGridAction.h"
#include "Grid.h"
#include <fstream>
#include <iostream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	pGrid = pApp->GetGrid();
}
void SaveGridAction::ReadActionParameters() {
	if ((UI.InterfaceMode) == MODE_DESIGN)
	{
		(pGrid->GetOutput())->PrintMessage("Are You sure to Save the game design ? Y/N");
		string ansr = (pGrid->GetInput())->GetSrting((pGrid->GetOutput()));

		if ((ansr == "y") || (ansr == "Y"))
		{
			(pGrid->GetOutput())->PrintMessage("Please: Enter the file name to save data");
			strfile = (pGrid->GetInput())->GetSrting((pGrid->GetOutput()));
			strfile += ".txt";
		}
	}
}

void	SaveGridAction::Execute() {
	ReadActionParameters();
	if (strfile != "") {
		ofstream savefile(strfile, ios::out);

		//	savefile.open(strfile);                             // Opens The File With The Entered Name , If It Doesnt Exist Creates it

		//	if (!savefile.is_open())                             // Makes Sure The File is Open To Avoid Unexpected Errors
		//		return;

		savefile << pGrid->GetNumOfLadders() << endl;	     	 // Gets Number Of Ladders In The Grid
		pGrid->SaveInterface(savefile, ObjectType::TLadder);	     	 // Writes it to The File

		savefile << pGrid->GetNumOfSnakes() << endl;		     	 // Gets Number Of Snakes In The Grid
		pGrid->SaveInterface(savefile, ObjectType::TSnake);	     	 // Writes it to The File

		savefile << pGrid->GetNumOfCards() << endl;		     	 // Gets Number Of Cards In The Grid
		pGrid->SaveInterface(savefile, ObjectType::TCard);		     	 // Writes it to The File



		savefile.close();                                        // Closes File (Important For Buffer)
		(pGrid->GetOutput())->PrintMessage("Successful Saving");

	}
}

SaveGridAction::~SaveGridAction(void)
{
}

