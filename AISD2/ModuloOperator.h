#pragma once
#include "BinaryOperator.h"

class ModuloOperator : public BinaryOperator
{
public:
	ModuloOperator(Token* Left, Token* Right, int* Limit);
	virtual int* Value() override;
};