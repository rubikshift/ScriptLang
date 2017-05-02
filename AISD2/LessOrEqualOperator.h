#pragma once
#include "BinaryOperator.h"

class LessOrEqualOperator : public BinaryOperator
{
public:
	LessOrEqualOperator(Token* Left, Token* Right, int* Limit);
	virtual int* Value();
};