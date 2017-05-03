#pragma once
#include "Token.h"
class Code
{
public:
	Code();
	Code(Token* LineOfCode);
	virtual ~Code();
	virtual void Execute();
private:
	Token* LineOfCode;
};