#pragma once

#include "Card.h"

class CardNine : public Card
{
	bool newCard;
	CellPosition celltogo;
public:
	static Player* Owner;
	static int Price;
	static int Fees;
	static bool isCardOwned;
	static bool IsSaved;


	CardNine(const CellPosition& pos);
	CardNine();
	virtual void ReadCardParameters(Grid* pGrid);
	bool StationIsBought();
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void BuyTheCard(Grid* pGrid, Player* pPlayer);
	void FineStation(Grid* pGrid, Player* pPlayer);

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

	virtual Card* GetMyCopy(const CellPosition&);

	Player* GetOwner();

	void SetOwner(Player* Ptr);



	virtual ~CardNine();
};