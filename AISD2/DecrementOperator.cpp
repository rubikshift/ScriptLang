#include "DecrementOperator.h"

DecrementOperator::DecrementOperator(Token * Right, int* Limit) : Operator(Right, Limit)
{
}

int * DecrementOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	int* rVal = Right->Value();
	(*rVal)--;
	return new int(*rVal);
}
