#include "BinaryOperator.h"
BinaryOperator::BinaryOperator() : Left(nullptr), Operator()
{
}
BinaryOperator::BinaryOperator(Token* Left, Token* Right, int* Limit)
{
	this->Left = Left;
	this->Right = Right;
	this->Limit = Limit;
}

BinaryOperator::~BinaryOperator()
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
