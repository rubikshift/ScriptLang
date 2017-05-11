#pragma once
#include "BinaryOperator.h"

class LessOperator : public BinaryOperator
{
public:
	LessOperator(Token* Left, Token* Right, int* Limit);
	virtual ~LessOperator();
	virtual int* Value();
};