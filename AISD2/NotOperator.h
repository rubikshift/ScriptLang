#pragma once
#include "Operator.h"

class NotOperator : public Operator
{
public:
	NotOperator(Token* Right);
	virtual int* Value();
};