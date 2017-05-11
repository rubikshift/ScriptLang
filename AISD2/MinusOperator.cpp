#include "MinusOperator.h"

MinusOperator::MinusOperator(Token * Right, int* Limit) : Operator(Right, Limit)
{
}

MinusOperator::~MinusOperator()
{
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

int * MinusOperator::Value()
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
		return nullptr;
	int* R = new int((-1) * (*rVal));
	delete rVal;
	return R;
}
