#include "If.h"

If::If(Token * Condition, Code * Block)
{
	this->Condition = Condition;
	this->Block = Block;
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
	if (Condition->Value() != nullptr)
		Block->Execute();
}
