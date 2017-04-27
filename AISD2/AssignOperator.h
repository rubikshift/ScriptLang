#pragma once
#include "BinaryOperator.h"
#include "Dictionary.h"
class AssignOperator : public Operator
{
public:
	AssignOperator(const char* VariableName, Token* Right, Dictionary* Memory);
	virtual int* Value() override;
};