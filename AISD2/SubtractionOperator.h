#pragma once
#include "BinaryOperator.h"

class SubtractionOperator : public BinaryOperator
{
public:
	SubtractionOperator(Token* Left, Token* Right);
	virtual int* Value() override;
};