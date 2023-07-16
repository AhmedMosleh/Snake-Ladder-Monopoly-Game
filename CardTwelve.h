#pragma once
#include "card.h"
class CardTwelve : public Card
{
	Player* CrdPlayer;
	int plwallet, CrdPrice, CrdFee;

public:

	CardTwelve(const CellPosition& pos);
	CardTwelve();
	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile);	// Loads and Reads the GameObject parameters from the file


	//void SetCardNumber(int cnum);   // The setter of card number
	//int GetCardNumber();            // The getter of card number

	~CardTwelve(void);
};
