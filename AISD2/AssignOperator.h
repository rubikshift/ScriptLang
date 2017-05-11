#pragma once
#include "BinaryOperator.h"
#include "Dictionary.h"
class AssignOperator : public BinaryOperator
{
public:
	AssignOperator(Token* Variable, Token* Right, int* Limit);
	virtual ~AssignOperator();
	virtual int* Value() override;
};