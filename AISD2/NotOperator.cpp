#include "NotOperator.h"
NotOperator::NotOperator(Token* Right, int* Limit) : Operator(Right, Limit)
{
}

NotOperator::~NotOperator()
{
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

int * NotOperator::Value()
{
	int* rVal = Right->Value();
	if (*Limit <= 0)
	{
		if (rVal != nullptr)
			delete rVal;
		return nullptr;
	}
	(*Limit)--;
	if (rVal == nullptr)
		return new int(0);
	else
	{
		delete rVal;
		return nullptr;
	}
}
