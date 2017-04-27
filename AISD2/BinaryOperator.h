#pragma once
#include "Operator.h"

class BinaryOperator : public Operator
{
public:
	BinaryOperator();
	virtual int* Value() = 0;
protected:
	Token* Left;
};