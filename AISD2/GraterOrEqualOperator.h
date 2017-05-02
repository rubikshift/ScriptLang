#pragma once
#include "BinaryOperator.h"

class GraterOrEqualOperator : public BinaryOperator
{
public:
	GraterOrEqualOperator(Token* Left, Token* Right, int* Limit);
	virtual int* Value();
};