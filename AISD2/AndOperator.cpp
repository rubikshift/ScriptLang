#include "AndOperator.h"

AndOperator::AndOperator(Token * Left, Token * Right) : BinaryOperator(Left, Right)
{
}

int * AndOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else
		return new int(0);
}
