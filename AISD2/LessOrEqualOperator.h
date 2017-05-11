#pragma once
#include "BinaryOperator.h"

class LessOrEqualOperator : public BinaryOperator
{
public:
	LessOrEqualOperator(Token* Left, Token* Right, int* Limit);
	virtual ~LessOrEqualOperator();
	virtual int* Value();
};