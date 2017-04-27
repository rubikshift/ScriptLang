#pragma once
#include "BinaryOperator.h"

class AdditionOperator : public BinaryOperator
{
public:
	AdditionOperator(Token* Left, Token* Right);
	virtual int* Value() override;
};