#pragma once
#include "BinaryOperator.h"

class GraterOrEqualOperator : public BinaryOperator
{
public:
	GraterOrEqualOperator(Token* Left, Token* Right);
	virtual int* Value();
};