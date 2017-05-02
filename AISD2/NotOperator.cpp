#include "NotOperator.h"
NotOperator::NotOperator(Token* Right, int* Limit) : Operator(Right, Limit)
{
}

int * NotOperator::Value()
{	
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	int* rVal = Right->Value();
	if (rVal == nullptr)
		return new int(0);
	else
		return nullptr;
}
