#include "AssignOperator.h"

AssignOperator::AssignOperator(Token * Left, Token * Right)
{
	this->Left = Left;
	this->Right = Right;
	int* lVal = Left->Value();
	int* rVal = Right->Value();
	*lVal = *rVal;
	value = new int(*rVal);
	IsConstant = false;
}

int * AssignOperator::Value()
{
	return value;
}
