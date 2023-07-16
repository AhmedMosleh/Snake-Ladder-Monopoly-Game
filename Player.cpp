#include "Player.h"

#include "CellPosition.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(1), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	this->prevent=0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
	// make stepcount same as cell position.
	stepCount = pCell->GetCellPosition().GetCellNum();
}



Cell* Player::GetCell() const
{
	return pCell;
}



void Player::SetWallet(int wallet)
{
	if (wallet >= 0) {
		this->wallet = wallet;
		// Make any needed validations
	}

}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::SetTurnCount()
{
	if (turnCount == 3) {
		turnCount = 0;
		return;
	}
	else {
		turnCount++;
	}
}

int Player::GetPlayerNum() const
{
	return playerNum;
}

int Player::GetStepCount() const
{
	return stepCount;
}

void Player::SetjustRollDice(int num)
{
	if (num >= 0 && num <= 6) 
	{
		justRolledDiceNum = num;

	}
}

int Player::GetjustRolledDiceNum()
{
	return justRolledDiceNum;
}
void Player::setpreventP(int i)
{
	if (i == 0 || i == 1)
		prevent = i;
	else
		prevent = 0;
}

int Player::getpreventP() 
{
	return prevent;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///-TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	
	
	///-TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	string messg1;
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	turnCount++;
	// == Here are some guideline steps (numbered below) to implement this function ==

	if (this->getpreventP()==1)
	{
		pOut->PrintMessage("You're prevented from rolling the dice this turn...Click to continue");
		this->setpreventP(0);
		return;
	
	}

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 3) {
		wallet += diceNumber * 10;
		turnCount = 0;
		pGrid->PrintErrorMessage("Player #" + to_string(playerNum) + "gets" + to_string(10 * diceNumber) + "coins");
		return;
	}

	// a player can't move with money less than 1
	if (wallet < 1) {
		pOut->PrintMessage("Player #" + to_string(playerNum) + "doesn't have enough coins to move");
		turnCount++;
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition* pos;

	messg1 = "Player: " + to_string(playerNum) + " has rolled: ";

	if ((diceNumber + pCell->GetCellPosition().GetCellNum()) < 98) {
		pos = new CellPosition(justRolledDiceNum + stepCount);
		messg1 += to_string(diceNumber);
	}
	else {
		pos = new CellPosition(99);
		messg1 += to_string(99 - stepCount);
	}

	pGrid->PrintErrorMessage(messg1);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, *pos);
	
	// house cleaning :)
	delete pos;
	pos = NULL;
	// 6- Apply() the game object of the reached cell (if any)
	if (pCell->GetGameObject()) {
		pCell->GetGameObject()->Apply(pGrid, this);
	}
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (pCell->GetCellPosition().GetCellNum() == 99) {
		pGrid->SetEndGame(true);
		pGrid->PrintErrorMessage("Player: " + to_string(playerNum) + "has won */*/*/*/*");
	}
}


void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}

void Player::PlayerInitialCondition() 
{
	wallet = 100;
	turnCount = 0;
	prevent = 0;
}


