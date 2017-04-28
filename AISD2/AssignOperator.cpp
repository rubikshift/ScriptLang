#include "AssignOperator.h"


AssignOperator::AssignOperator(const char* VariableName, Token* Right, Dictionary* Memory)
{
	this->Right = Right;
	value = Memory->Insert(VariableName, Right->Value());
}

int * AssignOperator::Value()
{
	value = Right->Value();
	return value;
}
