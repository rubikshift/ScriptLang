#include "MinusOperator.h"

MinusOperator::MinusOperator(Token * Right, int* Limit) : Operator(Right, Limit)
{
}

int * MinusOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	int* rVal = Right->Value();
	return new int((-1) * (*rVal));
}
