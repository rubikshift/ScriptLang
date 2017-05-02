#pragma once
#include "Operator.h"

class DecrementOperator : public Operator
{
public:
	DecrementOperator(Token* Right, int* Limit);
	virtual int* Value();
};