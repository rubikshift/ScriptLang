#pragma once
#include "BinaryOperator.h"

class MultiplicationOperator : public BinaryOperator
{
public:
	MultiplicationOperator(Token* Left, Token* Right);
	virtual int* Value() override;
};