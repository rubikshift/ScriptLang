#include "ModuloOperator.h"

ModuloOperator::ModuloOperator(Token* Left, Token* Right, int* Limit) : BinaryOperator(Left, Right, Limit)
{	
}

int* ModuloOperator::Value()
{
	if (*Limit <= 0)
		return nullptr;
	(*Limit)--;
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal % *rVal);
}