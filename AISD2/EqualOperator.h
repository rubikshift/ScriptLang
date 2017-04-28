#pragma once
#include "BinaryOperator.h"

class EqualOperator : public BinaryOperator
{
public:
	EqualOperator(Token* Left, Token* Right);
	virtual int* Value() override;
};