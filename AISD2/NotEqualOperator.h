#pragma once
#include "BinaryOperator.h"

class NotEqualOperator : public BinaryOperator
{
public:
	NotEqualOperator(Token* Left, Token* Right);
	virtual int* Value();
};