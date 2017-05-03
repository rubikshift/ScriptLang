#pragma once
#include "Code.h"
class If : public Code
{
public:
	If(Token* Condition, Code* Block);
	virtual ~If();
	virtual void Execute();
private:
	Token* Condition;
	Code* Block;
};