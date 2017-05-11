#pragma once
#include "Operator.h"

class NotOperator : public Operator
{
public:
	NotOperator(Token* Right, int* Limit);
	virtual ~NotOperator();
	virtual int* Value();
};