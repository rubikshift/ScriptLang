#include "DivisionOperator.h"

DivisionOperator::DivisionOperator(Token * Left, Token * Right) : BinaryOperator(Left, Right)
{
}

int * DivisionOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal / *rVal);
}
