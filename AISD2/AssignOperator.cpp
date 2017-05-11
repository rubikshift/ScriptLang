#include <cstring>
#include "AssignOperator.h"


AssignOperator::AssignOperator(Token* Variable, Token* Right, int* Limit) : BinaryOperator(Variable, Right, Limit)
{
}

AssignOperator::~AssignOperator()
{
	if (Left != nullptr)
	{
		delete Left;
		Left = nullptr;
	}
	if (Right != nullptr)
	{
		delete Right;
		Right = nullptr;
	}
}

int * AssignOperator::Value()
{
	int* rVal = Right->Value();
	Left->Insert(rVal);
	if (*Limit <= 0)
	{
		if (rVal != nullptr)
			delete rVal;
		return nullptr;
	}
	(*Limit)--;
	if (rVal == nullptr)
		return nullptr;
	int* R = new int(*rVal);
	delete rVal;
	return R;

}
