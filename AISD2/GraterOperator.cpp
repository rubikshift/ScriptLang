#include "GraterOperator.h"
GraterOperator::GraterOperator(Token* Left, Token* Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}
GraterOperator::~GraterOperator()
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
int* GraterOperator::Value()
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
	if (rVal == nullptr || lVal == nullptr)
	{
		if (rVal != nullptr)
			delete rVal;
		if (lVal != nullptr)
			delete lVal;
		return nullptr;
	}
	else
	{
		if (*lVal > *rVal)
		{
			delete lVal;
			delete rVal;
			return new int(0);
		}
		else
		{
			delete lVal;
			delete rVal;
			return nullptr;
		}
	}
}