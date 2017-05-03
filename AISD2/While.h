#pragma once
#include "Code.h"

class While : public Code
{
public:
	While(Token* Condition, Code* Block, int* Limit);
	~While();
	virtual void Execute();
private:
	Token* Condition;
	Code* Block;
	int* Limit;
	bool CheckLimit();
};