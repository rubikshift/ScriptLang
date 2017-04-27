#include "BinaryOperator.h"
BinaryOperator::BinaryOperator() : Left(nullptr), Operator()
{
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
