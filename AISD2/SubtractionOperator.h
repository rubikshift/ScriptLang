#pragma once
#include "BinaryOperator.h"

class SubtractionOperator : public BinaryOperator
{
public:
	SubtractionOperator(Token* Left, Token* Right, int* Limit);
	virtual int* Value() override;
};