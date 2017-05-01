#include "MultiplicationOperator.h"
MultiplicationOperator::MultiplicationOperator(Token* Left, Token* Right) : BinaryOperator(Left, Right)
{
}
int * MultiplicationOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal * *rVal);
}
