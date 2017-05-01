#include "Operator.h"
Operator::Operator() : Right(nullptr), Token()
{
}

Operator::Operator(Token* Right)
{
	this->Right = Right;
}

Operator::~Operator()
{
	if (value != nullptr)
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

