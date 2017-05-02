#pragma once
#include "BinaryOperator.h"

class AndOperator : public BinaryOperator
{
public:
	AndOperator(Token* Left, Token* Right);
	virtual int* Value();
};