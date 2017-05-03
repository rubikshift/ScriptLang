#include <cstring>
#include "AssignOperator.h"


AssignOperator::AssignOperator(const char* VariableName, Token* Right, Dictionary* Memory, int* Limit)
{
	this->Right = Right;
	this->Limit = Limit;
	this->VariableName = new char[strlen(VariableName) + 1];
	memcpy(this->VariableName, VariableName, strlen(VariableName)+1);
	this->Memory = Memory;
}

AssignOperator::~AssignOperator()
{
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
	delete[] VariableName;
}

int * AssignOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	value = Memory->Insert(VariableName, Right->Value());
	return value;
}
