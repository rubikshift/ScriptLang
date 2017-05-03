#include "If.h"

If::If(Token * Condition, Code * Block, int* Limit)
{
	this->Condition = Condition;
	this->Block = Block;
	this->Limit = Limit;
}

If::~If()
{
	if (Condition != nullptr)
		delete Condition;
	if (Block != nullptr)
		delete Block;
}

void If::Execute()
{
	if (*Limit <= 0)
		return;
	(*Limit)--;
	if (Condition->Value() != nullptr)
		Block->Execute();
}
