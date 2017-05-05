#include <cstring>
#include "Variable.h"

Variable::Variable(const char * VariableName, Dictionary * Memory)
{
	this->VariableName = new char[strlen(VariableName) + 1];
	memcpy(this->VariableName, VariableName, strlen(VariableName) + 1);
	this->Memory = Memory;
}

Variable::~Variable()
{
	delete[] VariableName;
}

int * Variable::Value()
{
	return Memory->Search(VariableName);
}

int* Variable::Insert(int * value)
{
	return Memory->Insert(VariableName, value);
}
