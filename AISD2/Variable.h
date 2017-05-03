#pragma once
#include "Token.h"
class Variable : public Token
{
public:
	Variable(const char* VariableName, Dictionary* Memory);
	virtual ~Variable();
	virtual int* Value();
private:
	char* VariableName;
	Dictionary* Memory;
};