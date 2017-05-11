#include "DivisionOperator.h"

DivisionOperator::DivisionOperator(Token * Left, Token * Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}

DivisionOperator::~DivisionOperator()
{
	if (Left != nullptr)
	{
		delete Left;
		Left = nullptr;
	}
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

int * DivisionOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (*Limit <= 0)
	{
		if (rVal != nullptr)
			delete rVal;
		if (lVal != nullptr)
			delete lVal;
		return nullptr;
	}
	(*Limit)--;
	if (rVal == nullptr || lVal == nullptr || *rVal == 0)
	{
		if (rVal != nullptr)
			delete rVal;
		if (lVal != nullptr)
			delete lVal;
		return nullptr;
	}
	int* R = new int(*lVal / *rVal);
	delete rVal;
	delete lVal;
	return R;
}
