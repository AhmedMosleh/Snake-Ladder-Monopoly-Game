#pragma once
#include "Action.h"
class SaveGridAction : public Action
{
	Grid* pGrid;
	string strfile;
public:

	SaveGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();

	~SaveGridAction(void);
};

