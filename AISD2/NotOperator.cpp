#include "NotOperator.h"
NotOperator::NotOperator(Token* Right) : Operator(Right)
{
}

int * NotOperator::Value()
{	
	int* rVal = Right->Value();
	if (rVal == nullptr)
		return new int(0);
	else
		return nullptr;
}
