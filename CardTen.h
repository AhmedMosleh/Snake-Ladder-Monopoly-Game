#pragma once

#include "Card.h"

class CardTen : public Card
{
	bool newCard;



public:
	static Player* Owner;
	static bool ongrid;
	static int Price;
	static int Fees;
	static bool isCardOwned;



	static bool  isSaved;      //for saving paramerters only once
	static bool isLoaded;      //for loading paramerters only once




	CardTen(const CellPosition& pos);
	CardTen();
	virtual void ReadCardParameters(Grid* pGrid);
	bool StationIsBought();
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void BuyTheCard(Grid* pGrid, Player* pPlayer);
	void FineStation(Grid* pGrid, Player* pPlayer);
	static void SetOwner(Player* Ptr);
	static Player* GetOwner();

	void setongridfalse();

	virtual void Save(ofstream& OutFile);

	virtual void Load(ifstream& InFile, Grid* pGrid);	// Loads and Reads the GameObject parameters from the file

	virtual Card* GetMyCopy(const CellPosition&);

	void setIsSaved(bool b);



	virtual ~CardTen();
};