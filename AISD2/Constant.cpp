#include "Constant.h"

Constant::Constant(int Value)
{
	value = new int(Value);
}

Constant::~Constant()
{
	delete value;
}

int * Constant::Value()
{
	return value;
}
