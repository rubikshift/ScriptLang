#include <cstring>
#include <cstdlib>
#include "Token.h"
#include "Operator.h"
#include "BinaryOperator.h"
#include "AdditionOperator.h"
#include "AndOperator.h"
#include "AssignOperator.h"
#include "DecrementOperator.h"
#include "DivisionOperator.h"
#include "EqualOperator.h"
#include "GraterOperator.h"
#include "GraterOrEqualOperator.h"
#include "LessOperator.h"
#include "LessOrEqualOperator.h"
#include "ModuloOperator.h"
#include "MultiplicationOperator.h"
#include "NotEqualOperator.h"
#include "NotOperator.h"
#include "OrOperator.h"
#include "SubtractionOperator.h"
Token::Token() : value(nullptr), IsConstant(false)
{
}

Token::Token(int * Variable) : value(Variable), IsConstant(false)
{
}

Token::Token(int Value) : IsConstant(true)
{
	value = new int(Value);
}

Token::~Token()
{
	if (value != nullptr && IsConstant)
	{
		delete value;
		value = nullptr;
	}
}

int* Token::Value()
{
	return value;
}

