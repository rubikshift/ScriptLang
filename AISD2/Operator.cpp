#include "Operator.h"
Operator::Operator() : Right(nullptr), Token()
{
}

Operator::Operator(Token* Right, int* Limit)
{
	this->Right = Right;
	this->Limit = Limit;
}

Operator::~Operator()
{
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

