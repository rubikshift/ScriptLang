#pragma once
#include "Code.h"

class BlockOfCode : public Code
{
public:
	BlockOfCode(Code* Left, Code* Right);
	~BlockOfCode();
	virtual void Execute();
private:
	Code* Left;
	Code* Right;
};