#include "DivisionOperator.h"

DivisionOperator::DivisionOperator(Token * Left, Token * Right)
{
	this->Left = Left;
	this->Right = Right;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (Left->IsConstant && Right->IsConstant)
		IsConstant = true;
	else IsConstant = false;
}

int * DivisionOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal / *rVal);
}
