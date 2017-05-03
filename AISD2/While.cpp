#include "While.h"

While::While(Token * Condition, Code * Block)
{
	this->Condition = Condition;
	this->Block = Block;
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
	while (Condition->Value() != nullptr)
		Block->Execute();
}
