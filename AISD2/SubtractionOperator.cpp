#include "SubtractionOperator.h"

SubtractionOperator::SubtractionOperator(Token * Left, Token * Right) : BinaryOperator(Left, Right)
{
}

int * SubtractionOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal - *rVal);
}
