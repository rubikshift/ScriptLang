#pragma once
#include "Token.h"

class Constant : public Token
{
public:
	Constant(int Value);
	virtual ~Constant();
	virtual int* Value();
private:
	int* value;
};