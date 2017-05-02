#pragma once
#include "Operator.h"

class DecrementOperator : public Operator
{
public:
	DecrementOperator(Token* Right);
	virtual int* Value();
};