#include "EqualOperator.h"

EqualOperator::EqualOperator(Token * Left, Token * Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}

int * EqualOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
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
