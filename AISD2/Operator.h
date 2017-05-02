#pragma once
#include "Token.h"
class Operator : public Token
{
public:
	Operator();
	Operator(Token* Right, int* Limit);
	virtual ~Operator();
	virtual int* Value() = 0;
protected:
	Token* Right;
};