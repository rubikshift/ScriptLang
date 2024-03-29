#pragma once
#include "Code.h"
class If : public Code
{
public:
	If(Token* Condition, Code* Block, int* Limit);
	virtual ~If();
	virtual void Execute();
private:
	Token* Condition;
	Code* Block;
	int* Limit;
};