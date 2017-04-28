#include "AdditionOperator.h"

AdditionOperator::AdditionOperator(Token * Left, Token * Right) 
{
	this->Left = Left;
	this->Right = Right;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (Left->IsConstant && Right->IsConstant)
		IsConstant = true;
}

int * AdditionOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal + *rVal);
}
