#include "GraterOperator.h"
GraterOperator::GraterOperator(Token* Left, Token* Right) : BinaryOperator(Left, Right)
{
}
int* GraterOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else
	{
		if (*lVal > *rVal)
			return new int(0);
		else
			return nullptr;
	}
}