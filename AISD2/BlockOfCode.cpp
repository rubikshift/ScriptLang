#include "BlockOfCode.h"

BlockOfCode::BlockOfCode(Code * Left, Code * Right)
{
	this->Left = Left;
	this->Right = Right;
}

BlockOfCode::~BlockOfCode()
{
	if (Left != nullptr)
		delete Left;
	if (Right != nullptr)
		delete Right;
}

void BlockOfCode::Execute()
{
	if(Left)
		Left->Execute();
	if(Right)
		Right->Execute();
}
