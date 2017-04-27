#include "AssignOperator.h"


AssignOperator::AssignOperator(const char* VariableName, Token* Right, Dictionary* Memory)
{
	value = Memory->Insert(VariableName, Right->Value());
}

int * AssignOperator::Value()
{
	return value;
}
