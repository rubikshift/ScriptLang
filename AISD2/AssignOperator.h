#pragma once
#include "BinaryOperator.h"
#include "Dictionary.h"
class AssignOperator : public Operator
{
public:
	AssignOperator(const char* VariableName, Token* Right, Dictionary* Memory, int* Limit);
	virtual ~AssignOperator();
	virtual int* Value() override;
private:
	int* value;
	char* VariableName;
	Dictionary* Memory;
};