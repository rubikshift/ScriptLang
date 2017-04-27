#pragma once
#include "BinaryOperator.h"

class DivisionOperator : public BinaryOperator
{
public:
	DivisionOperator(Token* Left, Token* Right);
	virtual int* Value();
};