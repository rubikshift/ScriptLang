#include "OrOperator.h"

OrOperator::OrOperator(Token* Left, Token* Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}

int* OrOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr && lVal == nullptr)
		return nullptr;
	else
		return new int(0);
}