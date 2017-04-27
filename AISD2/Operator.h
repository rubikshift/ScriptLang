#pragma once
#include "Token.h"
class Operator : public Token
{
public:
	Operator();
	virtual ~Operator();
	virtual int* Value() = 0;
protected:
	Token* Right;
};