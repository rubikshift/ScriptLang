#pragma once
#include "BinaryOperator.h"

class MultiplicationOperator : public BinaryOperator
{
public:
	MultiplicationOperator(Token* Left, Token* Right, int* Limit);
	virtual ~MultiplicationOperator();
	virtual int* Value() override;
};