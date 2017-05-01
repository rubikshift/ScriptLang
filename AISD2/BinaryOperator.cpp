#include "BinaryOperator.h"
BinaryOperator::BinaryOperator() : Left(nullptr), Operator()
{
}
BinaryOperator::BinaryOperator(Token* Left, Token* Right)
{
	this->Left = Left;
	this->Right = Right;
}

BinaryOperator::~BinaryOperator()
{
	if (value != nullptr)
	{
		delete value;
		value = nullptr;
	}
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
