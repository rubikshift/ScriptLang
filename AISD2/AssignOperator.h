#pragma once
#include "BinaryOperator.h"

class AssignOperator : public BinaryOperator
{
public:
	AssignOperator(Token* Left, Token* Right);
	virtual int* Value() override;
};