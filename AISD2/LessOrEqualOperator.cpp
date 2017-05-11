#include "LessOrEqualOperator.h"

LessOrEqualOperator::LessOrEqualOperator(Token * Left, Token * Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}

LessOrEqualOperator::~LessOrEqualOperator()
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

int * LessOrEqualOperator::Value()
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
		if (*lVal <= *rVal)
		{
			delete rVal;
			delete lVal;
			return new int(0);
		}
		else
		{
			delete rVal;
			delete lVal;
			return nullptr;
		}
	}
}
