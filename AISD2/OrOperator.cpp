#include "OrOperator.h"

OrOperator::OrOperator(Token* Left, Token* Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{
}

OrOperator::~OrOperator()
{
	if (Left != nullptr)
	{
		delete Left;
		Left = nullptr;
	}
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

int* OrOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (*Limit <= 0)
	{
		if (rVal != nullptr)
			delete rVal;
		if (lVal != nullptr)
			delete lVal;
		return nullptr;
	}
	(*Limit)--;
	if (rVal == nullptr && lVal == nullptr)
		return nullptr;
	else
	{
		if (rVal != nullptr)
			delete rVal;
		if (lVal != nullptr)
			delete lVal;
		return new int(0);
	}
}