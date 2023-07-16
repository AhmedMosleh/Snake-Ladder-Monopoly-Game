#pragma once

#include "Card.h"

class CardEleven : public Card
{
	bool newCard;
public:
	static bool ongrid;
	static Player* Owner;
	static int Price;
	static int Fees;
	static bool isCardOwned;
	static bool IsSaved;


	CardEleven(const CellPosition& pos);
	CardEleven();
	virtual void ReadCardParameters(Grid* pGrid);
	bool StationIsBought();
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void BuyTheCard(Grid* pGrid, Player* pPlayer);
	void FineStation(Grid* pGrid, Player* pPlayer);
	void setongridfalse();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	static void SetOwner(Player* Ptr);
	static Player* GetOwner();
	virtual Card* GetMyCopy(const CellPosition&);

	virtual ~CardEleven();
};