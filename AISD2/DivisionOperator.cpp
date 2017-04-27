#include "DivisionOperator.h"

DivisionOperator::DivisionOperator(Token * Left, Token * Right)
{
	this->Left = Left;
	this->Right = Right;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (Left->IsConstant && Right->IsConstant)
	{
		IsConstant = true;
		if (rVal == nullptr || lVal == nullptr)
			value = nullptr;
		else
			value = new int(*lVal / *rVal);
	}
	else IsConstant = false;
}

int * DivisionOperator::Value()
{
	if (IsConstant)
		return value;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal / *rVal);
}
