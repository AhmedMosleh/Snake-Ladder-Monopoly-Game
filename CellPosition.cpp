#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///**TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= 8) {
		vCell = v;
		return true;
	}

	return false; //** this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///**TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= 10) {
		hCell = h;
		return true;
	}

	return false; //** this line sould be changed with your implementation
}

int CellPosition::VCell() const
{

	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///**TODO: Implement this function as described in the .h file
	if (vCell >= 0 && vCell <= 8 && hCell >= 0 && hCell <= 10) {
		return true;

	}


	return false; //** this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///*TODO: Implement this function as described in the .h file
	//int CellNum = -1;
	int h = cellPosition.HCell();
	int v = cellPosition.VCell();
	int cellNum = 0;
	h++;
	v = 9 - v;
	//if ((v >= 1 && v <= 9) && (h >= 1 && h <= 11)) {
	//	cellNum = v * h;
	//}
	//else {
	cellNum = (v * 11) - (11 - h);
	//}

	if (cellNum >= 1 && cellNum <= 99) {
		return cellNum; // this line should be changed with your implementation
	}

	return 0; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	///*TODO: Implement this function as described in the .h file
	int i = 0;
	int vmax = 11;
	int v;
	if (cellNum % 11 != 0) {
		for (i = 1; i < 9; i++) {
			v = cellNum / vmax;
			if (v == 0) {
				break;
			}
			vmax += 11;
		}
		v = i;
	}
	else {
		v = cellNum / 11;
	}

	int hmax = v * 11;
	int h = 11 - (hmax - cellNum);
	h--;
	v = 9 - v;

	position.SetHCell(h);
	position.SetVCell(v);




	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file
	int TheNewPosition;
	CellPosition ThePosition;

	TheNewPosition = this->GetCellNum() + TheNewPosition;
	if (TheNewPosition < 99)
	{
		ThePosition = this->GetCellPositionFromNum(TheNewPosition);
	}
	else
	{
		ThePosition = this->GetCellPositionFromNum(99);
	}
	this->SetVCell(ThePosition.VCell());


	this->SetHCell(ThePosition.HCell());



	// Note: this function updates the data members (vCell and hCell) of the calling object

}