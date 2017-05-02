#pragma once
#include "Operator.h"

class BinaryOperator : public Operator
{
public:
	BinaryOperator();
	BinaryOperator(Token* Left, Token* Right, int* Limit);
	virtual ~BinaryOperator();
	virtual int* Value() = 0;
protected:
	Token* Left;
};