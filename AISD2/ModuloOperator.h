#pragma once
#include "BinaryOperator.h"

class ModuloOperator : public BinaryOperator
{
public:
	ModuloOperator(Token* Left, Token* Right, int* Limit);
	virtual ~ModuloOperator();
	virtual int* Value() override;
};