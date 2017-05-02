#include "DecrementOperator.h"

DecrementOperator::DecrementOperator(Token * Right) : Operator(Right)
{
}

int * DecrementOperator::Value()
{
	int* rVal = Right->Value();
	(*rVal)--;
	return new int(*rVal);
}
