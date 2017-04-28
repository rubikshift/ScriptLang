#include "EqualOperator.h"

EqualOperator::EqualOperator(Token * Left, Token * Right)
{
	this->Right = Right;
	this->Left = Left;
}

int * EqualOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else
	{
		if (*lVal == *rVal)
			return new int(0);
		else
			return nullptr;
	}
}
