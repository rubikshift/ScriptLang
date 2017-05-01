#include "ModuloOperator.h"

ModuloOperator::ModuloOperator(Token* Left, Token* Right) : BinaryOperator(Left, Right)
{	
}

int* ModuloOperator::Value()
{
	int* rVal = Right->Value();
	int* lVal = Left->Value();
	if (rVal == nullptr || lVal == nullptr)
		return nullptr;
	else return new int(*lVal % *rVal);
}