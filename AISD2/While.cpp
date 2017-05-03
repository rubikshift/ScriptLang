#include "While.h"

While::While(Token * Condition, Code * Block, int* Limit)
{
	this->Condition = Condition;
	this->Block = Block;
	this->Limit = Limit;
}

While::~While()
{
	if (Condition != nullptr)
		delete Condition;
	if (Block != nullptr)
		delete Block;
}

void While::Execute()
{
	while (CheckLimit() && Condition->Value() != nullptr)
		Block->Execute();
}

bool While::CheckLimit()
{
	if (*Limit <= 0)
		return false;
	(*Limit)--;
	return true;
}
