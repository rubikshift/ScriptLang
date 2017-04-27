#include "Operator.h"
Operator::Operator() : Right(nullptr), Token()
{
}

Operator::~Operator()
{
	if (value != nullptr && IsConstant)
	{
		delete value;
		value = nullptr;
	}
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

