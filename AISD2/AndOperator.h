#pragma once
#include "BinaryOperator.h"

class AndOperator : public BinaryOperator
{
public:
	AndOperator(Token* Left, Token* Right, int* Limit);
	virtual ~AndOperator();
	virtual int* Value();
};