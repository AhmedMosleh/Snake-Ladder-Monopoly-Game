#pragma once

#include "Action.h"
#include "CellPosition.h"
class CopyAction :public Action {
	Card* Copied;
	CellPosition CopiedPos;
public:
	CopyAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	~CopyAction();

};
