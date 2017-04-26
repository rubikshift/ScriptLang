#include "Variable.h"

Variable::Variable()
{
	Value = 0;
	Nul = true;
}

Variable::Variable(const int& Value)
{
	this->Value = Value;
	Nul = false;
}

bool Variable::IsNul() const
{
	return Nul;
}

int Variable::GetValue() const
{
	return Value;
}

void Variable::operator=(const int& Value)
{
	this->Value = Value;
	Nul = false;
}
