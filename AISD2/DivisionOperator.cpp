#include "DivisionOperator.h"

DivisionOperator::DivisionOperator(Token * Left, Token * Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}

int * DivisionOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr || *rVal == 0)
		return nullptr;
	else return new int(*lVal / *rVal);
}
