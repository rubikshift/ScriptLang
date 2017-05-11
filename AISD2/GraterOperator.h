#pragma once
#include "BinaryOperator.h"

class GraterOperator : public BinaryOperator
{
public:
	GraterOperator(Token* Left, Token* Right, int* Limit);
	virtual ~GraterOperator();
	virtual int* Value();
};