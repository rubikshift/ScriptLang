#pragma once
#include "BinaryOperator.h"

class OrOperator : public BinaryOperator
{
public:
	OrOperator(Token* Left, Token* Right);
	virtual int* Value();
};