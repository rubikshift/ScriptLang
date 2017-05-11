#pragma once
#include "BinaryOperator.h"

class AdditionOperator : public BinaryOperator
{
public:
	AdditionOperator(Token* Left, Token* Right, int* Limit);
	virtual ~AdditionOperator();
	virtual int* Value() override;
};