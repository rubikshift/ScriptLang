#pragma once
#include "BinaryOperator.h"

class EqualOperator : public BinaryOperator
{
public:
	EqualOperator(Token* Left, Token* Right, int* Limit);
	virtual ~EqualOperator();
	virtual int* Value() override;
};