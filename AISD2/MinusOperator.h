#pragma once
#include "Operator.h"

class MinusOperator : public Operator
{
public:
	MinusOperator(Token* Right, int* Limit);
	virtual ~MinusOperator();
	virtual int* Value();
};