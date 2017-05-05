#include <cstring>
#include "AssignOperator.h"


AssignOperator::AssignOperator(Token* Variable, Token* Right, int* Limit)
{
	this->Right = Right;
	this->Left = Variable;
	this->Limit = Limit;
	this->Memory = Memory;
}

int * AssignOperator::Value()
{
	if (*Limit <= 0)
	{
		Left->Insert(nullptr);
		return nullptr;
	}
	(*Limit)--;
	value = Left->Insert(Right->Value());
	return value;
}
